---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
toc: true
---

# Day 20

\newpage

# Two Independent Samples t-Test

\underline{When it's used:} randomized with unrelated treatments & control groups \hl{OR} observational study with comparing two unrelated groups.

\underline{Very common:} compute mean if everyone got "new" treatment to mean if everyone got "control" treatment. Example; two groups, one smoking and the other group not smoking.

\underline{Data looks like:} one numerical response variable measured in two \hl{independent groups}

\newpage

## Example

![Numbers to numbers](assets/independent_numerical)

![Numbers to groups](assets/independent_categorical)

\newpage

# Theory & Concepts

Let $\mu\textsubscript{1} =$ population mean in group 1. $\mu\textsubscript{2} =$ population mean in group 2.

Example: $\mu\textsubscript{1} =$ population mean cholesterol level if everyone got \underline{new} drug. $\mu\textsubscript{2} =$ population mean cholesterol level if everyone \underline{current} drug.

We want to do inference on $\mu\textsubscript{1} - \mu\textsubscript{2}$, the \underline{difference of population means}.

\hl{Recall:} $$t = \frac{STATISTIC \, - PARAMETER}{STANDARD\, \, ERROR}$$

$$t = \frac{(\bar{x}\textsubscript{1} - \bar{x}\textsubscript{2}) - (\mu\textsubscript{1} - \mu\textsubscript{1})}{STANDARD\, \, ERROR}$$

Now we have two sample, so we have:

\fbox{\begin{minipage}{15em}
\begin{itemize}
\item $\bar{x}\textsubscript{1}$
\item $S\textsubscript{1}$
\item $n\textsubscript{1}$
\end{itemize}

\begin{itemize}
\item $\bar{x}\textsubscript{2}$
\item $S\textsubscript{2}$
\item $n\textsubscript{2}$
\end{itemize}

\end{minipage}}

By CLT, $$\bar{X}\textsubscript{1} \sim N(\mu\textsubscript{1}, \frac{\sigma\textsubscript{1}}{\sqrt{n\textsubscript{1}}})$$

$$\bar{X}\textsubscript{2} \sim N(\mu\textsubscript{2}, \frac{\sigma\textsubscript{2}}{\sqrt{n\textsubscript{2}}})$$

$$\bar{X}\textsubscript{1} - \bar{X}\textsubscript{2} \sim N(\mu\textsubscript{1} - \mu\textsubscript{2}, \sqrt{\frac{(\sigma\textsubscript{1})^2}{n\textsubscript{1}} + \frac{(\sigma\textsubscript{2})^2}{n\textsubscript{2}}}]$$

$$Var(\bar{X}\textsubscript{1} - \bar{X}\textsubscript{2}) = Var(\bar{X}\textsubscript{1}) + Var(\bar{X}\textsubscript{2})$$

$$(\sigma\textsubscript{1})^2 + (\sigma\textsubscript{2})^2$$

\hl{Serious problem: we need to estimate two standard deviations!}

## Solution 1 : Assume $\sigma\textsubscript{1} = \sigma\textsubscript{2}$

Estimate using pooled standard deviation $S\textsubscript{p}$

$$\sqrt{weighted\, average\, of\, variance}$$


**this is not needed**

## Satterthwaite Approximation

$$t \sim t(df)$$

Where `df` is calculated by Satterthwaite approximation.

In general, df is \underline{\underline{NOT}} an integer


## Welch's t-Test

Almost always, H\textsubscript{0}: 

- $\mu\textsubscript{1} - \mu\textsubscript{2} = 0$
- $(\mu\textsubscript{1} = \mu\textsubscript{2})$

Under H\textsubscript{0}, 

$$t = \frac{(\bar{x}\textsubscript{1} - \bar{x}\textsubscript{2})}{\sqrt{\frac{(s\textsubscript{1})^2}{n\textsubscript{1}} +\frac{(s\textsubscript{2})^2}{n\textsubscript{2}}}}$$

\underline{Almost always:} use a two-sided test

Alternative hypothesis: \underline{difference} between treatment & control.

\textbf{Neyman-Pearson:} 

H\textsubscript{1}:

- $\mu\textsubscript{1} - \mu\textsubscript{2} = \Delta$
- $\Delta =$ desired effects size in original units
- Two sided critical region:
    <!--- $t > t\textsuperscript{\ast\ast}$-->
    <!--- $t < -t\textsuperscript{\ast\ast}$-->

Compute t\textsubscript{observed}

Accept H\textsubscript{1} if t\textsubscript{observed} in critical region.
Else accept H\textsubscript{0}.


\newpage

## NHST Approach

H\textsubscript{a}: $\mu\textsubscript{1} - \mu\textsubscript{2} \ne 0$

\hl{NOTE:} can use $\mu\textsubscript{1} - \mu\textsubscript{2} > 0$ or $\mu\textsubscript{1} - \mu\textsubscript{2} < 0$ but \underline{be \underline{very} careful}

Under H\textsubscript{0}:

$$t = \frac{(\bar{x}\textsubscript{1} - \bar{x}\textsubscript{2})}{\sqrt{\frac{(s\textsubscript{1})^2}{n\textsubscript{1}} +\frac{(s\textsubscript{2})^2}{n\textsubscript{2}}}} \sim t(K)$$

\textbf{K is given by software}

Two-sided p-value = $P(|t| \ge |t\textsubscript{observed}| | H\textsubscript{0} is true)$

If p-value $\le$ significance level, reject H\textsubscript{0} & accept H\textsubscript{a}.
Else fail to reject H\textsubscript{0}.


## Example

Study comparing fat consumption of early vs late eaters. We want to know whether there is a difference in fat consumption.

Use NHST approach

- H\textsubscript{0}: $\mu\textsubscript{1} - \mu\textsubscript{2} = 0$
- H\textsubscript{a}: $\mu\textsubscript{1} - \mu\textsubscript{2} \ne 0$

Let $\mu\textsubscript{1} =$ population mean fat consumption in early eaters

Let $\mu\textsubscript{2} =$ population mean fat consumption in later eaters

### Data

\underline{Early eaters (n=202)}

- $\bar{x} = 23.1g$
- $S = 12.5g$

\underline{Late eaters (n=200)}

- $\bar{x} = 21.4g$
- $S = 8.2g$

$\mu\textsubscript{1} - \mu\textsubscript{2} > 0 \implies$ always above

$\mu\textsubscript{1} - \mu\textsubscript{2} < 0 \implies$ always below

Under H\textsubscript{0}:

$$t = \frac{(\bar{x}\textsubscript{1} - \bar{x}\textsubscript{2})}{\sqrt{\frac{(s\textsubscript{1})^2}{n\textsubscript{1}} +\frac{(s\textsubscript{2})^2}{n\textsubscript{2}}}}$$

The answer is about 1.614.

Satterthwaite approximation gives df = 347.41

```r
pt(1.614, df = 347.41, lower.tail = FALSE)
```

p-value = 2(0.054) = 0.108

At 5% significance level, we fail to reject H\textsubscript{0} because 0.108 > 0.05. We failed to find a \underline{statistically significant} difference in fat consumption.
