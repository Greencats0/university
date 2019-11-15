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

## Why ANOVA?

We want to compare the means of more than two populations and our previous methods of analysis have been limiting.

\underline{Example:} we want to compare three samples to see if a difference exists somewhere between those groups. Each of them have their own sampling distributions and other characteristics.

\underline{Question to ask yourself:} Do all three of these means come from a common population. 

This type of test takes in $n$ amount of distributions and then distributes them along a unifying curve. We can then see where those distributions lie on the bigger distribution. 

![ANOVA Distribution Close to Mean](assets/anova_dist){width=40%}

![ANOVA Distribution Far from Mean](assets/anova_dist_far){width=40%}

Mean is in a different location relative to the overall mean of the populations. This might conclude that it is not apart of the common population.

Null Hypothesis: $H\textsubscript{0}: \mu\textsubscript{1} = \mu\textsubscript{2} = \mu\textsubscript{3}$

$\implies$ All the samples come from the same population. We are not asking if they are EXACTLY equal. We are asking if each mean likely came from the larger overall population. Variability AMONG/BETWEEN the sample means ($\bar{x}\textsubscript{i}$)

\newpage

## Comparing Analysis Methodology

The problem with running the individual tests on each respective sampling distribution, we run into some issues:

- All three t-tests have $\alpha = 0.05 \therefore$ the all compound
   - This makes the confidence of decrease to $0.95 \times 0.95 \times 0.95 = 0.857$
   - Recall that this is the confidence level or $\beta$
- Our new $\alpha$ value need to reflect as such: $\alpha = 1 - 0.857 = 0.143$

![Multiple t-Test Chart](assets/anova_multiple_test_example){width=75%}

This is why we do not do this, the error rate goes $\uparrow$.

## Variability Ratio

ANOVA: Analysis of Variance is \emph{variability} ratio.

This can be seen in the following figure:

![Variability Ratio Visual Example](assets/anova_var_ratio_visual){width=50%}

\begin{large}
$\frac{\text{Variance Between}}{\text{Variance Within}}$
\end{large}

\newpage

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

ANOVA tests \underline{\textbf{CANNOT}} determine/make conclusions about all populations means ($\forall$), only at least one element in the set ($\mu \in \forall$)

\newpage

#### Homework Example

![ANOVA Example Problem](assets/anova_example_problem){width=60%}

- $k = 4$
- $n = 20$
- $\alpha = 0.01$
- P-Value $= 0.002$
- H\textsubscript{0}: the shrubs are in the same species ($\mu\textsubscript{1} = \mu\textsubscript{2} = \mu\textsubscript{3} = \mu\textsubscript{4}$)
- H\textsubscript{1}: the shrubs are \underline{not} in the same species ($\mu\textsubscript{1} \ne \mu\textsubscript{2} \ne \mu\textsubscript{3} \ne \mu\textsubscript{4}$)

The decision to \underline{reject} the \underline{null hypothesis} at a significance level of $\alpha = 0.01$.
There is \underline{sufficient} evidence to conclude that \underline{at least one of the population means} \underline{\underline{different from}} \underline{\underline{\underline{at least one other population mean}}}.

\newpage

## Computing an F-Statistic

$df\textsubscript{1} = \text{Between} \implies k - 1$

$df\textsubscript{2} = \text{Within} \implies n - k$

- n: total number of elements in the sample
- k: number of populations

$$F = \frac{\text{Between}}{\text{Within}}$$

\newpage

# Example [Made Up]

\underline{Four groups:}

\begin{enumerate}
\item $n\textsubscript{1} = 15$
\item $n\textsubscript{2} = 20$
\item $n\textsubscript{3} = 15$
\item $n\textsubscript{4} = 25$
\end{enumerate}

$\uparrow$ F-Stat, $\downarrow$ p-value

![Example Worked in Class](assets/made_up_anova)

Clearly defined groups $\rightarrow \ge 3$ groups

- numerical response variable [\hl{for exam two}]

\newpage

# External Links

- [ANOVA YouTube Lecture](https://www.youtube.com/watch?v=0Vj2V2qRU10)
