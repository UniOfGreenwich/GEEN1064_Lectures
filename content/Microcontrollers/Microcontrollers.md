---
title: Mirco Controllers
description: Micro Controllers
class: gaia
_class:
  - lead
  - invert
style: |
    #img-right{
      float: right;
    }
    img[alt~="center"] {
      display: block;
      margin: 0 auto;
    }
    table {
      border-collapse: collapse;
      font-size: 22px;
    }
    table, th,tr, td {
      border: none!important;
      vertical-align: middle;
    }
    section::after {
    content: attr(data-marpit-pagination) '/' attr(data-marpit-pagination-total);
    }
footer: GEEN1064 | Engineering Design and Implementation
auto-scaling: false
paginate: true
_paginate: false
marp: true
math: true
---

# Development Boards 

    Module Code: GEEN1064

    Module Name: Engineering Design and Implementation

    Lecturer: Seb Blair BEng(H) PGCAP MIET MIHEEM FHEA

---

## What is (and isn't) a Microncontoller ($\mu$C)

- A µC is a small, self-contained computer that is housed on a
  single integrated circuit, or microchip.

- They differ from your desktop computer in that they are typically dedicated to a single function, and are most often embedded in other devices (e.g. mobile phones; household electronics).

- A µC is an Integrated Circuit (IC) device used for controlling other portions of an electronic system

- These devices are optimized for embedded applications that require both processing functionality and agile, responsive interaction with digital, analogue, or electromechanical components.

---

## What is (and isn't) a Microncontoller ($\mu$C)

- µC” is a well-chosen name because it emphasizes defining characteristics of this product category. The prefix “µ” implies smallness and the term "controller" here implies an enhanced ability to perform control functions.

-  As stated above, this functionality is the result of combining a digital processor and digital memory with additional hardware that is specifically designed to help the µC interact with other components.

---

## Microcontroller vs a Microprocessor

- µP contain only a Central Processing Unit (CPU), and therefore require added peripherals to perform tasks.

- CPU is the brain of any computer and it is the part of a computer that performs calculations, actions, and runs programs.
  - Intel Core i series, AMD

![bg right:50% 50%](../../figures/upANDuc.png)


---

## RAM and ROM

- µCs, on the other hand, contain RAM, ROM, and similar peripherals, which allow them to perform (simple) tasks independently.

- Random-Access Memory (RAM)
  - everyday tasks, such as loading applications, browsing the internet,editing a spreadsheet, or experiencing the latest game

- Read-Only Memory (ROM)  
  - computer memory chips containing permanent or semi-permanent data. Unlike RAM, ROM is non-volatile; even after you turn off your computer, the contents of ROM will remain

---

## Exploded View

![w:800 center](../../figures/micontrollerExplodedView.png)

---

## Deployment Platforms

- Prototyping platforms
  - Arduino family -> Uno, Mega, MKR series…
  - Single board computers -> Raspberry Pi, Orange Pi, Odroid, Jetson Nano….
- Used to build physical computing projects
  - Taking information from the world around us by using inputs such as sensors and switches and responding to that information with outputs like actuators, graphical indicators, lights etc.
- Open source hardware and software
  
- Open source projects emphasise the importance of documentation and sharing,
making the community of users a great resource for learners.

---

## Arduino Uno

Prototype Board from Arduino
- The Uno is a µC development board with an Atmega328P Chip
- 14 digital Input/Output (I/O) pins
- 6 Analogue Input pins (e.g. temperature sensors)
- 6 PWM Output pins (e.g. actuators)
- A 16 MHz quartz crystal

![bg right:50% 100%](../../figures/arduinoschematics.png)

---

## ATMega-328P Chip

![center](../../figures/atmegachip.png)

---

![w:935 center](../../figures/AUno_Rev2_CD.png)

---

![w:1050 center](../../figures/AD_Pinout.png)

----

## Base Code

<div style="font-size:27px">

```cpp
int led = 12; // set a variable, in this case pin number 12

void setup(){
  // Should only run once
  pinMode(led, OUTPUT); // set pin to send signal out
  Serial.begin(9600); // set the speed at which data is transmitted to the serial monitor
}

void loop(){
  // This runs forever
  digtialWrite(led, HIGH); // Turn pin 12 on
  Serial.println("On");
  delay(500); // on for 0.5 secs
  digtialWrite(led, LOW); // turn pin 12 off
  Serial.println("Off");
  delay(500); // off for 0.5 secs
}
```

</div>

----

## Basic Functions

```c
pinMode(int, <OUTPUT/INPUT>); // pin, direction
digitalWrite(int, <HIGH/LOW>); // pin, state

analogRead(int); // pin
analogWrite(int , int); // pin, value (0-255)

Serial.begin(int); // speed (4800. 9600, 19200 ...)
Serial.print(Type); // will write to serial any data type, without a new line terminator "/n"
Serial.println(Type); // will write to serial any data type, with a new line terminator "/n"

delay(int); // a specified amount of time in ms the cpu will wait before continuing to the next line
```

<!--
## Progamming a $\mu C$

Like all µC they only work if they are programmed to. Generally they are programmed using `C/C++`, `Assembly` programming languages which all compile down to binary. 

<div align=center>
<table>
<tr>
<td>
Assembly

```asm
add:
    push rbp
    mov rbp, rsp
    mov DWORD PTR [rbp-4], edi
    mov DWORD PTR [rbp-8], esi
    mov edx, DWORD PTR [rbp-4]
    mov eax, DWORD PTR [rbp-8]
    add eax, edx
    pop rbp
ret
```

</td>

<td>
C/C++

```c
int add(int num){
  return num + num;
}
```

</td>
</tr>
</table>
</div>

Don’t worry will not be programming in Assembly, `C/C++` is a language we can understand easily as it more human readable.

---

## Simulation Time

We are going to use tinkercad to simulated in using a microcontroller in a safe environment.


![](./../figures/tinkercardlogo.png)
[www.tinkercad.com](www.tinkercad.com)

![bg right:50% 100% vertical](../../figures/tinkercadpreview.png)

-->