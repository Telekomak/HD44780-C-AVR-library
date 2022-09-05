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
  
  ### 4. Other usefull functions:
  **Enable cursor using `lcd_show_cursor()` with arguments:**
  
  1. enable blink (0 or 1)
  ``` c
    lcd_show_cursor(1);
  ```
  **Disable cursor using `lcd_hide_cursor()`:**
  ``` c
    lcd_hide_cursor();
  ```
  **Set cursor position using `lcd_set_cursor()` with arguments:**
  
  1. row (0 - 1)
  2. collumn (0 - 40)
  ``` c
    lcd_set_cursor(0, 5);
  ```
  **Move cursor back to home position using `lcd_home()`:**
  ``` c
    lcd_home();
  ```
  **Turn the display off using `lcd_off()`:**
  ``` c
    lcd_off();
  ```
  **Send commands to controller using `lcd_command()` with arguments:**
  
  1. command
  ``` c
    lcd_command(0x01);
  ```
  Note: You can find list of all commands in the [datasheet](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf) on page 23 under *Instructions*
  
  **Pulse LCD's EN pin using `lcd_pulse_en`**:
  ``` c
    lcd_pulse_en();
  ```
  
## Resources:
- [**HD44780 datasheet**](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf)
- [**Awesome guide i was following**](https://www.glennklockwood.com/electronics/hd44780-lcd-display.html#introduction)
