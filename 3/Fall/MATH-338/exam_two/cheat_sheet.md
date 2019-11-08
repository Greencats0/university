---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=1cm,right=1cm,top=1cm,bottom=1cm"
monofont: 'Source Code Pro'
---

\pagenumbering{gobble}

\begin{center}
\textbf{MATH-338 Midterm 2 Cheat Sheet}
\end{center}
\textbf{THEORY}

\par\noindent\rule{\textwidth}{0.4pt}

\begin{scriptsize}

\textbf{Day 14:} probability density function is represented an integral with function $f(x)$. Our probability lies within the curve and is always 1. Density curve $\rightarrow$ bell curve. Z-Score allows us to have a universal standard for density curves with different scales. They are directly proportional to the standard deviation and the delta from the mean of the graph.

\textbf{Day 15:} unimodal: one hump, bimodal: two humps. Mean is resistant whereas the mean is subject to change. Density curves decay to histograms (integral $\rightarrow$ to Reimann Sum). Whisker plots are an effective method to determine if a data set contains outliers (data points not belonging to the sample set). \underline{Left skew:} long left tail. Sloping $\rightarrow$. \underline{Right skew}: long right tail. Sloping $\leftarrow$

\textbf{Day 16:} error: since there is some error while taking sample data, we do allow for some buffer. We also do not measure exact but to a tolerance which is influenced by the buffer above. \underline{Central Limit Theorem:} when population size is "large enough" $\bar{x}$ is an approximation. Higher skew and outliers suggest a larger $n$ value.

\textbf{Day 18:} As $n \uparrow, \, SEM \downarrow$.

\textbf{Day 19:} H\textsubscript{1}: $\mu < \mu\textsubscript{0} \leftarrow$ left side. H\textsubscript{1}: $\mu \ne \mu\textsubscript{0} \leftarrow$ \textbf{n} $\sigma$ on both side but no middle. H\textsubscript{1}: $\mu > \mu\textsubscript{0} \leftarrow$ lower.tail = TRUE. Population distribution normality $\implies$ sample population distribution normality. \underline{Matched pairs design:}  

\textbf{Day 20:} \underline{Two Independent Samples t-Test:} two unrelated treatments into one numerical response variable measured in two independent groups. Two different $\mu\textsubscript{1}$ and $\mu\textsubscript{2}$. NHST approach; identify $\mu\textsubscript{i}$


\end{scriptsize}

\par\noindent\rule{\textwidth}{0.4pt}

\textbf{FORMULAS}

\par\noindent\rule{\textwidth}{0.4pt}

\begin{scriptsize}
\begin{tabular}{l | l}

\parbox{0.5\textwidth}{

\begin{itemize}
\setlength\itemsep{0.25em}
\item $\sqcap = width \, \times \frac{1}{width}$ (finite curve)
\item $Z = \frac{x - \mu}{\sigma}$ (z-score)
\item $X \sim N(\mu \, , \sigma)$
\item $\bar{X} \sim N(\mu, \frac{\sigma}{\sqrt{n}})$
\item $SEM = \frac{s}{\sqrt{n}}$
\item $t = \frac{\bar{X} - \mu}{\frac{s}{\sqrt{n}}}$

\item $t = \frac{\bar{x}}{\sigma\textsubscript{$\bar{x}$}}$

\item $t = \frac{(\bar{x}\textsubscript{1} - \bar{x}\textsubscript{2})}{\sqrt{\frac{(s\textsubscript{1})^2}{n\textsubscript{1}} +\frac{(s\textsubscript{2})^2}{n\textsubscript{2}}}} \sim t(K)$ [NHST]
\item $df = n-1$
\end{itemize}

}

&

\parbox{0.5\textwidth}{
\begin{flushright}
\begin{itemize}
\setlength\itemsep{0.25em}
\item IQR = $Q\textsubscript{3} - Q\textsubscript{1}$
\item $K = 1.5$
\item Lower fence: $Q\textsubscript{1} - K \times IQR$
\item Upper fence: $Q\textsubscript{3} + K \times IQR$
\item $t = \frac{\Delta\bar{x} - \Delta\mu}{\frac{\Delta s}{\sqrt{n}}}$

\end{itemize}
\end{flushright}
}

\end{tabular}
\end{scriptsize}
\par\noindent\rule{\textwidth}{0.4pt}
\textbf{FRAMEWORK FLOW CHART}
\par\noindent\rule{\textwidth}{0.4pt}

\begin{scriptsize}
\begin{tabular}{l | l}

\parbox{0.5\textwidth}{

\begin{normalsize}
\textbf{NPHT}
\end{normalsize}
\begin{itemize}

\item Parameter is $\mu$ [population mean]. $\mu\textsubscript{0} = \mu\textsubscript{1}$
\item $\bar{X}$ is sample mean. Under CLT, normal distribution at $\mu\textsubscript{0}$ for H\textsubscript{0} and $\mu\textsubscript{1}$ for H\textsubscript{1}.
\item We accept H\textsubscript{0} if \underline{\underline{not}} in CR.

\end{itemize}
\begin{normalsize}
\textbf{N-P Power Analysis}
\end{normalsize}
\begin{itemize}
\item Define parameter and its value under H\textsubscript{0} and H\textsubscript{1}
\item Define a test statistic and its sampling distribution under both hypotheses.
\item Use $\alpha$ to compute critical region
\item Compute power and compare to 80% threshold
\end{itemize}
\begin{normalsize}
\textbf{One-Sample T-Statistic [NP]}
\end{normalsize}
\begin{itemize}
\item If t\textsubscript{observed} in CR, then accept H\textsubscript{1}: $\mu = \mu\textsubscript{1}$. Else accept H\textsubscript{0}: $\mu = \mu\textsubscript{0}$
\end{itemize}
\begin{normalsize}
\textbf{Two-Tailed Test}
\end{normalsize}
\begin{itemize}
\item Take the upper and lower limit of the curve and the significance level ($\alpha$) is the cut off point of being \emph{statistically significant}. Treat as critical region. If in CR, then accept H\textsubscript{1}. Else accept H\textsubscript{0}.
\end{itemize}
}

&

\parbox{0.5\textwidth}{
\begin{normalsize}
\textbf{NHST}
\end{normalsize}
\begin{flushright}
\begin{itemize}

\item Define a parameter and it's value under H\textsubscript{0}.
\item Define an interval representing an inequality
\item Define a test statistic and its sampling distrubution under H\textsubscript{0}
\item Compute p-value. P-Value $\le$ sig level $\implies$ reject H\textsubscript{0} \& accept H\textsubscript{1}. P-Value > sig level $\implies$ fail to reject H\textsubscript{0}. Can only be >, < $\ne$.

\end{itemize}
\end{flushright}
\begin{normalsize}
\textbf{Two-Sided Test}
\end{normalsize}
\begin{flushright}
\begin{itemize}
\item \textbf{Neyman-Pearson}
\item Critical region is $\frac{1}{2}$ left tail and $\frac{1}{2}$ right tail of sampling distribution under H\textsubscript{0}. Power will $\downarrow$.
\item \textbf{NHST}
\item Find the "one-sided" p-value and double it.
\end{itemize}

\end{flushright}
\begin{normalsize}
\textbf{Matched Pairs t-Test}
\end{normalsize}
\begin{itemize}
\item Paired subjects receives their respective treatment or an individual gets two treatments. Also a subset of block design. 
\item H\textsubscript{0}: $\mu\textsubscript{d} = 0$ (no difference) and H\textsubscript{a}: $\mu\textsubscript{d} \ne 0$ (difference). 
\item \underline{Requirements:} large population, normal distribution, $\sigma$ is unknown. 
\end{itemize}
\begin{flushright}
\end{flushright}
}
\end{tabular}
\end{scriptsize}
