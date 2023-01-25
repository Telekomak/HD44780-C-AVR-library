# HD44780-AVR-library
## Description:
This library is focused on providing a fast and simple way of communicating with the HD44780 controller while also providing low-level functionality to allow more control over the controller.

## Note:
If this library doesn't work correctly, try redefining ```LCD_DELAY```. This value affects time that LCD chip is given to process data packets (for my display it works with 1500).
Amount of time that HD44780 needs is tied to clock frequency connected to the chip.
Theese values are specified in the [datasheet](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf) on page 24.

It's either this or I've got something wrong in the code.

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
  **Call the `lcd_init()` function with arguments:**
  
  1. pointer to an instance of the `PinConfig` struct
  ``` c
    lcd_init(&config);
  ```
  **Warning:**
  If you change values in `config` you also have to reinitialize the display
  
  **Display is off by default, to turn it on call `lcd_on()` function:**
  ``` c
    lcd_on();
  ```
  
  ### 3. Printing a message:
  **You can prit individual characters with `lcd_write_char()`:**
  ``` c
    lcd_write_char('H');
    lcd_write_char('e');
    lcd_write_char('l');
    lcd_write_char('l');
    lcd_write_char('o');
    lcd_write_char(' ');
    lcd_write_char('w');
    lcd_write_char('o');
    lcd_write_char('r');
    lcd_write_char('l');
    lcd_write_char('d');
    lcd_write_char('!');
  ```
  **To clear the display use `lcd_clear()`:**
  ``` c
    lcd_clear();
  ```
  **To write string use `lcd_write_string()` with arguments:**
  
  1. pointer to the string
  2. lenght of the string
  ``` c
    char greetings[] = "Hello world!";
    lcd_write_string(&greetings[0], 12);
  ```
  
## 4. Reference:
  
  ### `int lcd_init(PinConfig* config)`: ###
  
  - **Description:**
  
        Initializes the HD44780 interface
    
  - **Arguments:**
  
        1. Pointer to instance of PinConfig struct
    
  - **Return value: `int`:** 
  
        0 if success
        1 if pin verification failed (some values specified in supplied config are the same or 0)
    
    
 ### `void lcd_command(uint8_t command)`: ###
  
  - **Description:**
  
        Sends command for the display (list of commands can be found in the datasheet on page 25)
    
  - **Arguments:**
  
        1. Command (in the datasheet refferred to as `instruction`)
    
  - **Return value: `void`:** 
  
        none
    
    
 ### `void lcd_write_char(char character)`: ###
  
  - **Description:**
  
        Writes one character to the display
    
  - **Arguments:**
  
        1. ASCII character
    
  - **Return value: `void`:** 
  
        none
    
 ### `void lcd_clear()`: ###
  
  - **Description:**
  
        Clears the display
    
  - **Arguments:**
  
        none
    
  - **Return value: `void`:** 
  
        none
    
    
 ### `void lcd_set_cursor(uint8_t row, uint8_t collumn)`: ###
  
  - **Description:**
  
        Sets the cursor position
    
  - **Arguments:**
  
        1. row (0 or 1)
        2. collumn (0 to 40)
    
  - **Return value: `void`:** 
  
        none
        
     
 ### `void lcd_write_string(char* string, unsigned long length)`: ###
  
  - **Description:**
  
        Writes string of characters to the display
    
  - **Arguments:**
  
        1. pointer to the first character of the string
        2. length of the string
    
  - **Return value: `void`:** 
  
        none
        
        
 ### `void lcd_pulse_en()`: ###
  
  - **Description:**
  
        Pulses the EN pin of the display 
          1. pulls the pin HIGH
          2. waits specified amount of microseconds (LCD_DELAY in HD44780/HD44780.c)
          3. pulls the pin LOW again
    
  - **Arguments:**
  
        none
    
  - **Return value: `void`:** 
  
        none
        
        
  ### `void lcd_pulse_en_repeat(int repeat)`: ###
  
  - **Description:**
  
        Calls lcd_pulse_en() specified amount of times
    
  - **Arguments:**
  
        1. amount of times to repeat
    
  - **Return value: `void`:** 
  
        none
        
        
 ### `void lcd_show_cursor(uint8_t blink)`: ###
  
  - **Description:**
  
        Turns on cursor on the display
    
  - **Arguments:**
  
        1. Should the cursor blink?
           0 - no
           > 0 - yes
    
  - **Return value: `void`:** 
  
        none
        
 
 ### `void lcd_hide_cusror()`: ###
  
  - **Description:**
  
        Turns of cursor on the display
    
  - **Arguments:**
  
        none
    
  - **Return value: `void`:** 
  
        none
        
 
  ### `void lcd_on()`: ###
  
  - **Description:**
  
        Turns on the display
    
  - **Arguments:**
  
        none
    
  - **Return value: `void`:** 
  
        none
        
 
 ### `void lcd_off()`: ###
  
  - **Description:**
  
        Turns off the display
    
  - **Arguments:**
  
        none
    
  - **Return value: `void`:** 
  
        none
        
 
 ### `void lcd_home()`: ###
  
  - **Description:**
  
        Sets cursor to the home position (0, 0)
    
  - **Arguments:**
  
        none
    
  - **Return value: `void`:** 
  
        none
        
 
## Resources:
- [**HD44780 datasheet**](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf)
- [**Awesome guide i was following**](https://www.glennklockwood.com/electronics/hd44780-lcd-display.html#introduction)
