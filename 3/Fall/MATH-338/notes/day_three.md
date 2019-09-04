---
headers-include: |
	\usepackage{textgreek}
---

# Outline

1. Expected value of the random variable
2. Variance and standard deviation of random variable
3. [If time allows] 


## Expected values (mean)

Please refer to day_two.pdf

## Law of Large Numbers

Suppose we have "N" \underline{independent} and \underline{identically distributed} (IID) realization of "X".

That is, we observe out random event "N" times \underline{independently} and record the value of "X".

Then, as "N" increases, the sample mean of the "N" independent observations converges to \textmu\textsubscript{x}

We can get \underline{arbitrarily close} to \textmu by simply observing values of "X" enough times.

\newpage

## Variance of a Random Variable

Average squared deviance from mean (distance away from the middle)

![variance formula](assets/variance)

- Variance is \underline{non-negative}
- Variance is \underline{not} a linear operator

In general, Var(X+Y) != Var(X) + Var(Y)

\underline{However}, if X and Y are \underline{independent}

Var(X+Y) == Var(X) + Var(Y)

Var(cX) != cVar(X)

\underline{However!} --> Var(cX) == \underline{C\textsuperscript{2}}Var(X)

When X and Y are independent,

Var(aX+bY) = a\textsuperscript{2}sigma\textsuperscript{2}\textsubscript{x} + b\textsuperscript{2}sigma\textsuperscript{2}\textsubscript{y}

## Standard Deviation of Random Variable

sigma\textsubscript{x} = $\sqrt{sigma\textsubscript{x}}$

Standard deviation is \underline{not} linear


sigma\textsubscript{x+y} = $\sqrt{sigma\textsubscript{x}+sigma\textsubscript{y}}$

If X and Y are independent

sigma\textsubscript{cx} = |C|sigma\textsubscript{x}

\newpage

## Adding a constant

Consider W = X + c (where c is an arbitrary constant)

E[W] = E[X+c] = E[X] + E[c]

E(W) = E(X) + c

Var(W) = Var(X+c)

= Var(X) + Var(c)

Var(c) = 0

Var(W) = Var(x)

SD(W) = SD(X)

## Example One

- Toss two fair coins.
- Let X be the number of heads observed
- Find the PMF, expected value, variance and standard deviation of X.

Each win is independent

P(Heads) = 1/2

Independence: P(A $\cap$ B) = P(A) * P(B)
0 heads: TT => P(TT) = P(T\textsubscript{1}) * P(T\textsubscript{2}) = 1/2 * 1/2 = 1/4
1 heads: HT
	 TH
2 heads: HH

### Easy Way

1. Find the PMF and write as a table
2. Expand our table by adding columns
3. Add down each column

```
# key is X=x
# value is P(X=x)
# --> points to xP(X=x)
# ---> points to variance 
map = {
	0: 0.25 --> 0 ---> 0.25
	1: 0.50 --> 0.5 ---> 0
	2: 0.25 --> 0.5 ---> 0.25
}

```
summation of P(X=x) = 1

summation of xP(X=x) \textmu\textsubscript{x} = 1 

summation of variance sigma\textsuperscript{2}\textsubscript{x} = 0.5

summation of standard deviation of X ~= 0.7


## Example Two

You enter a lottery in which there is a 1 in 1000 chance of winning.
If you win, you get $500 and if you don't you get nothing
Let Y be the amount of money you win.

Find the PMF, expected value, variance and standard deviation


```
map = {
	0:   0.999 -------> 0 ----> 0
	500: 0.001 ---> 0.5 --> 250 ---> 15.811
}
```
expected value: 0 and 500

## Example Two (With a twist)

You enter a lottery in which there is a 1 in 1000 chance of winning.
If you win, you get $500 and if you don't you get nothing
Let Y be the amount of money you win.

Let V = amount of money you have after the lottery

Find the PMF, expected value, variance and standard deviation

E[V] = E[Y-1] = E[Y] - 1 = 0.5 - 1 = -0.5
Var(V) = Var(Y-1) = Var(Y) = 249.75
SD(V) = SD(Y) = 15.8

## Relationship Between Probability and Statistics

Let our random event be:

Pick one person at random and record some characteristics of the individual


The individual we record is the \underline{case} or \underline{unit}

The characteristics we record are called \underline{variables}

The set of all cases of interest: \underline{population}

