---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
toc: true
---

# Day 21

\newpage

# ANOVA $\rightarrow$ Analysis of VAriance

\underline{\textbf{THE}} classic Fisher test.

\underline{Model:} $y \sim N(\mu, \sigma)$

- $\mu$ and $\sigma$ are unknown.
- $\mu$ may not be the same for all data points
- $\sigma$ is assumed same for all data points

In one-way ANOVA:

- \underline{Data:} one numerical response variable `y` and one categorical explanatory variable whose values are the "groups".
- We need $\ge 2$ groups

\underline{Example situations where we use it:}

- Compare control group to $> 1$ treatment group
- Observational study comparing 3 or more groups/populations

## Use cases

- \underline{Between-group effects:} variation due to changes in $\mu$
- \underline{Within-group effects:} variation due to individual differences

## Notation

- $\bar{y} =$ grand mean or the mean of all data in the \underline{whole} sample.
- $N =$ total sample size
- $I =$ number of groups
- $\bar{y}\textsubscript{i} =$ sample mean in group `i`
- $s\textsubscript{i} =$ sample standard deviation in group `i`
- $n\textsubscript{i} =$ sample size in group `i`
- $y\textsubscript{ij} =$ value of y for the j\textsuperscript{th} case in group `i`.

\newpage

## Hypothesis Testing

H\textsubscript{0}: $\mu\textsubscript{1} = \mu\textsubscript{2} = ... = \mu\textsubscript{I}$

- All the population means are equal $\implies$ no effect of group on response.
- Under H\textsubscript{0}, $y\textsubscript{ij} \sim N(\mu, \sigma)$
- Also: $\bar{y}\textsubscript{i} \sim N(\mu, \frac{\sigma}{\sqrt{n\textsubscript{i}}})$
- $\mu ,  \sigma$ are fixed but unknown

H\textsubscript{a}: \underline{not} H\textsubscript{0} \hl{[not really necessary because this is Fisher framework]}

- $\implies$ effect of group on response

### Implicit Assumptions of Model

- Normal population distribution
- $\sigma$ is the same for all groups \hl{[not as critical]}
    - robust to violations of this assumption as long as the largest $s\textsubscript{i} < 2\,  \times$ smallest $s\textsubscript{i}$

Under H\textsubscript{0}:

- $F\ sim F(DFG, \, DFE)$
- Think of `F` like $\chi^2$
- t and F are linked
- $N(0,1)$ and $\chi^2 are linked$

- If p-value $\le$ significance level, reject H\textsubscript{0} and claim the population means are \underline{not} all equal
- Do \underline{posthoc procedures} to figure out \underline{which} measure different & how different they are.
- If p-value > significance level, we fail to reject the hypothesis we did not \underline{prove} a difference /an effect.
