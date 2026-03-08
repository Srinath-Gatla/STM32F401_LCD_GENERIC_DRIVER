#include "STM32F401_LCD.h"
int IsPrime(int num)
{
	if(num < 2)
	{
		return 0;
	}
	for(uint32_t i=2;i<=(num/2);i++)
	{
		if((num % i)==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
    LCD_Handle_t LCD;

    // Configure data pins (PA0-PA7)
    for(uint32_t i = 0; i < 8; i++)
    {
        LCD.data[i].pGPIOx = GPIOA;
        LCD.data[i].GPIO_config.GPIO_PinNumber = i;
        LCD.data[i].GPIO_config.GPIO_PinMode = GPIO_MODE_OUT;
        LCD.data[i].GPIO_config.GPIO_PinSpeed = GPIO_SPEED_HIGH;  // Add this
        LCD.data[i].GPIO_config.GPIO_Pinpupdcontrol = GPIO_NO_PUPD; // Add this
        LCD.data[i].GPIO_config.GPIO_PinOptype = GPIO_OP_TYPE_PP; // Add this
    }

    // Configure control pins (PB0-PB2)
    LCD.EN.pGPIOx = GPIOB;
    LCD.EN.GPIO_config.GPIO_PinNumber = GPIO_PIN_0;
    LCD.EN.GPIO_config.GPIO_PinMode = GPIO_MODE_OUT;
    LCD.EN.GPIO_config.GPIO_PinSpeed = GPIO_SPEED_HIGH;
    LCD.EN.GPIO_config.GPIO_Pinpupdcontrol = GPIO_NO_PUPD;
    LCD.EN.GPIO_config.GPIO_PinOptype = GPIO_OP_TYPE_PP;

    LCD.RS.pGPIOx = GPIOB;
    LCD.RS.GPIO_config.GPIO_PinNumber = GPIO_PIN_1;
    LCD.RS.GPIO_config.GPIO_PinMode = GPIO_MODE_OUT;
    LCD.RS.GPIO_config.GPIO_PinSpeed = GPIO_SPEED_HIGH;
    LCD.RS.GPIO_config.GPIO_Pinpupdcontrol = GPIO_NO_PUPD;
    LCD.RS.GPIO_config.GPIO_PinOptype = GPIO_OP_TYPE_PP;

    LCD.RW.pGPIOx = GPIOB;
    LCD.RW.GPIO_config.GPIO_PinNumber = GPIO_PIN_2;
    LCD.RW.GPIO_config.GPIO_PinMode = GPIO_MODE_OUT;
    LCD.RW.GPIO_config.GPIO_PinSpeed = GPIO_SPEED_HIGH;
    LCD.RW.GPIO_config.GPIO_Pinpupdcontrol = GPIO_NO_PUPD;
    LCD.RW.GPIO_config.GPIO_PinOptype = GPIO_OP_TYPE_PP;

    // Initialize the LCD
    InitLCD(&LCD);
    // Display numbers
    for(uint32_t j = 0; j < 100; j++)
    {
    	if(IsPrime(j))
    	{
    		CmdLCD(&LCD, CLEAR_LCD);
    		StrLCD(&LCD, "Number: ");

        	NumLCD(&LCD, j);
        	delay(); // Increase this delay if needed
    	}
    }

    while(1);
}
