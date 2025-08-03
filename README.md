# AVR Atmega32 Calculator 🧮💻🔌

This project is a simple hardware-based calculator implemented using an AVR Atmega32 microcontroller. The calculator can perform basic arithmetic operations (addition, subtraction, multiplication, and division) on two numbers. It uses an LCD display for output and a keypad for input.

## Features ✨📌

- **Addition, subtraction, multiplication, and division** of two numbers
- **LCD display** for clear output
- **Keypad input** for easy number entry
- **Clear display** functionality

## Hardware Requirements 🛠️🧰

- **Microcontroller**: AVR Atmega32
- **LCD Display**
- **Keypad**
- **Crystal oscillator**: 8 MHz
- **Capacitors, resistors, and connecting wires**

## Software Layer 🖥️💡

1. **MCAL**: DIO (Digital Input/Output)
2. **HAL**: LCD (4 Bit Mode), Keypad

## Usage 📝

1. **Connect** the hardware components as per the circuit diagram.
2. **Compile** the code using the AVR-GCC compiler.
3. **Upload** the compiled code to the AVR Atmega32 microcontroller using AVRDUDE.
4. **Power up** the microcontroller to start the calculator.

## How It Works ⚙️

- **Input Numbers**: Use the keypad to enter numbers.
- **Select Operation**: Press the corresponding key for addition (`+`), subtraction (`-`), multiplication (`*`), or division (`/`).
- **Calculate**: Press the `=` key to perform the operation and display the result on the LCD.
- **Clear Display**: Press the `c` key to clear the display.
![Calculator](https://github.com/user-attachments/assets/f7f3cc19-40f1-4996-8fcd-e8955f5da1db)


---

Made with ❤️ by [Aboubakr Omar Ibnelkhatab]
