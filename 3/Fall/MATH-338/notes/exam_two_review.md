---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
---

# Distributions We Should Know

- Binomial: $B(n, P)$
    - n = sample size
    - p = probability of success
    - going to be on the exam \textcolor{red}{NO}
    ```r
    pbinom()
    qbinom()
    ```
- $\chi^2$: $\chi^2(df)$
    - df = k - 1 \hl{or} $(r-1)(c-1)$
    - going to be on the exam \textcolor{red}{NO}
    ```r
    pchisq()
    qchisq()
    ```
- $\sqcap$ Uniform: $U(a, b)$
    - a = min
    - b = max
    - going to be on the exam \textcolor{green}{YES}
    - seen in Lecture 13 (\underline{ONLY} for continuous random variable) 
    ```r
    punif()
    qunif()
    ```
========================================================
- Normal: $N(\mu, \sigma)$
    - $\mu =$ population mean
    - $\sigma =$ population standard deviation
    - going to be on the exam \textcolor{green}{YES}
    - Lecture 13 (continuous random variable) and Lecture 15 (sampling distribution of $\bar{x}$)
    ```r
    pnorm()
    qnorm()
    ```
- t: $t(df)$
    - df = n - 1 \hl{or computed via software}
    - going to be on the exam \textcolor{green}{YES}

========================================================

# Things that can be asked

- Boxplots
- Histograms
- \underline{Mean Inference $\rightarrow$ One and Two Populations}
    - t-Test
     ```r
     t.test()
     ```
     - Power Analysis
     ```r
     power.t.test()
     ```
     - ANOVA \& Post-Hoc

     ```r
     aov()
     TukeyHSD()
     ```
