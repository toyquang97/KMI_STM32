#include "../Inc/lcd.h"
void LCD_sendCmd( uint8_t data)
{
    HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET);
    LCD_sendByte(data);
}

void LCD_sendChar(uint8_t data)
{
    HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);
    LCD_sendByte(data);
}

void LCD_sendNibble(uint8_t data)
{
    HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, (data & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (data & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (data & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (data & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_RESET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_SET);
}

void LCD_sendByte(uint8_t data)
{
    LCD_sendNibble(data >> 4); // High order bit
    LCD_sendNibble(data); // Low order bit
}

void LCD_puts(char *data)
{
    while (data[0] != '\0')
    {
        LCD_sendChar(data[0]);
        data++;
    }
}

void LCD_init(void)
{
    HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_SET);
    initBriConLCD();
    LCD_sendCmd(0x33); // Initialize controller
    LCD_sendCmd(0x32); // Set 4-bit mode
    LCD_sendCmd(0x28); // 4 bit, 2 line, 5x7
    LCD_sendCmd(0x06); // Cursor direction -> right
    LCD_sendCmd(0x0C); // Display on, cursor off
    LCD_sendCmd(0x01); // Clear display
}

void LCD_clear(void)
{
    LCD_sendCmd(0x01);
    HAL_Delay(2);
}

void LCD_setCursor(uint8_t row, uint8_t col)
{
	uint8_t row_offsets[] = {0x00, 0x40, 0x14, 0x54};
	LCD_sendCmd(LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

void LCD_scroll(uint8_t isScroll)
{
	if(isScroll)
	{
		LCD_sendCmd(LCD_ENTRYMODESET | LCD_ENTRYSHIFTINCREMENT);
	}
}

void controlContrastLCD(uint8_t percent)
{
    if(percent > 100) percent = 100;
    if (percent < 75)  percent = 75; // minimun contrast
    __HAL_TIM_SetCompare(&htim17,TIM_CHANNEL_1,percent);
}

// Brightness control by transistor pull low, so pwm should invert
void controlBrightLCD(uint8_t percent)
{
    uint8_t temp = 0;
    if(percent > 100) percent = 100;
    temp = 100 - percent;
    __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,temp);
}

void initBriConLCD(void)
{
    HAL_TIM_PWM_Start(&CONTRAST_PWM,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&BRIGHTNESS_PWM,TIM_CHANNEL_2);
    __HAL_TIM_SetCompare(&CONTRAST_PWM,TIM_CHANNEL_1,95);
    __HAL_TIM_SetCompare(&BRIGHTNESS_PWM,TIM_CHANNEL_2,60);

}
