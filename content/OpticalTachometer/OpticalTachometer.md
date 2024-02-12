---
title: OpticalTachometer
description: OpticalTachometer slides
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
    grid {
      display: grid;
    }
    grid-cols {
      grid-template-columns: repeat(var(--columns, 2), minmax(0, 1fr));
    }
    grid-rows {
      grid-template-rows: repeat(var(--rows, 2), minmax(0, 1fr));
    }
    gap {
      gap: var(--gap, 4px);
    }
size: 16:9
paginate: true
_paginate: false
marp: true
math: true
---

# OpticalTachometer

    Module Code: GEEN1064

    Module Name: Engineering Design and Implementation

    Credits: 

    Module Leader: 

---


## Implementing the Optical Tachometer using a Integrated Circuit
[taˈkɒmɪtə]

---

## Phototransistor 

- Phototransistors have less ability to maintain a linear relationship between illuminance and output current. 
 
- This isn’t important if all you need is an on/off light detector that produces a digital output voltage


---
## TC1602A - LCD

![](../../figures/LCD_MashUp.png)

<!--
RS mode 0 -> Command mode
RS mode 1 -> Data mode
RW (Pin 5): Read/Write. This pin selects between read (RW=1) and write (RW=0) operations. Often connected to ground for write-only operations.
E (Pin 6): Enable. This pin is used to enable data transfers to the LCD module.
-->

--- 

## 