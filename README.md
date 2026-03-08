# STM32 Prime Number Display on LCD

An embedded systems project using **STM32F401 microcontroller** to detect and display **prime numbers** on a **16×2 LCD**.  
The LCD is interfaced using **8-bit parallel communication through GPIO pins**, demonstrating low-level peripheral configuration in **Embedded C** without using high-level libraries.

---

## 📌 Project Overview

This project implements a **prime number detection algorithm** on the STM32F401 microcontroller.  
The program iterates through numbers and checks whether each number is prime. If a number is prime, it is displayed on a **16×2 LCD module**.

The project focuses on:
- Embedded C programming
- Direct **GPIO register configuration**
- **LCD interfacing in 8-bit mode**
- Basic **algorithm implementation on microcontrollers**

---

## ⚙️ Hardware Requirements

- STM32F401 Microcontroller (Nucleo / custom board)
- 16×2 LCD Display (HD44780 compatible)
- Breadboard / PCB
- Connecting wires
- Power supply (3.3V / 5V depending on LCD)

---

## 🔌 LCD Pin Connections

| LCD Pin | Function | STM32 Pin |
|-------|--------|--------|
| D0–D7 | Data Bus | PA0 – PA7 |
| RS | Register Select | PB1 |
| RW | Read/Write | PB2 |
| EN | Enable | PB0 |
| VSS | Ground | GND |
| VDD | Power | 5V |
| VO | Contrast | Potentiometer |

---

## 💻 Software Requirements

- Keil uVision / STM32CubeIDE
- STM32F4 CMSIS Drivers
- Embedded C

---

## 🚀 Features

- Prime number detection algorithm
- LCD interfacing in **8-bit parallel mode**
- Direct GPIO configuration without HAL
- Displays prime numbers from **0–100**
- Modular LCD driver functions

---

## 📂 Project Structure

```
STM32-Prime-LCD
│
├── main.c
├── STM32F401_LCD.c
├── STM32F401_LCD.h
├── delay.c
├── delay.h
└── README.md
```

---

## 🧠 Prime Number Logic

The program checks whether a number is prime by testing divisibility from **2 up to √n**.

Example logic:

```c
int IsPrime(int num)
{
    if(num <= 1)
        return 0;

    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0)
            return 0;
    }

    return 1;
}
```

---

## 🖥 Example LCD Output

```
Number: 2
Number: 3
Number: 5
Number: 7
Number: 11
...
Number: 97
```

---

## 🎯 Learning Outcomes

- Understanding **microcontroller GPIO configuration**
- Interfacing **character LCD with STM32**
- Implementing algorithms in **embedded systems**
- Writing modular drivers for hardware peripherals

---

## 📜 License

This project is open-source and available under the **MIT License**.

---

## 👨‍💻 Author

**Your Name**

Embedded Systems Enthusiast  
Focused on Microcontrollers, Drivers, and Low-Level Programming
