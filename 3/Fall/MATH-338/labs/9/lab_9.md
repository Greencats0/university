---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
---

# Lab Assignment 9

Jared Dyreson

TR @ 11:30 - 14:15

MATH-338, Dr. Wynne

1. What is the power under the new alternative H\textsubscript{1}: `p = 0.6`?
	- \textbf{The power would be 0.425878} 
2. What is the power under the new alternative H\textsubscript{1}: `p = 0.8`?
	- \textbf{The power would be 0.9991866}
3. How does the power change as the alternative value of p gets further from the null value of 0.5?
	- \textbf{The power increases as it deviates upward from the null value of 0.5}
4. What is the critical region for $\alpha$ = 0.01? Is it a larger or smaller critical region compared to $\alpha$ = 0.05?
	- \textbf{The new critical region is going to be 36 which is higher than the original value of 32 which was initially found with an alpha of 0.05}
5. Change `crit.value` to the endpoint of the new critical region (from Question #4). Then, run that line and the lines below it to compute power. What is the new power?
	- \textbf{The new power is going to be 0.5788821 when you change the critical value}
6. Repeat the steps using $\alpha$ = 0.10. What is the power of the test at this new $\alpha$ value?
	- \textbf{The new power is going to be 0.09055912 when the value of alpha changes to 0.10}
7. How does the power change as the probability of Type I Error increases? Why do you suspect it changes in that direction?
	- \textbf{When the $\alpha$ changes, the critical value range will subsequently increase as well. This can be seen in the chart below}
	- $\alpha = 0.01 \rightarrow x \ge 36$
	- $\alpha = 0.05 \rightarrow x \ge 33$
	- $\alpha = 0.1 \rightarrow x \ge 32$
	- \textbf{This change can be attributed to the Type I Error because choosing lower values of $\alpha$ make it harder to reject a null hypothesis.}
	- \hl{The act of rejecting a true null hypothesis is considered a Type I Error}

8. What is the critical region for *n = 30*
	- \textbf{The critical region is 25}
9. Change `crit.value` to the endpoint of the new critical region (from Question #8). Then, run that line and the lines below it to compute power. What is the new power?
	- \textbf{The new power is 0}
10. Repeat the steps using n = 100. What is the power of the test using this new sample size?
	- \textbf{The new power for the new sample size is going to be 1}
11. How does the power change as sample size increases? Why do you suspect it changes in that direction? (Hint: think about the critical regions in terms of sample proportions!)
	- \textbf{As the sample size increases, the power increases as well. This makes sense because as you get more individuals for a study, the data becomes that more accurate. In terms of a critical region, there is a broader range of values you have access to.}
\newpage

# External Links

- [Consequences of errors and significance (STATS)](https://www.khanacademy.org/math/ap-statistics/tests-significance-ap/error-probabilities-power/a/consequences-errors-significance)

