---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
---

# Day 12

## Outline

1. Computing p-values with software using $\chi^2$ distribution
2. Test of independence
3. Measures of association between two categorical variables

\newpage


# Computing P-Value

Given $\chi^2$

P-Value is always above or equal to degrees of freedom.

<div style="text-align:center">![Changing the degrees of freedom](assets/chi_squared_graph_with_degrees){width=50%}</div>

p __

- interval values $\rightarrow$ probability

q __

- probability $\rightarrow$ values

P-Values = probability of getting our data or data that "disagree" as much or more with our model, if model is correct.

```r
arbitrary_val <- 4.8
pchisq(arbitrary_val, df = 5, lower.tail = FALSE)
```

\newpage

# Test of Independence

What I'm recording: two categorical variables

What I want to know: whether a suspected association between the variables will hold when generalized to the population.

# Test of Homogeneity

What I'm recording: 1 categorical variable in samples form \underline{multiple populations}

What I want to know: Is the variable's distribution the same in all populations?

\textbf{Both tests use data summarised in two-way tables}

We use Fisher's significance testing approach.

Test of independence: we model assuming that the two variables are not actually associated

\underline{H\textsubscript{0}}

- [Variable 1] does not affect [Variable 2]
	- [Variable 1] and [Variable 2] are independent/not associated/ not related

Testing of homogeneity: we model assuming the distribution is the same in every population

- H\textsubscript{0}: the distribution of [variable] is the same in [list of population]

More simply put: H\textsubscript{a}: not H\textsubscript{0}

In test of homogeneity, we consider "population" to be an explanatory variable & run a test of independence

Observed counts = number in sample of each cell of table.

## Example (Book Example 9.12)

![Base Table](assets/book_example_9_12)

Estimated probability of Cardiovascular Disease(CVD) = $\frac{200}{2415}$

If independent (according to chart):

- P(CVD | low salt) = $1169 \times \frac{200}{2415} = 96.81$

- P(CVD | high salt) = $1246 \times \frac{200}{2415} = 103.19$

- P(NO CVD | low salt) = $1169 \times \frac{2215}{2415} = 1072.19$

- P(NO CVD | high salt) = $1246 \times \frac{2215}{2415} = 1142.81$

\newpage

## Pearson Residuals

$\frac{O - E}{\sqrt{E}} \rightarrow$ for each cell

Contribution of a cell to $\chi^2$: residual\textsuperscript{2} = $\frac{(O - E)^2}{E}$

$\chi^2 = \Sigma \frac{(O - E)^2}{E}$


- P(CVD | low salt) = $\frac{88-96.81}{\sqrt{96.81}} = -0.895$

- P(CVD | high salt) = $\frac{112-103.19}{\sqrt{103.19}} = 0.867$

- P(NO CVD | low salt) = $\frac{1081-1072.19}{\sqrt{1072.19}} = 0.269$

- P(NO CVD | high salt) = $\frac{1134-1142.81}{\sqrt{1142.81}} = -0.261$

$\chi^2 = (-0.895)^2 + (0.867)^2 + (0.269)^2 + (-0.261)^2 = 1.69$

*finish second chart from picture*

## To get a P-Value

- Option 1: Our $\chi^2\textsubscript{observed}$ value comes from a $\chi^2$ distribution with degrees of freedom. Find P($\chi^2 \ge \chi^2\textsubscript{observed}$)
- Option 2: Simulate a bunch of samples assuming independence, then find proportion of simulated $\chi^2$ statistic $\ge \chi^2\textsubscript{observed}$

\underline{Fisher:} df (degrees of freedom) = (r - 1)(c -1)

- r: rows
- c: columns

"Sample size assumptions" method (2) \underline{always works} but different people can get different values.

Method 1 always gives some value, \underline{but} that value can be inaccurate at small sample sizes.

When \underline{all} expected counts $\ge$ 5, use method 1.

When any expected count < 5, use method 2.

Alternate method when `n` is really small: \underline{Fisher's exact test}

Condition on marginal totals being fixed, get a test statistic with hypergeometric distribution.

P-Value = P($\chi^2 \ge 1.69$) from $\chi^2$ distribution with 1 degree of freedom = 0.193

\newpage

\textbf{Not on test but may show up in context:}

# 3 "Measures of association" between categorical variables

1. Difference in proportions
- Population: P\textsubscript{1} - P\textsubscript{2}
- Samples: $\hat{P}\textsubscript{1} - \hat{P}\textsubscript{2}$
2. Relative risk (RR)
- Population : $\frac{P\textsubscript{1}}{P\textsubscript{2}}$
