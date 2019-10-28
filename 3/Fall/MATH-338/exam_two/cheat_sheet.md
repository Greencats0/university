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

\textbf{Day 16:} error: since there is some error while taking sample data, we do allow for some buffer. We also do not measure exact but to a tolerance which is influenced by the buffer above. The mean of the sampling distribution of the 


\end{scriptsize}

\par\noindent\rule{\textwidth}{0.4pt}

\textbf{FORMULAS}

\par\noindent\rule{\textwidth}{0.4pt}

\begin{scriptsize}
\begin{tabular}{l | l}

\parbox{0.5\textwidth}{

\begin{itemize}

\item $\sqcap = width \, \times \frac{1}{width}$ (finite curve)
\item $Z = \frac{x - \mu}{\sigma}$ (z-score)
\item $X \sim N(\mu \, , \sigma)$
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
