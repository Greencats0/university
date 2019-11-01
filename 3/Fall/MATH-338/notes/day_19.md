---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
toc: true
---

<!--attach files | [assets/t_test_examples.pdf]-->
<!--attach files | [assets/t_test_examples.pdf:1, exported/day_1.pdf:3]-->

<!--path/to/file:[page number to insert[^|$] before or after]-->
<!--path/to/file:? at the absolute last-->
<!--path/to/file:! at the absolute beginning-->

<!--program idea to automatically attached pdfs upon compile-->

# Day 19

\newpage

# One-Sample T-Test Examples

Please see attached PDF for example procedures

## Review

H\textsubscript{0}: $\mu = \mu\textsubscript{0}$

\underline{T-Statistic:}

<!--$$t=\frac{\bar{x} - \mu\textsubscript{0}{\frac{s}{\sqrt{n}}}}$$-->
$$t = \frac{\bar{x} - \mu}{\frac{s}{\sqrt{n}}}$$

$$t \sim t(n-1)$$

\newpage

## Example 1 : Budwiser

ABV: Alcohol By Volume

February 2013, a lawsuit claimed actual ABV content in Budwiser was 4.7% but Budwiser advertised ABV of 5%.

Suppose 3 independent labs test Budwiser beer ABV content.

\underline{Recall:} measurement error is assumed normally distributed

\underline{Assume:} measurements are unbiased

**read these as percents but treat as whole numbers**

H\textsubscript{0}: $\mu = 5$

H\textsubscript{1}: $\mu = 4.7$

$\alpha = 0.05$

\underline{Find the critical region:}

$$t = \frac{\bar{x} - 5}{\frac{s}{\sqrt{3}}}$$

Under H\textsubscript{0} $\implies t \sim t(2)$

There are two degrees of freedom.

\underline{Critical Region:} $t \le -2.92$

If t\textsubscript{observed} $\le -2.92$, accept H\textsubscript{1} claiming the beer is watered down.

If t\textsubscript{observed} $> -2.92$, accept H\textsubscript{0} claiming the beer is \underline{not} watered down.

\underline{Lab Measurements:}

$\bar{x} = 4.927$

$s = 0.032$

$$t\textsubscript{observed} = \frac{4.977 - 5}{\frac{0.032}{\sqrt{3}}} = -1.257$$

```r
qt(0.05, 2, lower.tail = TRUE)
```
Since $-1.257 > -2.92$, we accept H\textsubscript{0} $\implies$ beer is not watered down.

### Power Analysis

Is a sample of 3 labs big enough to detect $\mu = 4.7$?

\newpage

# Special Case: Matched Pairs (Paired) t-Test

\underline{When it's used:} matched-pairs experiment case-control observation study \hl{or} any other situation where we have a numerical response variable recorded on the same subjects under two different conditions/on pairs of subjects

\underline{Commonly seen:} before and after treatment studies.

We do inference on the \underline{paired differences}

E.G) after - before

$\mu\textsubscript{d}$ denotes the population mean of paired differences

$\bar{x\textsubscript{d}}$ denotes the sample mean of paired differences

$s\textsubscript{d}$ denotes the sample standard deviation of paired differences

$n$ denotes the number of paired differences


$$t = \frac{\bar{x\textsubscript{d}} - \mu\textsubscript{d}}{\frac{s\textsubscript{d}}{\sqrt{n}}}$$

\underline{Very common:}

H\textsubscript{0}: $\mu\textsubscript{d} = 0$

$\rightarrow$ no difference between conditions

H\textsubscript{a}: $\mu\textsubscript{d} \ne 0$

$\rightarrow$ difference between conditions

\newpage

## Example : Book Exercise 7.10

Comparing taste of hash browns in deep fryer (oil) vs air fryer (no oil)

Five experts rate taste of hash browns made in each fryer

![Hash Brown Expert Analysis](assets/hash_brown)

Is there a difference in taste bwtween oil and no-oil hash browns?

H\textsubscript{0}: $\mu\textsubscript{d} = 0$

H\textsubscript{a}: $\mu\textsubscript{d} \ne 0$

**No oil - oil**

![Hash Brown Expert Analysis (Difference)](assets/hash_brown_differences)

$\bar{x\textsubscript{d}} = 1.6$

$s\textsubscript{d} = 2.966$

$$t\textsubscript{observed} = \frac{1.6 - 0}{\frac{2.966}{\sqrt{5}}} = 1.96$$

$$t\textsubscript{observed} \sim t(4)$$

P(t $\ge$ 1.96 | H\textsubscript{0} is true) = 0.061

p-value = $2(0.061) = 0.122$

Compare the p-value to the significance level, which by default is 0.05

If p-value $\le$ significance level, we reject H\textsubscript{0} & accept H\textsubscript{a} conclude there is a taste difference.

If p-value > significance level, we fail to reject H\textsubscript{0} cannot claim there is a difference.

If H\textsubscript{a}: $\mu\textsubscript{d} = 0 \rightarrow$ no-oil taste better than oil taste. This is because our difference were no_oil - oil.

Then: $t\textsubscript{observed} = 1.96$

p-value = P(t $\ge$ 1.96 | H\textsubscript{0} is true) = 0.061

If H\textsubscript{a}: $\mu\textsubscript{d} < 0$, with no oil taste \underline{worse} than oil taste.

t = 1.96

p-value = P(t $\le$ 1.96 | H\textsubscript[0] is true) = 0.939

\newpage


# Example : Case of Beer

H\textsubscript{0} = $\mu = 5$
H\textsubscript{a} = $\mu < 5$
