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
![Pinout]()
