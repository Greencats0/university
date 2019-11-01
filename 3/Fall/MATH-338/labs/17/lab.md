---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
---

\begin{flushleft}

Jared Dyreson

MATH-338 @ 11:30 - 14:15
\end{flushleft}

\begin{center}
\textbf{LAB 17}
\end{center}

1. Compute the standard error of the mean for the first sample.

- $\frac{s}{\sqrt{n}} = \frac{.609}{2} = 0.3045$

2. For the first sample, compute the t-statistic corresponding to the sample mean.

- $\frac{2.0745 - 1.7}{0.3045} = 1.229885057$

3. Paste your histogram of the 1000 t-statistics below. How is the distribution of the t-statistics similar to a standard normal distribution? How is it different?

- Please see second to last page for the graph. It is similar to the normal distribution because it looks like a bell curve but it does not look as precise.

4. What are the degrees of freedom associated with this t-statistic?

- Degrees of freedom = $n-1 = 4-1 = 3 \implies df(3)$

5. Compute the standard error of the mean for the first new sample.

- $\frac{s}{\sqrt{n}} = \frac{.609}{\sqrt{100}} = \frac{0.609}{10} = 0.0609$

6. For the first new sample, compute the t-statistic corresponding to the sample mean.

- $\frac{2.0745 - 1.7}{0.0609} = 6.149425287$

7. Create a histogram of the 1000 new t-statistics and paste it below. Overlay both the density curve and the normal curve.

- Please see last page for attached histogram

8. What are the degrees of freedom associated with this t-statistic?

- Degrees of freedom = $n-1 = 100-1 = 99 \implies df(99)$

9. For a sample of size 4, what is the probability of obtaining a sample mean at least 2 standard errors away from the population mean (t > 2 or t < -2)? What about for a sample of size 100? 

- For sample size of n = 4
    - $P(t > 2) + P(t < -2)$
    ```r
      a <- pt(2, 3, lower.tail = FALSE)
      b <- pt(-2, 3)
      print(a + b)
      [1] 0.139326
    ```

- For sample size of n = 100
    - $P(t > 2) + P(t < -2)$
    ```r
      a <- pt(2, 99, lower.tail = FALSE)
      b <- pt(-2, 99)
      print(a + b)
      [1] 0.04823969
    ```
10. Briefly describe how the standard error and t-distribution change as the sample size increases.

- As your sample size increases, the standard error will subsequently lower. The t-distribution will increase when the sample size increases as well.
