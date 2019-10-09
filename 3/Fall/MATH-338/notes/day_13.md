---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
---

# Day 13 (Review Session)

## Problem Solving Methodology

1. What problems look like
2. What info to look for
3. How to solve them


\newpage

## Independent vs. Disjoint

### Are A and B Disjoint

\underline{Looks like:} define two events

\underline{Looking for:}

- P(A)
- P(B)
- P(A $\cap$ B)

\underline{Check:} Is P(A $\cap$ B) = 0

If yes $\rightarrow$ disjoint

If no $\rightarrow$ not disjoint

### Are A and B independent

\underline{Looking for:}

- P(A)
- P(B)
- P(A $\cap$ B)

Find \underline{ONE OF} the following comparisons:

Is P(A $\cap$ B) = P(A)P(B)

If yes $\rightarrow$ independent

If no $\rightarrow$ dependent

Is P(B | A) = P(B)?

- P(B|A) = $\frac{P(A \cap B)}{P(A)}$

### Event vs Probability

- \textbf{Event:} an actual thing that could happen or not
	- Example: the dog will go to the right place
- \textbf{Probability:} a number between 0-1 assigned to the "chance" of an event
	- Example: The dog has a 50% chance of going to the right bowl

\newpage

### Example

Problem: 3 lights, independently red/green

If red $\rightarrow$ 2 minutes

10 minutes to get to work

All green $\rightarrow$ 8 minutes

P(A) = 0.6
P(B) = 0.4
P(C) = 0.9

A $\rightarrow$ Light 1 is red
B $\rightarrow$ Light 2 is red
C $\rightarrow$ Light 3 is red

\underline{Goal:} Find the probability of not being late to work

Employee is not late \underline{\underline{if:}}

- all green
- one light is red

P(not late) = P(all green) + P(one red)

all green = {$(A^c, B^c, C^c)$} **he hits no red lights**

one red = {$(A, B^c, C^c)$, $(A^c,B, C^c)$, $(A^c, B^c, C)$} **he hits at most one light**

all green = P({$(A^c, B^c, C^c)$})

= P($A^c$)P($B^c$)P($C^c$)

= (0.4)(0.6)(0.1)

= 0.024

*finish from picture*


\newpage


## Conditional Probability/Bayes' Rule

\underline{Given:} two conditional probabilities/proportions \hl{$P(B|A), P(B|A^c)$}

One unconditional probability/proportions (prevalence/base rate) \hl{P(A)}

\underline{Goal:} Find a different conditional probability \hl{P(A|B)}

P(A|B) = $\frac{P \cap B}{P(B)}$

*Does not matter which method used of two way table and tree diagram*


