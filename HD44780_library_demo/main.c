#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include "../HD44780/HD44780_LCD.h"

int main(void)
{
	char display_on[] = "Display on";
	char cursor_visible[] = "Cursor visible";
	char cursor_blinking[] = "Cursor blinking";
	char greetings[] = "Hello world!";
	PinConfig config = {.ddr = &DDRD, .port = &PORTD, .d0 = 32, .d1 = 16, .d2 = 128, .d3 = 64, .rs = 4, .en = 8};
	
    LCD_init(&config);
	//display is off by default
	LCD_on();
	LCD_home();
	
	LCD_clear();
	LCD_write_string(&display_on[0]);
	_delay_ms(3000);
	
	LCD_clear();
	LCD_cursor_noblink();
	LCD_show_cursor();
	LCD_write_string(&cursor_visible[0]);
	_delay_ms(3000);
	
	LCD_clear();
	LCD_cursor_blink();
	LCD_write_string(&cursor_blinking[0]);
	_delay_ms(3000);
	
	
	//demo app
	LCD_hide_cursor();
	LCD_cursor_noblink();
	LCD_home();
	
	uint8_t collumn = 0, row = 0;
	
	while(1)
	{
		LCD_clear();
		
		for (int i = 0; i < 12; i++)
		{
			LCD_set_cursor((collumn + i) > 15? !row : row, (collumn + i) % 16);
			LCD_write_char(greetings[i]);
		}
		
		collumn++;
		collumn %= 16;
		
		if (!collumn) row++;
		row %= 2;
		
		_delay_ms(1000);
	}
}