#ifndef HD44780_LCD_H
#define HD44780_LCD_H

#ifndef F_CPU
	#define F_CPU 16000000u
#endif

#ifndef LCD_DELAY
	#define LCD_DELAY 100
#endif

//static config
#ifndef LCD_CONFIG_DDR
	#define LCD_CONFIG_DDR DDRB
#endif

#ifndef LCD_CONFIG_PORT
	#define LCD_CONFIG_PORT PORTB
#endif

#ifndef LCD_CONFIG_PIN_RS
	#define LCD_CONFIG_PIN_RS 1
#endif

#ifndef LCD_CONFIG_PIN_EN
	#define LCD_CONFIG_PIN_EN 2
#endif

#ifndef LCD_CONFIG_PIN_D0
	#define LCD_CONFIG_PIN_D0 4
#endif

#ifndef LCD_CONFIG_PIN_D1
	#define LCD_CONFIG_PIN_D1 8
#endif

#ifndef LCD_CONFIG_PIN_D2
	#define LCD_CONFIG_PIN_D2 16
#endif

#ifndef LCD_CONFIG_PIN_D3
	#define LCD_CONFIG_PIN_D3 32
#endif

#include <avr/io.h>
#include <util/delay.h>

typedef struct PinConfig{
	volatile uint8_t* ddr;
	volatile uint8_t* port;
	uint8_t rs;
	uint8_t en;
	uint8_t d0;
	uint8_t d1;
	uint8_t d2;
	uint8_t d3;
} PinConfig;

uint8_t LCD_init_dynamic(PinConfig* config);
void LCD_init_static();
void LCD_instruction(uint8_t instruction);
void LCD_write_char(char character);
void LCD_clear();
void LCD_set_cursor(uint8_t row, uint8_t collumn);
void LCD_write_string(char* string);
void LCD_write_buffer(char* buffer, uint16_t length);
void LCD_show_cursor();
void LCD_hide_cursor();
void LCD_on();
void LCD_off();
void LCD_home();
void LCD_cursor_blink();
void LCD_cursor_noblink();
#endif