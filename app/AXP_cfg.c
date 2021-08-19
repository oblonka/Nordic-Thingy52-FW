


#include "axp-cfg.h"
//#include "I2C_driver.h"	//ƽ̨i2C��д����ͷ�ļ� 


/*AXP216 ����������*/

uint8_t AXP216_read( uint8_t readAddr, uint8_t byteNum , uint8_t *readData)
		{
		if(byteNum<=0)
			return 0;
 
			/*�˴�����д�û������I2C������*/
 			//I2C_Read(AXP_DEVICES_ADDR,readData, readAddr, byteNum);//self_def

 	   return byteNum;
       }



/*AXP216 д��������	*/

uint8_t AXP216_write(const uint8_t writeAddr, const uint8_t writeData)
	{
  

			   	  
	    /*�˴�����д�û������I2C д����*/
  		//I2C_Write(AXP_DEVICES_ADDR,writeAddr,writeData); //self_def

	return 1;
	}


void delay_ms(uint16_t nms)
	{	    /*�˴�����д�û������mS ��ʱ����*/

	 //STM32_delay_ms(nms)  ;//self_def

	}



	
void axp_set_bits(int reg, uint8_t bit_mask)
{
	uint8_t reg_val;
    
	AXP216_read( reg,1, &reg_val);

	if ((reg_val & bit_mask) != bit_mask) {
		reg_val |= bit_mask;
		AXP216_write(reg, reg_val)	 ;

   		}

}


   
void  axp_clr_bits(int reg, uint8_t bit_mask)
{
	 uint8_t reg_val;

     AXP216_read( reg,1, &reg_val);

	if (reg_val & bit_mask) {
		reg_val &= ~bit_mask;
		AXP216_write(reg, reg_val)	 ;
    	}

}


		
void  axp_update(int reg, uint8_t val, uint8_t mask)
{

	uint8_t reg_val;

	AXP216_read(reg, 1, &reg_val);


	if ((reg_val & mask) != val) {
		reg_val = (reg_val & ~mask) | val;
    	AXP216_write(reg, reg_val);
	 }
}



