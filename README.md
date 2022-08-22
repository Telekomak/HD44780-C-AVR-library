# HD44780-AVR-library
## Description:
This library is focused on providing a fast and simple way of communicating with the HD44780 controller while also providing low-level functionality to allow more control over the controller.

The project is written in C without the use of the Arduino framework.

## Targets:
AVR devices

## Limitations:
  - Only supports 4-bit interface
  - Doesn't support reading from display memory
  - All pins have to be connected within a single port (PORTB, PORTD, etc..)

## HD44780 LCD pinout:
![Pinout](https://github.com/Telekomak/HD44780-AVR-library/blob/master/lcd_pinout.png?raw=true)

## Usage:
### Getting started:
  #### 1. Pin configuration:
  **All pins have to be connected within a single port!**
  
  ##### Create instance of `PinConfig` struct:
  ```c
  PinConfig config = {.ddr = &DDRD, .port = &PORTD, .d0 = 16, .d1 = 32, .d2 = 64, .d3 = 128, .rs = 4, .en = 8};
  ```
  ##### Values in `PinConfig` struct:
  Assigned values must be corresponding to values of individual bits in port register
  
  ![values](https://user-images.githubusercontent.com/65535357/185972927-10caa351-8ff5-4215-bb8a-56a6f6a83714.png)
  
  #### 2. Initialize the display
  Call the `lcd_init()` function:
  ``` c
    lcd_init(&config);
  ```
  **Warning:**
  **If you change values in `config` you also need to reinitialize the display**
  
  Display is off by default, to turn it on call `lcd_on()` function:
  ``` c
    lcd_on();
  ```
  
  #### 3. Printing a message:
  You can prit individual characters with `lcd_write_char()`:
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
  To clear the display use `lcd_clear()`:
  ``` c
    lcd_clear();
  ```
  To write string use `lcd_write_string()`:
  ``` c
    char greetings[] = "Hello world!";
    lcd_write_string(&greetings[0], 12);
  ```
  
  #### 4. Other stuff:
  Set cursor position with `` 
