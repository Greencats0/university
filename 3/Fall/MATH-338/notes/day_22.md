---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
toc: true
---

\newpage

# Day 22

Test is next Thursday 11/21.

# Confidence Intervals

\underline{Neyman-Pearson Ideas:}

![Two Sided Test](assets/two_sided){width=75%}

<!--Each sliver represents $t\textsuperscript{\ast\ast}$ and its corresponding area of $\frac{\alpha}{2}$-->

If t\textsubscript{observed} is anywhere in the area $1 - \alpha = C$, we accep H\textsubscript{0}.

\underline{One-sample t-Test:} For what values of $\mu\textsubscript{0}$ will we accept H\textsubscript{0}: $\mu = \mu\textsubscript{0}$?

$$-t^{\ast\ast} < t\textsubscript{observed} < t^{\ast\ast}$$

$$-t^{\ast\ast} < \frac{\bar{x}\textsubscript{observed} - \mu\textsubscript{0}}{\frac{s\textsubscript{observed}}{\sqrt{n}}}$$

Any value of $\mu$ between

$$\bar{x}\textsubscript{observed} - t^{\ast\ast} \times \frac{s\textsubscript{observed}}{\sqrt{n}}$$

\begin{center}
\hl{and}
\end{center}

$$\bar{x}\textsubscript{observed} + t^{\ast\ast} \times \frac{s\textsubscript{observed}}{\sqrt{n}}$$

We will accept.

The interval($\bar{x}\textsubscript{observed} - t^{\ast\ast} \times \frac{s\textsubscript{observed}}{\sqrt{n}}$, $\bar{x}\textsubscript{observed} + t^{\ast\ast} \times \frac{s\textsubscript{observed}}{\sqrt{n}}$), represents the \underline{range of values} within which we resonably would believe $\mu$ to be.
This interval is called a \underline{confidence interval} for $\mu$.

In many situations, we either don't know what $\mu\textsubscript{0}$ should be or don't care to make a decision - just want to estimate $\mu$.

\newpage

## How confident are we?

We define confidence level as the proportion of samples for which we would accept H\textsubscript{0}: $\mu = \mu\textsubscript{0}$ when H\textsubscript{0} is true.

So confidence level $C = 1 - \alpha \leftarrow$ depends on H\textsubscript{0} is true.

- $\uparrow \alpha \implies \downarrow C$
- $\downarrow \alpha \implies \uparrow C$

### Problem

We don't know $\mu\textsubscript{0}$!

Confidence is in our \underline{estimate} of $\mu$.

If $\mu$ is in our interval
    - "good" sample, correctly accept H\textsubscript{0}
If $\mu$ is not in our interval
    - "bad" sample, make a Type 1 Error

We \underline{always} assume we got a "good" sample.

## Affecting Width

What affects the width of the confidence interval?

$$\bar{x} \pm t^{\ast\ast} \times \frac{s}{\sqrt{n}}$$

- $\bar{x}$: center
- $t^{\ast\ast}$: comes from $t(df)$ and is also dependent on $\alpha$
    - $df \uparrow$, $t^{\ast\ast} \downarrow$, width $\downarrow$
    - $\alpha \uparrow$, $t^{\ast\ast} \downarrow$, width $\downarrow$
    - $C \uparrow$, $t^{\ast\ast} \uparrow$, width $\uparrow$
- n: sample size $\uparrow$, width $\downarrow$
- s: sample standard deviation $\uparrow$, width $\uparrow$

\newpage

# Example

Suppose we take a simple random sample of 8 college students and ask how much time they spend per week watching broadcast TV.
In the sample, $\bar{x} = 14.5$ hrs/week and $s = 14.884$ hrs/week.
Use this information to \underline{estimate} with \underline{95\% confidence} the \underline{population mean} time college students spend watching TV per week.

Is this data symmetric?

- This data is \textbf{not} because the sample standard deviation is quite large.

## Solution

\underline{Step 1:} Assume this is a good sample. So for any value in $\mu$ in:

$$y = mx + b$$

\underline{Step 2:} Plug in for $\bar{x}, s, n$

$$y = ax^2 + bx + c$$

\underline{Step 3:} Find $t^{\ast\ast}$

$$df = 7, C = 0.95 \implies \alpha = 0.05$$

```r
qt(0.025, df = 7, lower.tail = FALSE)
[1] 2.305
```

$\frac{\alpha}{2} = 0.025 \implies t^{\ast\ast}$

\underline{Step 4:}

$= (14.5-23.05(\frac{14.854}{\sqrt{8}}), 14.5+23.05(\frac{14.854}{\sqrt{8}}))$

$= (2.08, 26.92)$

\newpage

## Tying Example Back into Theory [Interpretation]

We are \underline{95\% confident} (in our estimate) that the \underline{population mean} (number of hours per week) is between \underline{2.08 and 26.92}.


# Other Frameworks

\underline{Matched Pairs}

\begin{large}
- $t\textsubscript{observed} = \frac{\bar{x}\textsubscript{d} - \mu\textsubscript{d}}{\frac{s\textsubscript{d}}{\sqrt{n}}}$
\end{large}
- Confidence Interval for  $\mu\textsubscript{d}$:

$$\bar{x}\textsubscript{d} \pm t^{\ast\ast} \times \frac{s\textsubscript{d}}{\sqrt{n}}$$

\begin{center}
($\bar{x}\textsubscript{d} - t^{\ast\ast} \times \frac{s\textsubscript{d}}{\sqrt{n}}$, $\bar{x}\textsubscript{d} + t^{\ast\ast} \times \frac{s\textsubscript{d}}{\sqrt{n}}$)
\end{center}

\underline{Two-Sample}

<!--(\bar{x}\textsubscript{1} - \bar{x}\textsubscript{2}) - (\mu\textsubscript{1} - \mu\textsubscript{2})-->

<!--\sqrt{\frac{s\textsubscript{1}^2}{\n\textsubscript{1}} + \frac{s\textsubscript{2}^2}{n\textsubscript{2}}-->

<!--$$t\textsubscript{observed} = \frac{(\bar{x}\textsubscript{1} - \bar{x}\textsubscript{2}) - (\mu\textsubscript{1} - \mu\textsubscript{2})}{\sqrt{\frac{s\textsubscript{1}^2}{\n\textsubscript{1}} + \frac{s\textsubscript{2}^2}{n\textsubscript{2}}}$$-->
\newpage

# Terms

\underline{Point Estimate:} statistic whose value is our "best guess" as to the value of a parameter

- $\bar{x}, \bar{x}\textsubscript{d}, \bar{x}\textsubscript{1} - \bar{x}\textsubscript{2}, etc$

\underline{Margin of Error:} how much to add/subtract to create an interval estimate we are C\% confident in:

t critical value $\times$ standard error [for two sided N-P test]

\newpage

# Example : Book Exercise 7.71

202 "early" eaters [Population 1]

- $\bar{x}$ = 23.1 grams of fat
- s = 12.5 grams

200 "late" eaters [Population 2]

- $\bar{x} = 21.4$ grams of fat
- s = 8.2 grams

Estimate with 95\% confidence the difference in population mean fat consumption. ($\mu\textsubscript{1} - \mu\textsubscript{2}$): ($-0.4, 3.8$)

We are \underline{\textcolor{blue}{95\%}} confident in our estimate that \underline{\textcolor{blue}{the difference in population mean fat consumption between early \& late eaters}} is between \underline{\textcolor{blue}{-0.4}} and \underline{\textcolor{blue}{3.8}} grams.

Suppose H\textsubscript{0}: $\mu\textsubscript{1} - \mu\textsubscript{2} = 0$.
H\textsubscript{1}: $\mu\textsubscript{1} - \mu\textsubscript{2} = \Delta$

Can I accept H\textsubscript{0} [\hl{in Neyman-Pearson Framework}] using this sample.

- Yes because $-0.4 < 0 < 3.8$

Can I reject H\textsubscript{0}: $\mu\textsubscript{1} - \mu\textsubscript{2} = 0$ [\hl{NHST}] in favor of H\textsubscript{a}: $\mu\textsubscript{1} = \mu\textsubscript{2} \ne 0$? (Using $\alpha = 0.05$)

- No because $-0.4 < 0 < 3.8$

\underline{Based on our sample:}

\begin{enumerate}
\item $\mu\textsubscript{1}$ and $\mu\textsubscript{2}$ could be $=$
\item $\mu\textsubscript{1}$ could be as much as 3.8 bigger than $\mu\textsubscript{2}$
\item $\mu\textsubscript{1}$ could be as much as 0.4 smaller than $\mu\textsubscript{2}$
\end{enumerate}

## Interpretations

\textcolor{blue}{We are 95\% confident in our estimate that, on average (in the population), early eaters consume between 0.4 grams less \& 3.8 grams more fat compared to late eaters.}

$\uparrow$ \textcolor{red}{SAME THING} $\downarrow$

\textcolor{blue}{$\mu\textsubscript{1} =$ population mean late eaters, $\mu\textsubscript{2} =$ population mean early eater ($-3.8, 0.4$)}

\newpage

## Hypothetical Scenarios

\underline{Suppose both bounds are positive:}

$\mu\textsubscript{early} - \mu\textsubscript{late} \implies$ CI: ($0.4, 3.8$)

Only possibility: $\mu\textsubscript{early} > \mu\textsubscript{late}$

\textcolor{blue}{We are 95\% confident in our estimate that, on average (in the population), early eaters consume between 0.4 grams more and 3.8 grams more than late eaters}

\underline{Suppose both bounds are negative:}

.... 

insert chart from picture

\textbf{NOTE:}

We can always \underline{always} perform hypothesis testing by constructing a confidence interval with confidence level

$$C = 1 - \alpha$$

and seeing i the null value is in the confidence interval!

Prefer confidence interval over hypothesis testing:

- Additional information!
- Confidence interval screws up in the interpretation are \underline{much} less costly than hypothesis testing screws ups.

\underline{Generally only use hypothesis for Fisher-type tests ($\chi^2$, ANOVA)}

H\textsubscript{0}: $\mu\textsubscript{1} = \mu\textsubscript{2} = \mu\textsubscript{3}$

Reject H\textsubscript{0}: at least 1 $\mu$ is different.

$\rightarrow Estimate$:

- $\mu\textsubscript{1} - \mu\textsubscript{2}$
- $\mu\textsubscript{1} - \mu\textsubscript{3}$
- $\mu\textsubscript{2} - \mu\textsubscript{3}$

\underline{Knowing} at least one of the differences exists.
