#include "../Inc/lcd.h"
void LCD_sendCmd( uint8_t data)
{
    HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);
    LCD_sendByte(data);
}

void LCD_sendChar(uint8_t data)
{
    HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET);
    LCD_sendByte(data);
}

void LCD_sendNibble(uint8_t data)
{
    HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, (data & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (data & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (data & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (data & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_RESET);
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
