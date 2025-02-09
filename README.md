# HD44780-AVR-library
## Description:
This library is focused on providing a fast and simple way of communicating with the HD44780 controller while also providing low-level functionality to allow more control over the controller.

## Note:
You can control data rate by redefining `LCD_DELAY` macro (default is 100)

## Targets:
AVR devices

## Limitations:
  - Only supports 4-bit interface
  - Doesn't support reading from display memory
  - All pins have to be connected within a single port (PORTB, PORTD, etc..)

## HD44780 LCD pinout:
![Pinout](https://github.com/Telekomak/HD44780-AVR-library/blob/master/lcd_pinout.png?raw=true)

# Usage:
## Getting started:
  ### 1. Pin configuration:
  **Warning:** All pins have to be connected within a single port!
  
  **Create instance of `PinConfig` struct:**
  ```c
  PinConfig config = {.ddr = &DDRD, .port = &PORTD, .d0 = 16, .d1 = 32, .d2 = 64, .d3 = 128, .rs = 4, .en = 8};
  ```
  **Values in `PinConfig` struct:**
  
  Assigned values must be corresponding to values of individual bits in port register:
  
  ![values](https://user-images.githubusercontent.com/65535357/185972927-10caa351-8ff5-4215-bb8a-56a6f6a83714.png)
  
  ### 2. Initializing the display
  **Call the `LCD_init(PinConfig*)` function with arguments:**
  
  1. pointer to an instance of the `PinConfig` struct
  ``` c
    LCD_init(&config);
  ```
  **Warning:**
  If you change values in `config` you will also need to reinitialize the display
  
  **Display is off by default, to turn it on call `LCD_on()` function:**
  ``` c
    LCD_on();
  ```
  
  ### 3. Printing a message:
  **You can prit individual characters with `LCD_write_char()`:**
  ``` c
    LCD_write_char('H');
    LCD_write_char('e');
    LCD_write_char('l');
    LCD_write_char('l');
    LCD_write_char('o');
    LCD_write_char(' ');
    LCD_write_char('w');
    LCD_write_char('o');
    LCD_write_char('r');
    LCD_write_char('l');
    LCD_write_char('d');
    LCD_write_char('!');
  ```
  **To clear the display use `LCD_clear()`:**
  ``` c
    LCD_clear();
  ```
  **To write string use `LCD_write_string(char*)` with arguments:**
  
  1. pointer to the string
  ``` c
    char greetings[] = "Hello world!";
    LCD_write_string(&greetings[0]);
  ```
  
## 4. Reference:
  
  ### `int LCD_init(PinConfig* config)`: ###
  
  - **Description:**
  
        Initializes the HD44780 interface
    
  - **Arguments:**
  
        1. Pointer to instance of PinConfig struct
    
  - **Return value: `int`:** 
  
        0 if success
        1 if pin verification failed (some values specified in provided config are the same or 0)
    
    
 ### `void LCD_instruction(uint8_t instruction)`: ###
  
  - **Description:**
  
        Sends instruction to the display (list of instruction can be found in the datasheet on page 24)
    
  - **Arguments:**
  
        1. Instruction
    
  - **Return value: `void`:** 
  
        none
    
    
 ### `void LCD_write_char(char character)`: ###
  
  - **Description:**
  
        Writes one character to the display
    
  - **Arguments:**
  
        1. ASCII character
    
  - **Return value: `void`:** 
  
        none
    
 ### `void LCD_clear()`: ###
  
  - **Description:**
  
        Clears the display
    
  - **Arguments:**
  
        none
    
  - **Return value: `void`:** 
  
        none
    
    
 ### `void LCD_set_cursor(uint8_t row, uint8_t collumn)`: ###
  
  - **Description:**
  
        Sets the cursor position
    
  - **Arguments:**
  
        1. row (0 or 1)
        2. collumn (0 to 40)
    
  - **Return value: `void`:** 
  
        none
        
     
 ### `void LCD_write_string(char* string)`: ###
  
  - **Description:**
  
        Writes string of characters to the display
    
  - **Arguments:**
  
        1. pointer to the string
    
  - **Return value: `void`:** 
  
        none
 
 ### `void LCD_write_buffer(char* buffer, uint16_t length)`: ###
  
  - **Description:**
  
        Writes buffer to the display
    
  - **Arguments:**
  
        1. pointer to the buffer
        2. length of the buffer
    
  - **Return value: `void`:** 
  
        none
 
        
 ### `void LCD_pulse_en()`: ###
  
  - **Description:**
  
        Pulses the EN pin of the display 
          1. pulls the pin HIGH
          2. waits specified amount of microseconds (LCD_DELAY in HD44780/HD44780.h)
          3. pulls the pin LOW again
    
  - **Arguments:**
  
        none
    
  - **Return value: `void`:** 
  
        none
        
        
  ### `void LCD_pulse_en_repeat(int repeat)`: ###
  
  - **Description:**
  
        Calls LCD_pulse_en() specified amount of times
    
  - **Arguments:**
  
        1. amount of times to repeat
    
  - **Return value: `void`:** 
  
        none
        
        
 ### `void LCD_show_cursor()`: ###
  
  - **Description:**
  
        Turns on cursor on the display
    
  - **Arguments:**
        
        none
        
  - **Return value: `void`:** 
  
        none
        
 
 ### `void LCD_hide_cusror()`: ###
  
  - **Description:**
  
        Turns off cursor on the display
    
  - **Arguments:**
  
        none
    
  - **Return value: `void`:** 
  
        none
        
 
  ### `void LCD_on()`: ###
  
  - **Description:**
  
        Turns on the display
    
  - **Arguments:**
  
        none
    
  - **Return value: `void`:** 
  
        none
        
 
 ### `void LCD_off()`: ###
  
  - **Description:**
  
        Turns off the display
    
  - **Arguments:**
  
        none
    
  - **Return value: `void`:** 
  
        none
        
 ### `void LCD_cursor_blink()`: ###
  
  - **Description:**
  
        Turns cursor blink on
    
  - **Arguments:**
  
        none
    
  - **Return value: `void`:** 
  
        none
        
 ### `void LCD_cursor_noblink()`: ###
  
  - **Description:**
  
        Turns cursor blink off
    
  - **Arguments:**
  
        none
    
  - **Return value: `void`:** 
  
        none
 
 ### `void LCD_home()`: ###
  
  - **Description:**
  
        Sets cursor to the home position (0, 0)
    
  - **Arguments:**
  
        none
    
  - **Return value: `void`:** 
  
        none
        
 
## Resources:
- [**HD44780 datasheet**](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf)
- [**Guide for communication**](https://www.glennklockwood.com/electronics/hd44780-lcd-display.html#introduction)
