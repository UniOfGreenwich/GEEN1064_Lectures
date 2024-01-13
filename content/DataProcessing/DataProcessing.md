---
title: Data Processing
description: Data Processing slides
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
      font-size: 24px;
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

# Data Processing

    Module Code: GEEN1064

    Module Name: Engineering Design and Implementation

    Credits: 20 

    Lecturer: Seb Blair BEng(H) PGCAP MIET MIHEEM FHEA 

---

## Content

- Information Theory
- Binary
- Hexadecimal
- Octal 

---

## Information Theory

- [A Mathematical Theory of Communication, (Shannon,1948)](https://archive.org/details/bellsystemtechni27amerrich/page/n399/mode/2up)

  - Term *bit* was introduced as something that can have the representation of **1** or **0** most commonly an electrical signal 
  - Foundations of the electrical computer was built off of this knowledge. 

- Sequences of bits have no intrinsic meaning except for the representation that we assign to them, both by convention and by building particular operations into the hardware.

---

## Binary

By choosing an appropriate representation, you can use bits to represent any value you can imagine:

- Characters are represented using numeric character codes.
- Floating-point representation supports real numbers.
- Two-dimensional arrays of bits represent images.
- Sequences of images represent video. 
- and so on... 

>>*can be read right to left or left to right (an important distinction)*

---


## Uses: 

|Base|Combinations|Example|
|---|---|---|
|**$2^3$**|$8_{10}$|Linux User Permissions $\rightarrow$ `rwx` $\rightarrow$ $7_3$ $\rightarrow$ $0\ 1\ 1\ 1_2$ |
|**$2^4$**|$16_{10}$|Hex  $\rightarrow$ $A_{16}$ $\rightarrow$ $1\ 0\ 1\ 0_2$ $\rightarrow$ $10_{10}$|
|**$2^8$**|$256_{10}$|ASCII $\rightarrow$ $A_{256}$ $\rightarrow$ $65_{10}$ $\rightarrow$ $0\ 1\ 0\ 0\ 0\ 0\ 0\ 1_2$|
|**$2^{10}$**|$1024_{10}$|ADC $\rightarrow$ 2.5V $\rightarrow$ $512_{10}$ $\rightarrow$ $1\ 0\ 0\ 0\ 0\ 0\ 0\ 0\ 0\ 0_2$ |
|**$2^{12}$**|$4096_{10}$|ADC $\rightarrow$ 2.5V $\rightarrow$ $1\ 0\ 0\ 0\ 0\ 0\ 0\ 0\ 0\ 0\ 0\ 0_2$ |
|**$2^{16}$**|$65536_{10}$|Colour (RGB) $\rightarrow$ <font  color="#8833FF">#8833FF$_{16}$ </font> $\rightarrow$ 136$_{10}$, 51$_{10}$, 255$_{10}$ $\rightarrow$ $1\ 0\ 0\ 0\ ... 1\ 1\ 1\ 1_2$ |
|**$2^{32}$**|$4.29_{10}\cdot 10^9$|IPv4 $\rightarrow$ $192.168.0.12_{10}$ $\rightarrow$ $11000000.10101000.00000000.00001100_2$ |
|**$2^{64}$**|$18.4_{10}\cdot 10^{18}$|64-bit OS ||
|**$2^{128}$**|$340_{36}$|IPv6 $\rightarrow$ 2001:db8:85a3:8d3:1319:8a2e:370:7348$_{16}$ $\rightarrow$ $0010...1000_2$ |

---

## Binary

<div align=center>

|Decimal | Binary||Decimal|Binary
|---|---|----|---|---|
|0|0 0 0 0 0 0||10|0 0 1 0 1 0|
|1|0 0 0 0 0 1||11|0 0 1 0 1 1|
|2|0 0 0 0 1 0||12|0 0 1 1 0 0|
|3|0 0 0 0 1 1||13|0 0 1 1 0 1|
|4|0 0 0 1 0 0||14|0 0 1 1 1 0|
|5|0 0 0 1 0 1||15|0 0 1 1 1 1|
|6|0 0 0 1 1 0||16|0 0 1 0 0 0|
|7|0 0 0 1 1 1||17|0 1 0 0 0 1|
|8|0 0 1 0 0 0||...|...|
|9|0 0 1 0 0 1||63|1 1 1 1 1 1|


</div>

---

## Binary ($2^n$)

The number of combinations can be found by doing the following: 
$N_{combinations} = 2^n$ 

You can calculate the maximum number you can have:

$N_{maxValue} = 2^n -1$ 

<p align=center>

||     MSB |         |         |          |          |         |          |         |         |         |     LSB|
|---|---------|---------|---------|----------|----------|---------|----------|---------|---------|---------|--------|
||**$2^{10}$** | **$2^{9}$** | **$2^{8}$** |  **$2^{7}$** |  **$2^{6}$** | **$2^{5}$** | **$2^{4}$**  | **$2^{3}$** | **$2^{2}$** | **$2^{1}$** | **$2^{0}$** |
|$2^n$|  1024   |   512   |   256   |    128  |    64   |   32   |   16   |    8    |   4    |   2   |   1  |
|$2^n-1$|  1023   |   511   |   255   |    127  |    63   |   31   |   15   |    7    |   3    |   1   |   0  | 

</p>

---


## Binary to Decimal
<p align=center>

|**$2^{10}$** | **$2^{9}$** | **$2^{8}$** |  **$2^{7}$** |  **$2^{6}$** | **$2^{5}$** | **$2^{4}$**  | **$2^{3}$** | **$2^{2}$** | **$2^{1}$** | **$2^{0}$** |
|---------|---------|---------|----------|----------|---------|----------|---------|---------|---------|--------|
|  1024   |   512   |   256   |    128  |    64   |   32   |   16   |    8    |   4    |   2   |   1  | 
| **0**   |  **0**  |  **0**  |  **1**  |  **0**  |  **0** |  **1** |  **0**  |  **1** | **1** | **0**|

</p>

Therefore the decimal equivalent value is:
$$
    \begin{aligned}
     1 \cdot 2^7 &= 128_{10}\\
     1 \cdot 2^4 &=  \hspace{0.5em}16_{10} \\
     1 \cdot 2^2 &=  \hspace{1em} 4_{10} \\
     1 \cdot 2^1 &=   \hspace{1em} 2_{10} \hspace{0.5em}+ \\
      \hline
      [0]000 \ 1001 \ 0110_2 &\equiv  150_{10}
    \end{aligned}
$$

---

## Your turn

<p align=center>

|**$2^{10}$** | **$2^{9}$** | **$2^{8}$** |  **$2^{7}$** |  **$2^{6}$** | **$2^{5}$** | **$2^{4}$**  | **$2^{3}$** | **$2^{2}$** | **$2^{1}$** | **$2^{0}$** |
|---------|---------|---------|----------|----------|---------|----------|---------|---------|---------|--------|
|  1024   |   512   |   256   |    128  |    64   |   32   |   16   |    8    |   4    |   2   |   1  | 

</p>

- $1\ 1\ 1\ 1_2$ <details>
  <summary>Answer</summary>

    $15_{10}$
  
  </details>

- $1\ 1\ 1\ 1\ 1\ 1\ 0\ 1_2$ <details>
  <summary>Answer</summary>

    $253_{10}$
  
  </details>

---

## Little or Big Endian

 - The order in which binary is read is very important. 
 - consider: 
    - $1\ 0\ 0\ 0\ 0\ 0\ 0\ 0_2 = 256_{10} \  || \  1_{10}$ 
 - or:
    - $1\ 0\ 0\ 1\ 1\ 0\ 0\ 1_2 = 153_{10} \ || \ 153_{10}$

- Intel processors use little endian 
- ISO standard for network address is big endian

---

## Why does size matter?

- $2.96 billion reasons why.
- 42 seconds
- One value
 
![bg right:60% 100%](../../figures/ariane5.gif)

</div>

---

## Integer Overflow: One line of Code

```ada
-- Vertical velocity as measured by sensor
L_M_BV_32 := TBD.T_ENTIER_32S ((1.0/C_M_LSB_BV) * G_M_INFO_DERIVE(T_ALG.E_BV));
-- Check, if measured vertical velocity bias can be
-- converted to a 16 bit int. If so, then convert
if L_M_BV_32 > 32767 then
P_M_DERIVE(T_ALG.E_BV) := 16#7FFF#;
elsif L_M_BV_32 < -32768 then
P_M_DERIVE(T_ALG.E_BV) := 16#8000#;
else
P_M_DERIVE(T_ALG.E_BV) := UC_16S_EN_16NS(TDB.T_ENTIER_16S(L_M_BV_32));
end if;
-- Horizontal velocity bias as measured by sensor
-- is converted to a 16 bit int without checking
P_M_DERIVE(T_ALG.E_BH) := UC_16S_EN_16NS (TDB.T_ENTIER_16S ((1.0/C_M_LSB_BH) *
G_M_INFO_DERIVE(T_ALG.E_BH)));
```

---

## Simplified: 

```ada
-- Vertical velocity as measured by sensor
L_M_BV_32 = ConvertTo32BitSigned((1.0 / C_M_LSB_BV) * GetSensorInfo(T_ALG.E_BV))

-- Check if measured vertical velocity bias can be converted to a 16-bit int
if L_M_BV_32 > 32767 then
    P_M_DERIVE[T_ALG.E_BV] = 32767
elsif L_M_BV_32 < -32768 then
    P_M_DERIVE[T_ALG.E_BV] = -32768
else
    P_M_DERIVE[T_ALG.E_BV] = ConvertTo16BitSigned(L_M_BV_32)
end if

-- Horizontal velocity bias as measured by sensor is converted to a 16-bit int without checking
P_M_DERIVE[T_ALG.E_BH] = ConvertTo16BitSigned((1.0 / C_M_LSB_BH) * GetSensorInfo(T_ALG.E_BH))

```


---
## A fix...

```c
int32_t L_M_BV_32 = (int32_t)((1.0 / C_M_LSB_BH) * G_M_INFO_DERIVE(T_ALG.E_BV));

if (L_M_BV_32 > 32767) {
    P_M_DERIVE[T_ALG.E_BV] = 0x7FFF;
} else if (L_M_BV_32 < -32768) {
    P_M_DERIVE[T_ALG.E_BV] = (int16_t)0x8000;
} else {
    P_M_DERIVE[T_ALG.E_BV] = UC_16S_EN_16NS((int16_t)L_M_BV_32);
}

int32_t L_M_BH_32 = (int32_t)((1.0 / C_M_LSB_BH) * G_M_INFO_DERIVE(T_ALG.E_BH));

if (L_M_BH_32 > 32767) {
    P_M_DERIVE[T_ALG.E_BH] = 0x7FFF;
} else if (L_M_BH_32 < -32768) {
    P_M_DERIVE[T_ALG.E_BH] = (int16_t)0x8000;
} else {
    P_M_DERIVE[T_ALG.E_BH] = UC_16S_EN_16NS((int16_t)L_M_BH_32);
}

```

---

## Interger Overflow:

The	software	counter	internal	to	the	generator	Control	units	(GCUs)	will	overflow	after	248	days	of continuous	power,	causing	that	GCU	to	go	into	failsafe	mode... resulting	in	a	loss	of	all	AC	
electrical	power	regardless	of	flight	phase

![bg right:50% 100%](../../figures/boeing787.jpeg)

<div style="font-size:12px">

[https://s3.amazonaws.com/public-inspection.federalregister.gov/2015-10066.pdf](https://s3.amazonaws.com/public-inspection.federalregister.gov/2015-10066.pdf)

<p>

---

## Binary to Data, Data to Information

```vbnet
Press Capital A Key
   |
   v
Generate Electrical Signal
   |
   v
Encode Signal into Binary (e.g., 01000001)
   |
   v
Interpret Binary as Data (01000001 -> 65)
   |
   v
Translate Data into Information (e.g., Recognize "A" key press)
   |
   v
Application-Specific Action (e.g., Input "A" in a text editor)

```
---

## Data Input and Data Processing

**Manual Data Input**

- **Definition:** Entering data directly by a user.

<details>
<summary>Examples:</summary>

<div class="grid" style="columns: 2; gap: 8px;">
<div style="font-size:26px; margin-top:20px">

  - Keyboard: Users manually type data using keyboards.
  - Mouse: Interacting with graphical interfaces.
  - Joystick: Relevant in gaming and simulation applications.

</div>
<div>

![](https://nanonets.com/blog/content/images/2021/12/giphy--6-.gif)

</div>
</div>

---
## Automatic Data Input through Sensors

- **Definition:** Gathering data automatically through sensors.

<details>
<summary>Examples:</summary>

<div class="grid" style="columns: 2; gap: 8px;">
<div style="font-size:26px; margin-top:50px">

  - Accelerometers: Used in laptops for tilt detection.
  - Gyroscopes: Essential in navigation systems.
  - Temperature sensors: Applied in environmental monitoring on ships.

</div>
<div>

![w:500](https://bearprocess.com/assets/IMUvis/imu-vis.gif)

</div>
</div>

---

## Integration of Input Methods

Discuss scenarios where a combination of input methods is beneficial.

<details>
<summary>Example...</summary>

<div class="grid" style="columns: 2; gap: 8px;">
<div style="font-size:26px; margin-top:50px">

Using manual input for calibration and automatic sensing for continuous monitoring on a ship.

</div>
<div>

![w:600](https://www.mdpi.com/sensors/sensors-19-04480/article_deploy/html/images/sensors-19-04480-g002.png)

</div>
</div>

</summary>

---

## Challenges in Data Input

What challenges?

<details>
<summary>Examples</summary>

<div class="grid" style="columns: 2; gap: 8px;">
<div style="font-size:26px; margin-top:20px">

- Data Validation, Error Checking
- Redunancy Checks/sensors, Back ups
- Real-time Monitoring and Feedback
- Data Encryption and Security Measures

- Scalability and Performance Optimisation
- User Training and Documentation
- Regular Maintenance and Updates
- Collaboration and Communication
- Adaptability to Changing Environments

</div>
<div>



</div>
</div>

</summary>

---

## Data Processing PT1

![](../../figures/DataProcessing.gif)


--- 

## Data Processing PT2

![](../../figures/DataProcessing2.gif)
