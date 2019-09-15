---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
---
# Day Five Notes

## Outline

1. Sampling Distributions
2. Binomial Setting and Sampling Distribution

## Sampling Distributions

![Illustration of bias and variance](assets/bias_variability_versus){width=50%}

Generally in science we have \underline{low bias and high variability.}

### Joke

**A physicist, a biologist and a statistician go hunting:**

They are hiding together in the bushes and they see a deer 70ft ahead of them. The physicist makes some calculations, aims and fires at the deer. His shot ends up 5ft to the left of the deer. The biologist analyzes the deer's movement, aims and fires. His shot ends up 5ft to the right of the deer. The statistician drops his rifle and happily shouts, "WE GOT IT!!"

\newpage

In MATH-338, we \underline{assume} our sample is generated using \underline{random sampling} methods (\underline{simple random sampling})

- All samples of size `N` are equally likely

If we do \underline{not} use good sampling methods:

- Probability distribution of sample changes $\rightarrow$ introduces bias

Sampling distribution depends on statistic & \underline{sample size}

- For very large populations (~ 20x sample size)
- Sampling distribution does \underline{NOT} depend on population size

Variability of sampling size $\downarrow$ as the sample size $\uparrow$.

\par\noindent\rule{\textwidth}{0.4pt}

Bias of sampling distribution << Bias introduced by bad sampling/study design

Variability  of sampling distribution << Variability due to bad sampling/study design

\newpage


## Binomial (Probability) Distribution

Describe the number of "success" in `N` trials in the \underline{binomial setting}

### Four Conditions

\underline{B}inary outcomes:

- All outcomes are classified either \underline{success} or \underline{failure}

\underline{I}ndependent outcomes: (hand waved by good study design)

- The previous outcome does not influence the next outcome (flipping a coin, gender of a baby).

\underline{N}umber of outcomes = `N`

- Fixed sample size/number of trials
- Known in advance before any outcomes observed

\underline{S}uccess is equally likely for each case/on each trial

- P = Probability of success = population probability of success 
- the pass/fail rate of a class is 90/10, everyone is equally likely to fit these odds

### Situations

- N term is violated : World Series games. A minimum four games is played but there is no fixed amount of games played
- I term is violated : teams who play away games vs home games

\newpage

## Binomial Random Variable

Let X = count(number) of success in a set of `N` outcomes obtained in the binomial setting

X has a PMF defined by:

$P(X=x) = {n \choose x}P\textsuperscript{x}(1-P)\textsuperscript{n-x}$

- $n(x) = \frac{n!}{x!(n-x)!}$
	- Number of ways to get x success and n-x failures out of N trials
- probability of getting exactly x success
- Probability of getting n-x failures

Shorthand to: \hl{$X\sim B(n,p)$}

![Explanation](assets/binomial_random_variable)

\newpage

## Example One

Toss a fair coin 8 times and let X = number of heads

Is X a binomial random variable?

- B: \checkmark success = heads
- I: \checkmark
- N: \checkmark n=8
- S: \checkmark p=0.5

\hl{$X\sim B(8,0.5)$}

\newpage

## Mean and Variance of a Binomial Random Variable

Consider the \underline{Bernoulli} random variable:

```
X = {
	1: if outcome is success
	0: if outcome is failure
}
```

If p = probability of success, then:

$\mu\textsubscript{x} = 1 * P + 0(1-P) = P$

Binomial random variable is sum of `N` independent Bernoulli random variables

So if mean of binomial random variable = \hl{$P+P+P...+P = nP$} (n number of times)

Variance of Bernoulli random variable = 

\hl{$(1-P)\textsuperscript{2}P + (0-P)\textsuperscript{2}(1-P) = P(1-P)$}

When X = 1 and X = 0 respectively $\uparrow$

$\Sigma(X-\mu)\textsuperscript{2}P(X=x)$
$(1-\mu)\textsuperscript{2}P(X=1)$

Variance of binomial random variable = 

\hl{$P(1-P)+P(1-P)+...+P(1-P) = nP(1-P)$ (n number of times)}

Standard deviation if binomial random variable = \hl{$\sqrt{nP(1-P)}$}

\newpage


## Example Two (Question)

Sample of 2000 men get Gemfibrazil

Sample of 2000 men get some other drug (placebo)

It was assumed that 4% of men of the placebo group age get heart attacks (without drug intervention)

Looking at just placebo group:

- Define success, failure, `N`, `P` in this binomial setting
- Find mean, variance, and standard deviation of number of heart attacks the placebo group would experience.

### Example Two (Answers)

**Formulas used from section: Mean and Variance of a Binomial Random Variable**

#### 1

- Success is someone getting a heart attack
- Failure is someone not getting a heart attack
- 2000 is `N`
- 0.04 is `P`

#### 2

- Mean: 80
- Variance: 76.8
- Standard deviation: 8.76356092

\newpage

## Distribution of Sample Proportion

\hl{$\hat{P} = \frac{X}{n}$}

We have no idea how to estimate the number of successes in a very large population

\underline{Proportions} are restricted to $[0,1]$

Sample proportion and population proportion are on the same scale

$E[\hat{P}] = E[\frac{X}{n * X}] = \frac{X}{n} * E[X]$

If $X\sim B(n,P)$ then \hl{$E[X] = \mu\textsubscript{x} = nP$}

$E[\hat{P}] = \frac{X}{n}(n-P) = P$

$\hat{P}$ is an \underline{unbiased estimator} of P

Variance($\hat{P}$) = $V(\frac{1}{n} * X) = (\frac{1}{n})\textsuperscript{2} V(x)$

If $X\sim B(n,P)$ then $V(x) = nP(1-P)$

\hl{$V(\hat{P}) = (\frac{1}{n})\textsuperscript{2}(nP(1-P)) = \frac{P(1-P)}{n}$}

\hl{$SD(\hat{P}) = \sqrt{\frac{P(1-P)}{n}}$}

## Probability Problems involving p hat

$\hat{P}$ does \underline{NOT} have a binomial distribution

However we can convert $X=n * \hat{P}$ and X has a binomial distribution
