---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
---

# Day 8

## Outline

1. A History Lesson
2. Neyman-Pearson Hypothesis Testing

## History Lesson

### Major Players

- Karl Pearson
- Egon Pearson
- Jerzy Neyman
- Ronald Fisher

\newpage

## Neyman-Pearson Hypothesis Testing

\hl{TL;DR version}

1. Define a boundary used to inform a decision
2. Obtain data and see which side of the boundary it falls on
3. Make decision

### Example

We have a coin and it is weighted \underline{but} we don't know if it's weighted to be 60% heads or 60% tails.

Define a parameter to describe the situation

Let `P` represent probability of getting heads ("population proportion of heads")

Define two competing "hypothesis" involving the parameter.

(heads)

- H\textsubscript{0} : `P = 0.6` [\hl{null hypothesis}: "nothing unexpected"]
- H\textsubscript{1} : `P = 0.4` [\hl{alternative hypothesis}: "something is happening, we should change our minds"]

Define a "\underline{critical region}" based on our sample data

1. Define a test statistic `T` whose value can be computed from the sample data
2. Define the sampling distribution of `T` under H\textsubscript{0} and H\textsubscript{1}
3. Based on the sampling distribution under H\textsubscript{0}, define:
	- $\alpha = P(we\, claim\, H\textsubscript{1}\, is\, true | H\textsubscript{0}\, is\, true)$
	and find the region in the sampling distribution under H\textsubscript{0} corresponding to that $\alpha$ value.
4. If the observed value of `T` is in that region, conclude H\textsubscript{1} is true. Otherwise, conclude H\textsubscript{0} is true

### Example

Our decision rule:

- If we get 4 or fewer heads in 10 flips: conclude H\textsubscript{1} is true.
- If more than 4 heads in 10 flips: conclude H\textsubscript{0} is true.

"Critical region": Let $X = number\, of\, heads\, in\, 10\, flips$

- $X \le 4$

\newpage

\underline{Recall}:

<div style="text-align:center">![Two Way Table](assets/two_way_table){width=30%}</div>

Now apply this to Neyman-Pearson rules:

<div style="text-align:center">![Neyman-Pearson Two Way Table](assets/neyman_pearson_two_way){width=40%}</div>

## Under N-P Rules

Type 1 Error is "worse" than Type 2 Error.
However, if P(Type 1 Error) is too low, P(Type 2 Error) balloons.

$\alpha = P(1)$
- P(Concluded H\textsubscript{1} | H\textsubscript{0} is true)

$\beta = P(2)$
- P(Concluded H\textsubscript{0} | H\textsubscript{1} is true)

\underline{Power} of test = $1 - \beta$

- `=` P(concluded H\textsubscript{1} | H\textsubscript{1} is true)

\newpage

## Example

Let $X = number\, of\, heads\, in \, 10\, flips$

- Under H\textsubscript{0}: $X\, \sim B(10, 0.6)$
- Under H\textsubscript{1}: $X\, \sim B(10, 0.4)$

For critical region X $\le$ 4:

- $\alpha = P(X\, \le 4 \, |\, p = 0.6) = 0.166$
- $\beta = P(X > \, |\, p = 0.4) = 0.367$

Power = $P(X\, \le 4 \, | \, p = 0.4) = 0.633$

Traditionally, set $\alpha = 0.05$ or $\alpha = 0.01$

Find the critical region giving a Type 1 Error rate of at most $\alpha$

(Find x such that P(X $\le$ x | H\textsubscript{0} is true) $\le \alpha$)

P(x $\le 2$ | H\textsubscript{0} is true) = 0.0123

P(X $\le 3$ | H\textsubscript{0} is true) = 0.0548

Critical region corresponding to $\alpha = 0.05$: $x \le 2$

What is $\beta$ for this critical region? 

$\beta = P(x > 2 | p = 0.4) = 0.833$

In most fields, we use \underline{power} instead

Power = $P(X \le 2 | p = 0.4) = 0.167$

\newpage

## Rules of thumb

1. $\alpha < \beta$. If $\alpha \le \beta$, either decrease $\alpha$ or switch H\textsubscript{0} or H\textsubscript{1}
2. At your "given" $\alpha$ value, $\beta \le 2$ or equivalently, power $\ge 0.8$ (80% power). If power < 0.8, plan to collect more data!

## In Practice

1. The idea of "nothing weird happening" should \underline{give us} the value of the parameter.
2. We define a clinically signifiant/practically signifiant difference in parameter values ("minimum effect size")

## What we need at each step

1. To compute the critical region:

- need $\alpha$, H\textsubscript{0} (value of P under H\textsubscript{0})
- sampling distribution of test statistic under H\textsubscript{0}

2. To compute power:

- need critical region, H\textsubscript{1} (value of P under H\textsubscript{1})
- sampling distribution of test statistic under H\textsubscript{1}
