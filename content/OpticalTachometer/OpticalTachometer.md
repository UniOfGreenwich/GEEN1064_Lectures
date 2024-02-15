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

$V_{out} = \frac{R1}{R1 + R2}\cdot V_{in}$

$$ 3.18V = \frac{470\Omega}{270\Omega+470\Omega} \cdot 5V \Lleftarrow V_{out} = \frac{R2}{R1 + R2} \cdot V_{in} $$

</div>

**Ohms Law:**

<div align=center>

$V = I*R$

$I = \frac{V}{R}$

$R = \frac{V}{I}$




</div>

--- 

## Testing light sensitivity : Circuit

![bg right:40% w:500](../../figures/digitalPhototransistorCircuit.PNG)

 - we are doing this physically
---
## Testing light sensitivity : Code

- Try different colour LEDs and distances, is there a difference?

```c
int adc = 0,resistance = 10000;
float voltage = 0, current = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
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

## Propeller/Turbines

![bg right:40% w:500](../../figures/propeller_types.jpg)

- RPM 
  - is more practical and widely used in engineering and everyday settings where specific rotational speeds need to be specified and monitored
- Angular Velocity ($\omega$)
  - is more commonly used in theoretical and analytical studies of rotational motion.

<div align="center">

$\omega = \frac{2\Pi\  \cdot\ RPM}{60}$

</div>


---

## Matlab code

- Open and Create a script, call it what you like.

```matlab
clear
clc
% Manually declare the RPM array
RPM = [0, 100, 150, 264, 304, 418, 500, 526, 526, 526, 526, 526, 526, 524, 524, 526, 526, 526, 526, 526, 526, 526, 450];

% Number of data points
num_points = numel(RPM);

% Time in minutes
T_mim = (0:num_points-1).';

% Calculate rad/m
rad_per_m = pi() * 2 * RPM;

% Calculate rad/s
rad_per_s = rad_per_m / 60;

% Calculate delta rad/s
delta_rad_per_s = [0; diff(rad_per_s)];

% Calculate rad/s^2
rad_per_s_squared = delta_rad_per_s ./ [0; diff(T_mim)];
```
 
---

## Matlab code Part 2

```matlab
% Create figure
figure;

% Create bar plot for rad_per_min
yyaxis left;
bar(T_mim, rad_per_s);
xlabel('T_min');
ylabel('Rad/s (Bar)');
title('RPM vs Rad/s^2');
grid on;

% Create line plot for rad_per_s_squared
yyaxis right;
plot(T_mim, rad_per_s_squared, 'LineWidth', 2);
ylabel('Rad/s^2 (Line)');

% Show legend
legend('Rad/s', 'Rad/s^2');

% Adjust y-axis limits for line plot
ylim_right = ylim;
ylim_right(1) = min(ylim_right(1), 0); % Ensure minimum value is 0
yyaxis right;
ylim(ylim_right);

% Adjust figure layout
grid on;
```

---

## Arduino [taˈkɒmɪtə] code

```c
unsigned int rpm = 0;
int count = 0, timeOld = 0;
const float distance_per_revolution_mm = 88.86;

void setup(){
  Serial.begin(9600);
}

void loop(){
  delay(1000);

  for (int i = 0; i < 60; i++)
  {
    if (analogRead(5) < 80){
       count++;
    }
  }
  //(30 = 2 blades) (20 = 3 blades) (15 = 4 blades) (12 = 5 blades)
  rpm = (2 * rpmcount * 60000) / (millis() - timeold) * distance_per_revolution;

  Serial.print("RPM: ");
  Serial.println(rpm);
  timeOld = millis();

}
```

---

## Interrupts

- Micro Controllers can only do one thing at a time. 
- We use interrupts to break out of what is currently being executed
  - External Interrupts (Pins)
  - Timer/Counter Interrupts (internal clock)
  - Serial Communication Interrupts (receiving data)
  - ADC Conversion Complete Interrupt (`analogRead()`)

![bg right:50% 100%](../../figures/interrupts.jpg)

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

## Adding the LCD to the current ciruit


---

## Final code


---
