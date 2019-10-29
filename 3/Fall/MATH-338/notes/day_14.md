---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
toc: true
---

# Day 14

\newpage

## Continuous Random Variables

Can take any real number (${\rm I\!R}$) value within any given interval.

We cannot use a probability mass function so we will instead use a probability \hl{density} function (PDF) denoted as $f(x)$

### Properties

- The probability of being in an interval (a, b] is:
    $$\int_{a}^{b} f(x) dx = \int_{-\infty}^{b} f(x) - \int_{-\infty}^{a} f(x) dx $$
    - This is considered the area under the curve between a and b
- $P(X=x) = 0 \, \, \forall x$
    - $P(X \le x) = P(X < x)$
    - $P(X \ge x) = P(X > x)$

$f(x)$ is displayed graphically as a \underline{density curve}

### Properties of $f(x)$

- $\forall \, \, x \in {\rm I\!R}, \, f(x) \ge 0$
    - Density never goes below x-axis
- $\int_{-\infty}^{\infty} f(x) dx = 1$

Mean of continous random variable: $\mu_x = \int_{-\infty}^{\infty} x \times f(x) dx$

Variance of continous random variable is $\sigma^2 = \int_{-\infty}^{\infty} (X = \mu_x)^2 f(x) dx$

\newpage

## Uniform Random Variable

![Graphical Representation](assets/uniform_rv){width=50%}

$X \sim U(a, b)$

### Example : Standard Uniform Random Variable

$X \sim U(0, 1)$

#### Find

- P(X $\ge$ 0.3)
- P(X = 0.3)
- P(0.3 < X $\le$ 1.3)
- P(0.2 $\le$ X $\le$ **or** 0.7 $\le$ X $\le$ 0.9)
- P(X is not in the interval (0.4, 0.7))

##### Answers

- $\sqcap = (0.7) \times (1) = 0.7$
- $\sqcap = 0$
    - \hl{The probability of being exactly on a point in the infinite sum will **always** be 0.}
    <!--- \hl{Since a = b and to find the height is $\frac{1}{b-a} \times (b-a)$, there is no rise/run component. This makes the area 0.}-->
- $\sqcap = (0.7) \times (1) = 0.7$
    - \hl{Do not keep shading when there is no density curve, meaning it is a hard stop at $X = 1$}
- $\sqcap = ((0.25 - 0.2) \times \frac{1}{0.25 - 0.2})  + ((0.91 - 0.7) \times \frac{1}{0.91 - 0.7}) = 0.25$
- $\sqcap = 0.4 + 0.3 = 0.7$

\newpage

## Normal Random Variable

$f(x) = \frac{1}{\sigma\sqrt{2\pi}}\,e^{ -\frac{(x-\mu)^2}{2\sigma^2} }$

**Density curve is also a "bell curve"**

### Empirical (68-95-99.7) Rule

![Bell Curve](assets/normal_curve)

$X \sim N(\mu \, , \sigma)$

\newpage

## Standardization

It may be useful to \underline{standardize} distributions to compare 2 variables with same density curve shape but different scales.
For normal distributions $X \sim N(\mu, \sigma)$, we convert to \underline{Z-Scores} $Z \sim N(0, 1)$

$$Z = \frac{x - \mu}{\sigma} = \frac{value \, - \, mean \, of \, distribution}{standard \, deviation}$$

$$f(z) = \frac{1}{\sqrt{2\pi}} \times \Eulerconstant \textsuperscript{-\frac{1}{2}Z^2}$$

$$P(Z \le z) = P(X \le x)$$

"Cumulative proportion"/"Cumulative probability"
