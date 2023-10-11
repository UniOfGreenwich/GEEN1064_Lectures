---
title: Programming and Flow Diagrams
description: Programming and Flow Diagrams
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
    .columns {
      display: grid;
      grid-template-columns: repeat(3, minmax(0, 1fr));
      gap: 1rem;
    }

size: 16:9
paginate: true
_paginate: false
marp: true
math: true
---

# Programming and Flow Diagrams

    Course Code: GEEN1064 
    
    Course Name: Engineering, Design and Implementation

    Credits: 20

    Lecturer: Seb Blair BEng(H) PGCAP MIET MIHEEM FHEA

---

![bg center 35%](https://imgs.xkcd.com/comics/good_code.png)

---

## What is programming?

<details>
<summary>?</summary>

A programming language is a computer language programmers use to develop software programs, scripts, or other sets of instructions for computers to execute​...

</details>


<details>
<summary>Why program?​</summary>

Automate process​, Create digital records​, Communication ,Simulation/emulation​, …​

But ultimately programming provides instructions on how hardware is controlled, remember at the end of the day it is all zeroes and ones that represent electrical signals.​

</details>

---

## Types of Programming Languages

- High Level / low level – C#, Java, Python, Ruby, C, C++, assembly ​

- Declarative / imperative/procedural – SQL, Curl, Prolog​

- General-purpose/domain specific – HTML, Markdown/up, MATLAB​

- Object-orientated/concurrent – C#, Java, Python,​

- Command/complied/script language – batch, bash, Javascript​

- Answer set - Prolog

---

## Human Language and Programming Languages


<details>

<summary>Are all programming languages in English?​</summary>

No, but the vast majority are because they are the most used.​

</details>


<details>

<summary>Does it matter when these are compiled down to machine code?​</summary>

No, because it’s all ones and zeroes​

</details>

---

## Some Examples of Non-English Programming Languages


**Linotte​**
It has been a developer for using French keywords, and its “Hello world” program looks like this:​

```vb
BonjourLeMonde:​
  début​
    affiche "Bonjour le monde!"​
```

Has a web engine for HTML and PHP and JSP. 

---

**SAKO​**
System Automatycznego Kodowania Operacji (Automatic Operation Encoding System) programming language, which uses polish as for its keywords:​

```
K) PROGRAM DRUKUJE NAPIS HELLO WORLD​

   LINIA​

   TEKST:​

   HELLO WORLD​

   KONIEC​
```

Really only used in the late 1950s and early 1960s for the XYZ computers.

---

**Rapira​**

Rapira is another awesome example of non-english programming languages. It uses Russian keywords:​

```
ПРОЦ СТАРТ()​

    ВЫВОД: 'Привет, мир!'​

КОН ПРОЦ​
```
**Translated:**
```
proc start()
     output: 'Hello, world!!!';
end proc
```

---

**EPL**​

Chinese engineers developed 易语言 (Easy Programming Language, as known as EPL):​

```
公开 类 启动类​
{​
  公开 静态 启动()​
  {​
    控制台.输出("你好，世界！");​
  }​
}​

public class startup class​
{
  public static start()
  {
    console.output("Hello, World!");
  }
}
```
---

## Learning to Program

You do not need to know how to program in all languages, ​you only need to know how to program.​

- Conditions​
  - if, else if , else​
  - switch​

- Loops​
  - for​
  - while
  - do​

---

## Pseudo Code

So before programming actual code you should write in pseudocode;

Are you older enough to take a driving test?​

```ps
BEGIN​
  NUMBER age​

  INPUT "Enter your age for driving licence"​
  
  OUTPUT age​

  IF age>=16  THEN​
      OUTPUT "You can take driving licence"​
  ELSE​
    OUTPUT "You can't take driving licence"​
  ENDIF
  ​
END​
```
---

##  Conditional Checks

<table align=center>
<tr>
<td>
C

```c
a = 200;​
b = 33;​
if (b > a)​
{​
 print("b is greater than a");​
}​
else​
{​
  print("b is not greater than a");​
}​
```
</td>
<td>

Python
```py
a = 200​
b = 33​
if b > a:​
  print("b is greater than a")​
else:​
  print("b is not greater than a")​
```
</td>

<td>

Matlab

```matlab
a = 200​
b = 33​
if (b > a)​
 print("b is greater than a")​
else​
  print("b is not greater than a")​
end​
```

</td>
</tr>
</table>

---

## `If` Flow Diagram

![bg right:52% 100%](../../figures/ifflowdiagram.png)


```
if(condition1)​
{  ​
  //code for if condition1 is true  ​
}​
else if(condition2)​
{  ​
  //code for if condition2 is true  ​
}  ​
else if(condition3)​
{  ​
  //code for if condition3 is true  ​
}  ​
...  ​
else​
{  ​
  //code for all the false conditions   ​
}​
```


---

## While Do & Do While Loops


While loops run forever until a condition is met, like our iconic duo on the left are demonstrating.​

​
![bg right:50% 100%](../../figures/roadrunner.png)

---

## An Example Looping

Infinite Loop

```c
while (0 < 1)​
{  ​
  print(“Hello World!”);​
}​
```

Finite Loop

```c
int i = 0;​

while (i < 10)​
{  ​
  print(“Hello World!”);​
  i = i + 1;​
}​
```
---

## Flow Diagrams Symbols

![center](../../figures/flowchartsymbols.png)

---

## Mermaid Editor

[https://mermaid-js.github.io/mermaid-live-editor/edit/](https://mermaid-js.github.io/mermaid-live-editor/edit/)

![h:570 center](../../figures/mermaid.png)

---

## Mermaid Exercise

[https://mermaid-js.github.io/mermaid-live-editor/edit/](https://mermaid-js.github.io/mermaid-live-editor/edit/)

So now that we have seen mermaid, write out the flow for a robot to make a hot beverage such as tea.
​
**Remember**​
Computers are not good or bad at a job, it is how well the human programs it.​

---

## Blocky 

[https://blockly.games/?lang=en](https://blockly.games/?lang=en)

![center](../../figures/blockly.png)

---

## Ev3 Spike

- Icon 
- Block
- Python

![bg right: 75% 100% vertical](https://eduk8.gr/wp-content/uploads/2022/02/spike_ess_code.png)

![bg right:75% 75%](https://thecodingfun672211385.files.wordpress.com/2021/01/python-start-line-sensing-part-1.jpg)

---

## Eve Spike block

<div class="columns">

<div>

![](https://bb.ca/catalogue_images/580x358/2499481.png)

</div>

<div>

![](https://i.stack.imgur.com/N4Mbs.jpg)

</div>

<div>

![](https://i.stack.imgur.com/JTXCW.jpg)

</div>

</div>

<!--

 - main CPU is an STM32F413. It includes 1M of flash and 320k of RAM and the ARM Cortex M4 core can be clocked up to 100MHz
 
 - In addition to the 1M of embedded flash, there's a Winbond W25Q256JV providing an additional 32MB for program and data storage.

 - The 6 motor outputs are driven by a trio of LB1836 dual motor drivers.

 - Bluetooth connectivity is provided by the TI CC2564C. (LED SIDE Raised cube)

- source https://bricks.stackexchange.com/questions/15057/what-internal-electronics-do-spike-prime-and-mindstorms-robot-inventor-use



-->

---

## Programming Information for EV3 Spike

$$ T = \frac{1}{f}$$

- T is time
- f is frequency

Ev3 Spike CPU is a STM32F413 and operates at 100MHz on the Arm Cortex M4.

Clock Speed: 
$$ 0.0000001 = \frac{1}{100M}$$

$$ 100ns = \frac{1}{100*10^{6}}$$

Per line of code ($L_c$):
 $$ 400ns = L_c \cdot (4 \cdot 100ns)$$ 

---

## Programming Space

The Winbond W25Q256JV providfes 32MB for a program and data storage.

- EV3 files use the ZIP algorithm, the EV3 file contains a number of compressed files. 
  - An EV3 file contains 6 to 26 files, the average being 9. 
  - EV3 files are between 4 KB and 320 KB in size. T
  - These files are often associated with luuma, robot, guitar, ctric, sensor, color, balancing, printer and code.

Average program size:

  $$2,880,000 = 9 \cdot 320KB$$
  $$2.8MB = 9 \cdot (320 \cdot 10^3)$$

Max program size:

$$8,320,000 = 26 \cdot 320KB$$
$$8.32MB = 26 \cdot (320 \cdot 10^3)$$

<!--
https://filext.com/file-extension/EV

10 small programs
6 medium programs
3 large programs
-->

