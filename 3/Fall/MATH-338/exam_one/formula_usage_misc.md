---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
---

# Formula Usage Misc

## lower.tail = FALSE

\begin{flushleft}
$$\sum_{x = 0}^{k} f(x) = 0.05$$
\end{flushleft}

This is because the index starts at zero and moves to a delimeter denoted as `n`.

## lower.tail = TRUE

\begin{flushleft}
$$\sum_{x = k}^{n} f(x) = 0.05$$
\end{flushleft}

This is because the summation occurs across a range where the starting term is not 0.
