# Worksheet 6

1. SIGFAULT: a type of page fault but usually happens when you have a bad pointer. It is also a software interrupt and is an exception.
2. divide by zero, which is an example of a program exception.
3. Typing on the keyboard, moving the mouse pointer, pressing the track pad. Anything that takes away the attention of the processor's main tasks
4. Operating system code runs at 0, which in Linux is considered to be root and is stored in $EUID
5. ISR: Interrupt Service Routine
6. The processor saves the current RIP register, the loads the appropriate ISR address into the RIP register to begin executing the ISR
7. Context
8. Difference:
	- FILH (first level interrupt handler): saves the context of the processor (state of things happening in the processor when the interrupt is issued)
	- SILH (second level interrupt handler): finds what type of interrupt, such as a disk drive interrupt needing to schedule another type of request (I/O). Consults the IDT.
9. Polling: when the CPU is waiting and checking for all the hardware of the availability of any request. Spends wasted time waiting/checking for something to happen.
10. System Timer: provides a constant “tick” interrupt periodically
11. It would be very taxing on the CPU if there are many interrupts a second, it would be better to toggle between using polling and other methods rather than constantly interrupting. Network devices use polling to handle all the overhead of many packets transmitted to the computer.
