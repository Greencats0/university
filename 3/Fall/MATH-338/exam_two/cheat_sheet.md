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

\textbf{Day 15:} unimodal: one hump, bimodal: two humps. Mean is resistant whereas the mean is subject to change. Density curves decay to histograms (integral $\rightarrow$ to Reimann Sum). Whisker plots are an effective method to determine if a data set contains outliers (data points not belonging to the sample set)

\textbf{Day 16:} error: since there is some error while taking sample data, we do allow for some buffer. We also do not measure exact but to a tolerance which is influenced by the buffer above. \underline{Central Limit Theorem:} when population size is "large enough" $\bar{x}$ is an approximation. Higher skew and outliers suggest a larger $n$ value.

\textbf{Day 18:} As $n \uparrow, \, SEM \downarrow$.Two-tailed tests take the upper and lower limit of the curve and the significance level ($\alpha$) is the cut off point of being \emph{statistically significant}. Treat as critical region. If in CR, then accept alt. Else accept null.

\textbf{Day 19:} H\textsubscript{1}: $\mu < \mu\textsubscript{0} \leftarrow$ left side. H\textsubscript{1}: $\mu \ne \mu\textsubscript{0} \leftarrow$ \textbf{n} $\sigma$ on both side but no middle. H\textsubscript{1}: $\mu > \mu\textsubscript{0} \leftarrow$ lower.tail = TRUE. Population distribution normality $\implies$ sample population distribution normality. \underline{Matched pairs design:}  paired subjects receives their respective treatment or an individual gets two treatments. Also a subset of block design. \underline{Common hypothesis:} H\textsubscript{0}: $\mu\textsubscript{d} = 0$ (no difference) and H\textsubscript{a}: $\mu\textsubscript{d} \ne 0$ (difference). \underline{Matched-pairs t-test reqs:} large population, normal distribution, $\sigma$ is unknown.

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
\item IQR = $Q\textsubscript{3} - Q\textsubscript{1}$
\item $K = 1.5$
\item Lower fence: $Q\textsubscript{1} - K \times IQR$
\item Upper fence: $Q\textsubscript{3} + K \times IQR$

\end{itemize}
\end{flushright}
}

\end{tabular}
\end{scriptsize}
