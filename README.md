# kurklu_lab2

# Introduction

As part of our joint design course in GE5A at Polytech Clermont, we are required to apply the theoretical knowledge gained during practical work. These tasks are performed on a Terasic DE10-Lite board based on an Altera MAX 10 FPGA. For this second project, our goal is to implement a counter on three 7-segment displays. The counter should display a new value every 1 second, achieved using an interrupt on a timer.

# Architecture
Here is the architecture I created using Paint:

![lab2](https://user-images.githubusercontent.com/24780090/211839652-f88ff0c1-7246-49c2-b8b6-950c2bf19ab3.jpg)

First, I included the components to rebuild my basic system:
* A clock
* A RAM
* A NIOS-2
* A JTAG

Then, I added PIOs to manage my I/O:
* A 4-bit PIO for segment 1
* A 4-bit PIO for segment 2
* A 4-bit PIO for segment 3
* A TIMER

Here is the system initialized in Qsys:

![lab2_qsys](https://user-images.githubusercontent.com/24780090/211839872-e2330fc6-c873-4232-878d-f696c17ae4e7.jpg)

# Progress

First, I wrote the "bin_to_7seg.vhd" file to perform the translation of a number into 7 segments. For the translation, I simply created a truth table using "when-else" statements.

## Polling Counter
Next, I performed the necessary steps to compile my system in Quartus (VHDL creation, components, pin assignments, etc.). In the software part, I wrote a simple for loop to display the numbers from 0 to 9 on a single segment using polling. Once this step was validated, I added three nested for loops to display the numbers on all three 7-segment displays. The code can be found in the "polling.c" file.

[Video link for polling counter demonstration](https://user-images.githubusercontent.com/24780090/211843099-4f6160b2-aeac-4aea-9bee-a2d28c4c9b7c.mov)

## Timer Counter
In this part, I added a timer to my Qsys design and set it with a period of 1 second. First, I tested if the interrupt was working by registering the interrupt, creating the "timer_interrupt()" function to handle the interrupt, and running the execution with "alt_printf()" for debugging purposes. I noticed that I only entered the "timer_interrupt()" once. By referring to the timer documentation, I checked the CONTROL and STATUS registers, and at the end of the "timer_interrupt()", I noticed that the TO bit of the register did not return to 0. After correcting this, I successfully entered the interrupt every 1 second. Finally, I implemented the counter within the interrupt, which can be found in the "main.c" file.

[Video link for timer counter demonstration](https://user-images.githubusercontent.com/24780090/211845285-f251671e-e3e1-4b9d-b263-c7e8c17521c6.mov)

# Conclusion

I successfully completed lab2 without major difficulty and in less time than lab1. This second practical work allowed me to use timers and understand their functioning. In the first lab, I spent a lot of time on the interrupt. For this lab, I directly consulted the documentation to ensure that all registers behaved correctly. However, at the beginning of

 the practical work, I needed some time to think about how to make the connections, but once the system architecture was drawn, it greatly helped me.