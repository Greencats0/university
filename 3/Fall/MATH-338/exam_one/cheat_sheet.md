---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=1cm,right=1cm,top=1cm,bottom=1cm"
monofont: 'Source Code Pro'
---

\begin{center}
\textbf{MATH-338 Midterm 1 Study Guide}
\end{center}
\textbf{THEORY}

\par\noindent\rule{\textwidth}{0.4pt}

\begin{scriptsize}

\textbf{Day 2:} Independent events happen same time, not affecting one another (P(A $\cap$ B) = P(A)P(B)). Disjoint is the opposite (P(A $\cap$ B) = 0). Probability Mass Function (PMF) is a dictionary mapping of events to positive probabilities. Over an infinite amount of iterations, RVs converge to a number.

\textbf{Day 3:} \underline{Law of Large Numbers:} more times means more precise result. 

\textbf{Day 4:} \underline{Parameter:} any numerical quantity that characterizes a given population. \underline{Population proportion:} a percentage value associated with a population. \underline{Sample proportion:} the proportion of individuals in a sample sharing a certain trait ($\hat{p}$). Sample Mean($\bar{X}$). \underline{Sampling distribution:} probability distribution of statistic obtained through a large number of samples drawn (sample \textbf{must} be know).

\textbf{Day 5:} We want \underline{low bias and high variability.} Bias bad. Variability $\downarrow$ as the sample size $\uparrow$. \underline{Binomial Probability Distribution Conditions:} \underline{B}inary outcome (TF), \underline{I}ndependent (previous outcomes do \textbf{not} affect next.), \underline{N}umber of outcomes, \underline{S}uccess is equally likely. `X` denotes the number of successes and `n` is the number of elements in your sample. $\hat{P}$ does \textbf{NOT} have a binomial distribution.

\textbf{Day 6:} \underline{Interacting variables:} one variable can affect the another variable (non-independent). \underline{Confounding variable:} a factor that influences the results of an experiment. \underline{Block design:} split sample initially based on traits (possibly confounding) then randomly assign in those groups. \underline{Matched Pairs Design:} blocks sizes of two (only looking with two levels). \underline{Repeated Measures Design} two similar subjects have the same tests and those results are compared. \underline{Hawthorne Effect:} individuals know they are being experimented on.

\textbf{Day 7:} \underline{Sensitivity:} proportion of actual positive. \underline{Specificity:} proportion of actual negative. \underline{Positive Predictive Value:} proportion of positive tests that were actually positive. \underline{Negative Predictive Value:} same as above but for negative. \underline{Prevalence:} base rate.

\textbf{Day 8:} \underline{Neyman-Pearson Testing:} This test will allow us to make preemptive decisions based on conditions presented before the study is conducted. These are the theoretical outcomes WITHOUT taking any sample data. \underline{Null Hypothesis:} nothing unexpected (original hypothesis, H\textsubscript{0}). \underline{Alternate Hypothesis:} "something is happening and we should change our minds" (H\textsubscript{a}). \underline{Critical region:} range of values that corresponds to the rejection of H\textsubscript{0} at some chosen probability level. \underline{Type I Error:} occurs when a significance test results in the rejection of a true null hypothesis. \underline{Type II Error:} the data do not provide strong evidence that the null hypothesis is false.

\end{scriptsize}


\par\noindent\rule{\textwidth}{0.4pt}

\textbf{FORMULAS}

\begin{scriptsize}

\begin{tabular}{l | l}

\parbox{0.5\textwidth}{

\begin{itemize}

\item Mean of Probability Dist. : $\mu\textsubscript{x} = \Sigma x \times p(x)$
\item Variance : $\sigma^2\textsubscript{x} = \Sigma [x^2 \times P(x)] - \mu^2\textsubscript{x}$
\item Standard Deviation : $\sigma\textsubscript{x} = \sqrt{\sigma\textsubscript{x}}$ \underline{and} $\sigma\textsubscript{x+y} = \sqrt{\sigma\textsubscript{x} + \sigma\textsubscript{y}}$
\item Number successes : $X \sim B(n,p)$
\item Mean of binomial RV: $nP$
\item Variance of Bernoulli RV: $P(1-P)$
\item Variance of binomial RV: $nP(1-P)$
\item Standard deviation of binomial RV: $\sqrt{nP(1-P)}$
\item Bayes' Rule: $\frac{P(B|A)P(A)}{P(B)}$
\item P(B|A) = $\frac{number\, of\, outcomes\, in\, A\, \cap\, B}{number\, of\, outcomes\, in\, A} = \frac{P(A\, \cap\, B)}{P(A)} > 0$
\end{itemize}

}

&

\parbox{0.5\textwidth}{
\begin{flushright}
\begin{itemize}

\item Population proportion: $\hat{P} = \frac{X}{n}$
\item Variance($\hat{P}$) = $\frac{P(1-P)}{n}$
\item Standard Deviation($\hat{P}$) = $\sqrt{\frac{P(1-P)}{n}}$
\item Sensitivity: $\frac{TP}{TP + FN}$
\item Specificity: $\frac{TN}{TN + FP}$
\item PPV: $\frac{TP}{TP + FP}$
\item NPV: $\frac{TN}{TN + FN}$
\item Prevalence: $\frac{Actual\, Positive}{Actual\, Positive\, + \, Actual\, Negative}$
\item $\alpha = P(1) - $P(Concluded H\textsubscript{a} | H\textsubscript{0} is true)
\item Baseline $\alpha = 0.05$
\item $\beta = P(2) - $P(Concluded H\textsubscript{0} | H\textsubscript{a})
\item Power: $1 - \beta$

\end{itemize}
\end{flushright}
}

\end{tabular}


\end{scriptsize}

\par\noindent\rule{\textwidth}{0.4pt}

\textbf{ABBREVIATIONS AND MISC}

\begin{scriptsize}

\begin{tabular}{l | l}

\parbox{0.5\textwidth}{

\begin{itemize}

\item TP: True Positive
\item TN: True Negative
\item FP: False Positive
\item FN: False Negative
\end{itemize}

}

&

\parbox{0.5\textwidth}{
\begin{flushright}
\begin{itemize}

\item Independent events: $P(A \cap B) = P(A) \times P(B)$
\item Conditional probability: $P(A \cap B) = P(A) \times P(B|A)$ [Tree Mapping]
\end{itemize}
\end{flushright}
}

\end{tabular}


\end{scriptsize}
\par\noindent\rule{\textwidth}{0.4pt}
