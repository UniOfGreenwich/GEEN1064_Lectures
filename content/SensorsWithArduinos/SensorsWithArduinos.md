---
title: Sensors with Arduinos
description: Sensors with Arduinos
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
size: 16:9
paginate: true
_paginate: false
marp: true
math: true
---

# Sensors With Arduino Development Board 

    Module Code: GEEN1064

    Module Name: Engineering Design and Implementation

    Lecturer: Seb Blair BEng(H) PGCAP MIET MIHEEM FHEA

---

## What is (and is not) A Microcontroller (µC) PT 1

<div style="font-size:24px">

- A µC is a small, self-contained computer that is housed on asingle integrated circuit, or microchip.

- They differ from your desktop computer in that they are typically dedicated to a single function, and are most often embedded in other devices (e.g. mobile phones; household electronics).

- A µC is an Integrated Circuit (IC) device used for controlling other portions of an electronic system

- These devices are optimized for embedded applications that require both processing functionality and agile, responsive interaction with digital, analogue, or electromechanical components.

</div>

![bg right:30% 100%](../../figures/greekMicro.png)

---

## What is (and is not) A Microcontroller (µC) PT 2

- “µC” is a well-chosen name because it emphasizes defining characteristics of this product category. The prefix “µ” implies smallness and the term "controller" here implies an enhanced ability to perform control functions.

-  As stated above, this functionality is the result of combining a digital processor and digital memory with additional hardware that is specifically designed to help the µC interact with other components.

![bg right:30% 100%](../../figures/greekMicro.png)

---

## Arduino Uno

Prototype Board from Arduino
- The Uno is a µC development board with an Atmega328P Chip
- 14 digital Input/Output (I/O) pins
- 6 Analogue I/O pins (e.g. temperature sensors)
- A 16 MHz quartz crystal

![center](../../figures/arduinoschematics.png)

---

## ATMega-328P Chip

![center](../../figures/atmegachip.png)

---

## Signals

- **Digital**
  - value is either HIGH or LOW ( on/off, one/zero) e.g. switch state

- **Analogue**
  - value ranges, usually from 0-255. e.g. LED brightness, motor speed, etc.

---

## Analogue Sensors

![center](../../figures/analogueSensors.png)

---

## Digital Sensors

![center](../../figures/digitalSensors.png)

---

## Digital To Analogue Conversion With Pulse Width Modulation (PWM)

- Computer cannot output analogue signal
    - Usually digital 0 or 5 volt

- But this can be faked by PWM
    - by averaging digital signal flipping between two values

- The duty cycle is defined as the ratio between the pulse duration, or pulse width and the period of a rectangular waveform and measured in percentage