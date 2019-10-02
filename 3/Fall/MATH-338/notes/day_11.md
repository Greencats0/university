---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
---

# Day 11

## Outline

1. Fisher's Significance Tests
2. Goodness of fit test

## Tl;DR

This model is concerned about the model used rather than actually trying to prove anything. If the initial hypothesis is rejected then we look into \underline{why} it failed, rather than stopping at that conclusion.

## Midterm Exam 1

### Lecture

- ~ 60% 
- 4 to 5 multi-part problems

\underline{Allowed:} one-sided formula sheet (can be typed or printed)

### Lab

- ~ 40%
- 3 problems, 2 to 3 part problems

\underline{Allowed:} textbook, notes, software help, anything on Titanium

\newpage

# Fisher's Significance Testing

In Fisher's view, there is only \underline{one} hypothesis. We see how well sample data "fit" that hypothesis.

In the strictest sense, the hypothesis includes \underline{all} assumptions about the probability model used to obtain the sampling distribution of the test statistic.

Assumption are of two kinds:

1. Assumptions about parameters
2. Assumptions about data generation/collection

In practice, we refer to \underline{\underline{the}} hypothesis as the \hl{null hypothesis} (H\textsubscript{0}).

Using the Null Hypothesis Significance Testing we write H\textsubscript{a}: not H\textsubscript{0}

Where we see this:

- $\chi\textsuperscript{2}$ test (Chi-Squared)
- ANOVA

\par\noindent\rule{\textwidth}{0.4pt}

In Fisher's approach, we \underline{first} specify our model

- Then: Specify sampling distribution of test statistic
- Then: Collect data and compute value of test statistic
- Then: Get P-Value

\underline{Recall:} P-Value is probability of obtaining our data, or a result with a test statistic signalling \underline{equal or greater "distance" from} H\textsubscript{0}, if H\textsubscript{0} is true.

\underline{Pure Fisher Philosophy:} Stop here. P-Value represents "how well" data fit hypothesis.

- Very high P-Value: data fit suspiciously well
- Very low P-Value: data does not fit well at all

In practice: Fisher commends a personal \underline{significance level.}

- Significance = "Signifying something"

\par\noindent\rule{\textwidth}{0.4pt}

P-Value $\le$ significance level: our results are a meaningful difference from the model. We should investigate!

- Reject H\textsubscript{0}

P-Value > significance level: our results are consistent with the model. We did not prove it correct but the model is a reasonable approximation of reality.

- Fail to reject H\textsubscript{0}

In practice: we define one main assumption about the parameters to be the H\textsubscript{0} that can get rejected.

\newpage

# Goodness of Fit Testing

Most of the "classic" goodness of fit tests involve genetics.

## Example (Theory) : Mendel's Pea Plants

Dihybrid cross for seed shape & seed color
\underline{Mendel's Laws:} Should see a 9:3:3:1 ratio

\underline{Hypothesis:} $\frac{9}{16}$ round/yellow, $\frac{3}{16}$ round/green, $\frac{3}{16}$ wrinkled/yellow, $\frac{1}{16}$ wrinkled/green

In practice: 

H\textsubscript{0}: P\textsubscript{RY} = $\frac{9}{16}$, P\textsubscript{RG} = $\frac{3}{16}$, P\textsubscript{WY} = $\frac{3}{16}$, P\textsubscript{WG} = $\frac{1}{16}$

\par\noindent\rule{\textwidth}{0.4pt}

We know the observed sample will probably not have those proportions.

We need a measure of "how far off" our sample is from what we expect. [$\chi^2$ test statistic]

We define (Pearson) residuals for the different categories:

Residual = $\frac{O -E}{\sqrt{E}}$

- O : # of \underline{observed} in sample
- E : # of \underline{expected} in sample

$\chi^2 = \Sigma\, \,  residual\textsuperscript{2} = \Sigma \, \, \frac{O -E}{\sqrt{E}}$

\hl{Where $\Sigma$ is all categories}

\par\noindent\rule{\textwidth}{0.4pt}

Mendel observed:

- 315 RY
- 108 RG
- 101 WY
- 32 WG

\par\noindent\rule{\textwidth}{0.4pt}

Total: 556 seeds

\par\noindent\rule{\textwidth}{0.4pt}

What do we expect?

- $\frac{9}{16} (556) = 312.75$ RY
- $\frac{3}{16} (556) = 104.25$ RG
- $\frac{3}{16} (556) = 104.25$ WY
- $\frac{1}{16} (556) = 34.75$ WG

Pearson Residuals:

- RY : $\frac{315 - 312.75}{\sqrt{312.75}} = 0.127$

- RG : $\frac{108 - 104.25}{\sqrt{104.25}} = 0.367$

- WY : $\frac{101 - 104.25}{\sqrt{104.25}} = -0.318$

- WG : $\frac{32 - 34.75}{\sqrt{34.75}} = -0.467$

\newpage

# Goodness of Fit Testing (Continued)

Contribution of a category $\chi^2$ = square of its Pearson residual

In our example:

$\chi^2 = (0.127)^2 + (0.367)^2 + (-0.318)^2 + (-0.467)^2 = 0.47$

Our sample data is 0.47 "off" from what we expected.

$\chi$ is unit-less.

To compute the P-Value, we need a sampling distribution of $\chi^2$

P-Value = P($\chi^2 \ge 0.47$ | H\textsubscript{0} is true)

\par\noindent\rule{\textwidth}{0.4pt}

Approximate the sampling distribution 1 of 2 ways:

1. Under H\textsubscript{0}, $\chi^2$ has approximately a $\chi^2$ distribution with (# of categories - 1) \underline{degrees of freedom}

<div style="text-align:center">![$\chi^2$ Distribution](assets/chi_squared_graph){width=50%}</div>

- Strictly non-negative
- "Skewed right"

Software gives us approximate-value $P(\chi^2 \ge 0.47) = 0.9254$

If P-Value is "really small": reject H\textsubscript{0} means "our proportions are not all correct" - we should investigate to find out which ones & why.

Mendel's data was probably full crap, not on him but the guy collecting the peas.

2. Simulate very many samples of sizes `n`, under assumption of H\textsubscript{0} is true, and compute $\chi^2$ for each simulated sample

When we expected $\ge 5$ in each category in our sample, both approaches give similar results.

When in any category we expect < 5 counts, we use #2 above.
