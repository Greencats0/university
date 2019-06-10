---
mainfont: ebgaramond
---
# Flip Flops

The purpose of a flip flop is to preserve the data over a duration of time. Ones that are clocked will ignore all of the inputs given until the clock is signaled. 

## Clocks

- Rising Edge: the transition from low to high
- Falling Edge: the transition from high to low

![Clock\ Diagram](assets/Clock\ Diagram.gif)

## Caveat

There is a problem called **metastability** which is when the clock and data line are changed at around the same time, the hardware has a hard time telling which one came first, so there may be undefined behavior that would incur.

\pagebreak


## D Flip Flop

- When E is high (1), Q follows D with Q' the complement of Q
- When E is low (0), the output remains the same (no state change) and D is ignored

- E: Enable
- D: Data
- Q Q' : Output

![D Flip Flop with Truth Table](assets/D\ Flip\ Flop\ Truth\ Table.png){width=50%}

\pagebreak


## D Flip Flop (Clocked)

- Captures the value of the D input at a specific portion of the clock cycle (rising or falling edge)
- **Clock Cycle**: the clock line going high and then low again

![D Latch Diagram](assets/D\ Latch.gif){width=50%}

\pagebreak

## SR Flip Flop

- When both S and R are low, the outputs are in a constant state
- Q and Q' are complementary; when Q is high, Q' is low

![SR Latch](assets/SR\ Latch.gif){width=50%}

![SR Truth Table](assets/SR\ Flip\ Flop\ Truth\ Table.jpg){width=40%}

\pagebreak

## JK Flip Flop

- All state changes are synced to a clock point
	- When J is 1 and K is 0, on the next clock rising edge, Q will go high
	- When K is 1 and J is 0, on the next clock rising edge Q will go low
	- When J and K are both 0, nothing will happen when the clock is pulsed
	- If J and K are 1, no matter the state of Q, it will change to the opposite state (flipping)

![JK Flip Flop Diagram](assets/JK\ Flip\ Flop\ Diagram.png)

\pagebreak

## T Flip Flop

- When T is high, every clock cycle will toggle the outputs

![T Flip Flop Diagram](assets/T\ Flip\ Flop.png)