---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
    \usepackage{subcaption}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
toc: true
---

\graphicspath{./assets/}

\newpage

# Day 15

# Z-Score Example

Two tests of "English" ability

- NAEP Reading Test
- SAT verbal

Suppose a student score scored 320 on NAEP & 650 SAT

Which test did he do better on?

$NAEP \sim N(288, 38)$

$SAT \sim N(500, 120)$

\textbf{Convert to Z-Scores}

\underline{NAEP:} 

$$Z = \frac{value\, - \, mean}{standard\, deviation} = \frac{320 - 288}{38} = 0.842$$

\begin{center}
\hl{Student scored 0.842 standard deviation above average}
\end{center}

\underline{SAT:}

$$Z = \frac{value\, -\, mean}{standard\, deviation} = \frac{650 - 500}{120} = 1.25$$

\begin{center}
\hl{Student scored 1.25 standard deviation above average}
\end{center}

## R-Code

```r
pnorm(320, mean = 288, sd = 38)
[1] 0.8001355
```

Cumulative proportion of 0.800 (80%) which means 80\textsuperscript{th} percentile.

```r
pnorm(650, mean = 500, sd = 120)
[1] 0.8943502
```

Cumulative proportion of 0.8943502 which means 89\textsuperscript{th} percentile.

\newpage

# Water bottle example

## Questions

- Why does it continue to overfill
    - How much does it actually pour $\rightarrow$ average
- Why does Dr. Wynne have such terrible reaction speed?
    - Reaction speed $\rightarrow$ average
- Does the water fill at the same rate
    - Average rate for one pour
    - $\rightarrow$ average over several attempts


Expected value = $\mu$ = expected amount filled

$\bar{X}$ =  average amount filled in a sample of pours "sample mean".

\underline{Variability:} how variable are the individual values. (range)

- $\sigma$ = Standard Deviation
- $\sigma^2$ = Variance 
- S = Sample Standard Deviation
- $S^2$ = Sample Variance

\underline{Bias:} \underline{Center:} - on average, are we where we expected to be? (mean, median, mode)

\newpage 

# Shape

\underline{Shape:} where "average" is compared to "most likely"

- How "consistent" the values are given variability

![Unimodal Distribution](assets/unimodal){width=50%}

![Bimodal Distribution](assets/biomodal){width=50%}


\newpage 

The median is resistant, the mean is subject to more change. 


![Left and Right Skewed Graphs](assets/skewed_graphs){width=50%}

![Symmetric Graph](assets/symmetric){width=50%}


\newpage

Approximating a Density Curve: \underline{Histogram}

![Histogram](assets/histogram){width=50%}

- "bins": intervals on the x-axis
- Choice of bins is \underline{very} important
    - Endpoints of bins
    - Center & Width
- Reimann Integral of an unknown density curve 

\newpage

# Outliers

Points that doesn't fit with everything else

## Attempting to determine outliers

- Plot your data & look for points that don't belong
- $\uparrow$ best way
- Investigate why they're different

## Box-Plots

![Box Plot](assets/boxplot){width=50%}

## Rule of Thumb

- Step 1: Get five number summary (min, Q\textsubscript{1}, medium(Q\textsubscript{2}), Q\textsubscript{3}, max)
- Step 2: Compute IQR = range middle 50% of data
    - IQR = Q\textsubscript{3} - Q\textsubscript{1}
- Step 3: Compute "fences"
    - Lower fence: $Q\textsubscript{1} - K \times IQR$
    - Upper fence: $Q\textsubscript{3} + K \times IQR$

Anything outside the fences is an outlier.

By convention, $k = 1.5$

## Example : Senator Ages

Five number summary:

- Min = 39
- Q\textsubscript{1} = 55.5
- Median = 63
- Q\textsubscript{3} = 69
- Max = 85

$IQR = 69 - 55.5 = 13.5$

Lower fence: $55.5 - (1.5)(13.5) = 35.25$
Upper fence: $69 + (1.5)(13.5) = 89.25$

In this data set we have no outliers because our data falls between the fences.

\newpage

# Numerical Variable Connection to Random Variables

\textbf{Recall for random variable X}

$E(A + Bx) = a + b \times E(x)$

$Var(A + Bx) = b^2 \times Var(x)$

$SD(A + Bx) = |b| \times sd(x)$

\textbf{Recall for random variable X and Y}

$E(Ax + By) = aE(x) + bE(y)$

$Var(Ax + By) = A^2 \times var(x) + B^2 var(y)$

$SD(Ax + By) = \sqrt{A^2 \times var(x) + B^2 \times var(y)}$

All of these rules hold for numerical variables too
