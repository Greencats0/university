---
headers-include: |
	\usepackage{textgreek}
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
---

# Day 2

# Outline

1. Recap of probability
2. Simulation
3. Random Variables

# Independent vs. Disjoint Events

- Independent events __can__ happen at the same time, but knowing that event "A" occurred **does not** change P(B) and vice versa
- Disjoint events cannot happen at the same time.
	- Knowing that event "A" occurred changed P(B) = 0 and vice versa
- If A and B are independent, P(A $\cap$ B) = P(A) P(B)
- If A and B are disjoint, P(A $\cap$ B) = 0

## Example One

- Draw a tile from a bag of 100 scrabble tiles
- Event C = "the tile is a C"
- Event A = "the tile is an A"

P(C) = .02

P(A) = .09

Events "C" and "A" are disjoint

Events "C" and "A" are \underline{not} independent

## Example Two

Draw one tile and set it outside

Event C = "first tile is a C"

Event A = "second tile is a A"

Event C and A are not disjoint

Events "C" and "A" are \underline{not} independent

**Sampling without replacement**

## Example Three

Draw a tile, put it back in the bag and then draw another tile

Event C = "first tile is a C"
Event A = "second tile is an A"

Event C and A are \underline{not} disjoint
Event C and A \underline{are} independent

**Sampling with replacement**

# Simulation

Trying to imitate in the real world where the outcome is uncertain but is random

- Specify our \underline{model} for an uncertain situation/random event
- "Randomly" generate an outcome for the model
- Repeat step two many, many times

## Why simulate?

- Once we set up the model, the math maybe too difficult
- Situation may be unique, or we only have ability to observe it once, due to physical/financial limitations
- For fun and/or profit

Report \underline{assumptions} of the model!

# Random Variables (RVs)

Random variable is a variable whose numerical values describe outcomes of a random event

Typically we map outcomes in our sample space denoted as "S" to numerical values of the random variable.

\underline{Discrete Random Variable} :  probability mass function (PMF) places positive probability at specific numbers on the number line

- Only specific numbers
- Example: all outcomes are real, positive numbers

\underline{Continuous Random Variable} : probability density function (PDF)

- Places positive probability along a possibly infinite interval of the number line.

\newpage

## Writing the PMF of a Discrete Random Variable

Each unique key value X=x is mapped to an non unique value P(X=x)

```
example_hash_map = {
	key: value
}
```
A hash table is another way to represent data mapping.

- value represents a random variable
- key represents a "realization" of value

## Example One

We can find P(Y=0)

Once we have observed the random event either y = 0 or y != 0

Let X = the point value of the chosen tile


```
map = {
	0: 0.02,
	1: 0.68,
	2: 0.07,
	3: 0.08,
	4: 0.10,
	5: 0.01,
	8: 0.02,
	10: 0.02
}
```

Sum of values in map == 0

\newpage

## Example Two

Use PMF & probability rules to find:

- P(X <= 3)
	- P(X = 0, 1, 2 or 3)
	- P(X = 0) + P(X = 1) + P(X = 2) + P(X = 3)
	- = 0.85
- P(X > 1)
	- P(X = 2, 3, 4, 5, 8, or 10)
	- 1 - P(X <= 1) = 1 - (X = 0 or 1)
	- 1 - [P(X = 0) + P(X = 1)] = 1 - [0.02 + 0.68] = 1 - .7 = 0.3

- P(X > 5)
	- P(X = {0..5})
	- 0.04
- P(3 < x <= 5)
	- 0.11
	- P(X = 4, or 5)

\newpage

# Expected Value (Mean) of a Random Variable

- Called expectation, mean, all the same thing
- On \underline{average}, what value do we expect the random variable to be

Recall idea of "weighted average"

## Mean of a Probability Distribution

\underline{\textmu}

Denotes the average of all events, which in turn gives us an expected value for a given function.

## Summation notation

![discrete random variable formula](assets/mean_of_discrete_random)

Expected value is a \underline{linear} operator (can take in sum and give back a result in the form of a sum of the applied operators)

## For random variables X and Y, and constant C

- E[X+Y] = E[X] + E[Y]
- E[cX] = cE[X]
- ^ where "c" is a constant applied

This implies, for X, Y and arbitrary constants a,b E[aX + bY] = aE[X] + bE[Y]

Consequences: a = 1 , b = -1

E[X - Y] = E[X] - E[Y]

\textmu\textsubscript{x-y} = \textmu\textsubscript{x} - \textmu\textsubscript{y}
