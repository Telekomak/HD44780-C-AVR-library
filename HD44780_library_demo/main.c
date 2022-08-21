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
	
    lcd_init(&config);
	lcd_home();
	
	lcd_clear();
	//display is off by default
	lcd_on();
	lcd_write_string(&display_on[0], 10);
	_delay_us(1000000);
	
	lcd_clear();
	lcd_show_cursor(0);
	lcd_write_string(&cursor_visible[0], 14);
	_delay_us(1000000);
	
	lcd_clear();
	lcd_show_cursor(1);
	lcd_write_string(&cursor_blinking[0], 15);
	_delay_us(5000000);
	
	//demo app
	lcd_hide_cusror();
	
	uint8_t collumn = 0, row = 0;
	
	while(1)
	{
		lcd_clear();
		
		for (int i = 0; i < 12; i++)
		{
			lcd_set_cursor(collumn + i > 15? !row : row, (collumn + i) % 16);
			lcd_write_char(greetings[i]);
		}
		
		collumn++;
		collumn %= 16;
		
		if (!collumn) row++;
		row %= 2;
		
		_delay_us(400000);
	}
}