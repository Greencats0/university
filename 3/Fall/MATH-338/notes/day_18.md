---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
        \usepackage{xfrac}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
toc: true
---

# Day 18

\newpage

# Historical Motivation for T-Statistics

## Example : Best Beer

### Questions

- What type of barely is best?
    - How much barely can be produced?
    - How high quality is the barely?

Combine the two questions proposed into one variable $\rightarrow$ value per acre. We know there is variation in this variable.
Different farms have variable soil, temperature, etc.

We need to know the \underline{average} value per acre.

$$\bar{X} \sim N(\mu, \frac{\sigma}{\sqrt{n}})$$

Problem is that we don't know $\mu$ nor $\sigma$

We can hand-waive this by saying:

- For sufficiently large samples we can replace population standard deviation $\sigma$ with sample sample standard deviation $s$ and our probability calculations are not too far off.

Our sample size is 4 farms, which is not enough.

For small samples, there is a lot variability in $S$. We need to take this variation into account.

### Conclusions being Published

- Released in 1908 under the pseudonym \underline{Student} who's real name is W.S. Gosset
- "Conclusions are not strictly applicable to populations known to be normally distributed; yet it appears probable that the deviation from normality must be very extreme to lead to serious error."

Fisher was the only person who really cared about this report. This allowed Fisher for coming up with a better way. Most problems solved by statistics have been solved by beer and eugenics.

$$t = \frac{\bar{X} - \mu}{\frac{s}{\sqrt{n}}}$$

\newpage

# Definitions

## Standard Error of the Mean (SEM) 

The \underline{estimated} standard deviation of the sampling distribution of $\bar{X}$, calculated as $\frac{s}{\sqrt{n}}$.
More generally, the standard error of the statistic is the \hl{estimated} (from sample data) standard deviation of its sampling distribution.
As `n` $\uparrow$, SEM $\downarrow$

## One-Sample t Statistic:

$$t = \frac{\bar{X} - \mu}{\frac{s}{\sqrt{n}}}$$ 

Has a (student's) t-distribution

With $n-1$ degrees of freedom, supposing a simple random sample of size `n` drawn from a population $\sim N(\mu, \sigma)$ where $(\mu\, known, \sigma\, unknown)$.
When population is not normal, procedures using t-distribution are still roughly accurate (unless clear skew/outlier issues).
At high degrees of freedom, $t(n-1)$ is indistinguishable from $N(0, 1)$ visually. It gets more rounded and less peaked at the top. 

\newpage

# R Code

- pt: values $\rightarrow$ probability
- qt: probability $\rightarrow$ values

\newpage

# Example

Suppose you have a simple random sample of 16, one-bedroom apartments for renting in a neighborhood. The sample mean rent price is $1280 per month and sample standard deviation is $180 per month.

## Computational

- What is the SEM?
- What would the distribution of a t-statistic based on this sample?
- What else would you need to know/assume to calculate t-statistic?

## Theoretical

- If you took a simple random sample of 25 apartments instead, would you express SEM to be larger or smaller? Why?
- Is it guaranteed?

## Response

### Computation

- $\frac{s}{\sqrt{n}} = \frac{180}{\sqrt{16}} = 45$
- \hl{Degrees of freedom:} $n-1 = 16-1 = 15 \rightarrow t(df = 15) \rightarrow t(15)$ 
- $\mu$

### Theoretical

- The SEM will go $\downarrow$ because there is less variability.
- No because if $s > 225 \implies \frac{s}{\sqrt{n}} > 45$

\newpage

# One-Sample T-Statistic

H\textsubscript{0} : $\mu  = \mu\textsubscript{0}$

$$t = \frac{\bar{X} - \mu\textsubscript{0}}{\frac{s}{\sqrt{n}}}$$

$\uparrow$ under the null hypothesis (H\textsubscript{0}).
If t\textsubscript{observed} is in critical region: accept H\textsubscript{1}: $\mu = \mu\textsubscript{1}$. Else accept H\textsubscript{0}: $\mu = \mu\textsubscript{0}$
Also, under H\textsubscript{0}, $t \sim t(n-1)$

$$t\textsubscript{observed} = \frac{\bar{x}\textsubscript{observed} - \mu\textsubscript{0}}{\frac{s\textsubscript{observed}}{\sqrt{n}}}$$

## Neyman-Pearson Framework

Critical Region: on the t-scale

- $t \ge t^{\ast}$
- $t \le -t^{\ast}$

$$t\* \ge \frac{\bar{X} - \mu\textsubscript{0}}{\frac{s}{\sqrt{n}}}$$

## Two-Sided Test

$$|t| \ge t^{\ast\ast}$$

If t\textsubscript{observed} is in critical region: accept H\textsubscript{1}: $\mu = \mu\textsubscript{1}$.
Else accept H\textsubscript{0}: $\mu = \mu\textsubscript{0}$

$$t\textsubscript{observed} = \frac{\bar{x}\textsubscript{observed} - \mu_0}{\frac{s\textsubscript{0}}{\sqrt{n}}}$$

## NHST

- H\textsubscript{a}: $\mu > \mu\textsubscript{0}$
- OR : $\mu < \mu\textsubscript{0}$
- OR : $\mu \ne \mu\textsubscript{0}$

## P-Value

- $P(t \ge t\textsubscript{observed})$
- $P(t \le t\textsubscript{observed})$
- $P(|t| \ge |t\textsubscript{observed}|)$
   - Find one-sided p-value and double it

\newpage

# Distributions we Should Know

- $N(\mu, \sigma)$
- $B(n, P)$
- $U(a, b)$ OR $V(a, b)$, can't tell
- $\chi^2(df)$
- $t(df)$

# External Links

- [Two Tailed Test Article](https://www.investopedia.com/terms/t/two-tailed-test.asp)
