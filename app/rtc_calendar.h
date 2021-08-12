/* Copyright (c) 2014 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *2021-8-09 10:24:01
 */

#ifndef __RTC_CALENDAR_H__
#define __RTC_CALENDAR_H__

#include <stdint.h>
#include <stdbool.h>
#include "time.h"

typedef struct{
	unsigned char second;
	unsigned char minute;
	unsigned char hour;
	unsigned char date;
	unsigned char month;
	uint16_t year;
}data_t;

#define UART_LOG      1   //修改为1,激活串口输出,0 2021-8-9 22:59:28

#define UPDATA_SEC    1   //更新秒
#define UPDATA_HM     2   //更新时、分
#define UPDATA_DATE   3   //更新年、月、日

// Change the following defines to change the RTC timer used or the interrupt priority
#define CAL_RTC                 NRF_RTC1
#define CAL_RTC_IRQn            RTC1_IRQn
#define CAL_RTC_IRQHandler      RTC1_IRQHandler
#define CAL_RTC_IRQ_Priority    3

extern uint8_t TimeUpdataFlag;
void nrf_cal_init(void);
char *nrf_cal_get_time_string(void);
void nrf_cal_set_time(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minute, uint32_t second);
void CAL_update(void);

#endif
