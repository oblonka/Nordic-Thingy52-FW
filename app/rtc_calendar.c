/* Copyright (c) 2014 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */
 
#include "rtc_calendar.h"
#include "nrf.h"

struct tm t;
uint8_t TimeUpdataFlag;


void nrf_cal_init(void)
{
    //使用外部32.768 kHz 晶体振荡器作为低频时钟源
    NRF_CLOCK->LFCLKSRC = CLOCK_LFCLKSRC_SRC_Xtal << CLOCK_LFCLKSRC_SRC_Pos;
	  //LFCLK启动完成事件清零
    NRF_CLOCK->EVENTS_LFCLKSTARTED = 0;
	  //启动LFCLK
    NRF_CLOCK->TASKS_LFCLKSTART = 1;
	  //等待LFCLK启动完成
    while(NRF_CLOCK->EVENTS_LFCLKSTARTED == 0);
    
	
    //配置RTC每秒产生一次比较匹配事件
    CAL_RTC->PRESCALER = 4095;
    CAL_RTC->EVTENSET = RTC_EVTENSET_COMPARE0_Msk;
    CAL_RTC->INTENSET = RTC_INTENSET_COMPARE0_Msk;
    CAL_RTC->CC[0] = 8;
    CAL_RTC->TASKS_START = 1;
    NVIC_SetPriority(CAL_RTC_IRQn, CAL_RTC_IRQ_Priority);
    NVIC_EnableIRQ(CAL_RTC_IRQn);  
}


void nrf_cal_set_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second)
{

	t.tm_year = year - 1900;//2021-8-9 14:33:53  1900 这个是时间的计算标准,不能改这个时间基准,从蓝牙端进行起始时间的更改
    t.tm_mon = month;
    t.tm_mday = day;
    t.tm_hour = hour;
    t.tm_min = minute;
    t.tm_sec = second;   
    CAL_RTC->TASKS_CLEAR = 1;  
}


char *nrf_cal_get_time_string(void)
{
    static char cal_string[80];
	  strftime(cal_string, 80, "%Y-%m-%d-%H:%M:%S", &t);
    return cal_string;
}


static char not_leap(void)     
{
	if (!(t.tm_year%100))
	{
		return (char)(t.tm_year%400);
	}
	else
	{
		return (char)(t.tm_year%4);
	}
}


void CAL_updata(void)
{
	TimeUpdataFlag = UPDATA_SEC;
	if (++t.tm_sec==60)        //keep track of time, date, month, and year
	{
		TimeUpdataFlag = UPDATA_HM;
		t.tm_sec=0;
		if (++t.tm_min==60)
		{
			t.tm_min=0;
			if (++t.tm_hour==24)
			{
				TimeUpdataFlag = UPDATA_DATE;
				t.tm_hour=0;
				if (++t.tm_mday==32)
				{
					t.tm_mday++;
					t.tm_mday=1;
				}
				else if (t.tm_mday==31)
				{
					if ((t.tm_mon==4) || (t.tm_mon==6) || (t.tm_mon==9) || (t.tm_mon==11))
					{
						t.tm_mon++;
						t.tm_mday=1;
					}
				}
				else if (t.tm_mday==30)
				{
					if(t.tm_mon==2)
					{
						t.tm_mon++;
						t.tm_mday=1;
					}
				}
				else if (t.tm_mday==29)
				{
					if((t.tm_mon==2) && (not_leap()))
					{
						t.tm_mon++;
						t.tm_mday=1;
					}
				}
				if (t.tm_mon==13)
				{
					t.tm_mon=1;
					t.tm_year++;
				}
			}
		}
	}	
}



//2021-8-11 23:45:48

