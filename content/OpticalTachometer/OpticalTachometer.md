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
    @import url(../utilities.css);

size: 16:9
paginate: true
_paginate: false
marp: true
math: true
---

# Implementing the Optical Tachometer using a Integrated Circuit

    Module Code: GEEN1064

    Module Name: Engineering Design and Implementation

    Credits: 20

    Lecturer: Seb Blair BEng(H) PGCAP MIET MIHEEM FHEA

---

## Detecting Light

-  Photoresistor
-  Photodiode
-  Phototransitor

![bg left:40% w:400 vertical ](../../figures/Photoresistors.png)

![bg left:40% 40% vertical ](../../figures/photodiode.png)![bg left:40% 30% vertical ](../../figures/phototransistor.png)

---

## Photoresistor

- Material: highly-resistance semiconductor material called Cadmium Sulfide cell, $Cd^{2+}S^{2-}$, which is highly sensitive to visible and near-infrared light

- Warning: is a known carcinogen and is associated with an elevated risk of developing lung cancer!

- Characteristics:
   - High light intensity -> a lower resistance

  -  Low light intensity -> in a higher resistance
![bg right:30% w:350 vertical ](../../figures/Photoresistors.png)

---

## Photodiode


![bg right:30% w:350 vertical ](../../figures/photodiode.png)
![bg:30% w:600 ertical ](../../figures/layer-structure-of-photodiode.png)

---

## Phototransistor 

![bg right:50% w:600 ](../../figures/phototrans_symbol.png)

- Phototransistors have less ability to maintain a linear relationship between illuminance and output current. 
 
- Brighter light results in more current; less-bright light results in less current.


![bg right: 50% w:200 vertical ](../../figures/phototransistor.png)

---

## Theories

**Volage divider:**

<div align=center>

$V_{Rx} = V{s}\cdot\frac{R1}{R1 + R2}$

$0.45v = 5v\cdot\frac{1000\Omega}{1000\Omega + 10000\Omega}$

</div>

**Ohms Law:**

<div align=center>

$V = I*R$

$I = \frac{V}{R}$

$R = \frac{V}{I}$


</div>

--- 

## Testing light sensitivity : Circuit


---
## Testing light sensitivity : Code

We are going to build a circuit with 


```c
int adc = 0,resistance = 10000;
float voltage = 0, current = 0;

void setup(){
  Serial.begin(9600);
}

void loop{
   adc = analogRead(5);
   voltage = adc / 1023 * 5; // adcMax = 1023 * supplied voltage -> 5V
   current = voltage / resistance; // Ohms law, provides approximation 
   Serial.print("Voltage: ");
   Serial.print(voltage);
   Serial.print(" Current: ");
   Serial.print(current);
   Serial.print(" ADC: ");
   Serial.println(adc);
}
```



--- 

## [taˈkɒmɪtə]








--- 


---
## TC1602A - LCD

![](../../figures/LCD_MashUp.png)

<!--
RS mode 0 -> Command mode
RS mode 1 -> Data mode
RW (Pin 5): Read/Write. This pin selects between read (RW=1) and write (RW=0) operations. Often connected to ground for write-only operations.
E (Pin 6): Enable. This pin is used to enable data transfers to the LCD module.
-->
