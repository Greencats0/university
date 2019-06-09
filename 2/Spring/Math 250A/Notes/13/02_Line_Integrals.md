# Section 13.2: Line Integrals

## Symbol Chart

\begin{center}
 \begin{tabular}{||c||} 
 \hline\hline
 Closed Line Integral \\ [0.5ex] 
 \hline
 $\oint_C$ \\
 \hline
 \end{tabular}
\end{center}


\pagebreak

### Definition

Let $\vec{r}$ : I &rarr; ${\rm I\!R}^3$, $\vec{r(t)}$ = $\langle x(t), y(t), z(t) \rangle$
Let *f*: $(D)$ $\leq$ ${\rm I\!R}^3$ &rarr; ${\rm I\!R}$ be a continuous function of the curve $\vec{r}$ $\subseteq$ $(D)$

\underline{Problem:} Determine the total mass of a solid lying along the image of the curve $\vec{r}$, with density *f*. 

Assume *f* $\geq$  0. Let $\Delta$ be a division of the curve into *n* sub-arcs.

![Line Integral Subarcs](assets/Line\ Integral\ Subarcs.png)

\underline{Define:} The line integral of function *f* along $(C)$ = the image of the $\vec{r}$

$$\lim_{n\to\infty} \sum_{k=1}^{n} f(x,y,z) \Delta S_k$$ 

The above form can be rewritten in the Riemann Integral with the form of:

$$\oint_C f(x,y,z) ds$$

\pagebreak

### Solving

1. Find a parameterization for $(C)$:  

	$\vec{r(t)}$ = $\langle x(t)\vec{i} + y(t)\vec{j} + z(t)\vec{k} \rangle$

	a $\leq$ t $\leq$ b

2. Compute the arc length [speed]
	$$ ds = \sqrt{\frac{d(x)}{d(t)}^2 + \frac{d(y)}{d(t)}^2 + \frac{d(z)}{d(t)}^2} dt$$

3. Set up the Riemann Integral
	$$ \int_a^b f(x(t), y(t), z(t)) ds$$

\pagebreak

### Example 1

$$\oint_C x^2y+2 ds = I $$

Where $(C)$ is the upper half of the circle $x^2 +y^2 = 1$

\underline{Solution:} 

$$\vec{r} : [0, \pi] \rightarrow {\rm I\!R}^2 $$

$$\vec{r(t)} = \cos(t)\vec{i} + \sin(t)\vec{j}$$

$$ ds = \sqrt{(\frac{d(x)}{d(t)})^2 + (\frac{d(y)}{d(t)})^2} = \sqrt{(\sin(t))^2 + (\cos(t))^2} = 1 dt$$

$$ I = \int_0^\pi (2+\cos^2(t)sin(t)) * 1 dt  = 2t - \left. \frac{\cos^3(t)}{3} \right|_{t=0}^\pi $$

$$ \boxed{2\pi + \frac{2}{3}} $$

\pagebreak

### Example 2

Integrate $$ f(x,y,z) = x + \sqrt{y} - z^2 $$ over the linear path from A(0,0,0) to B(1,1,1). Need a parameter for the line segment from A to B

\underline{Solution:}

$$ \vec{AB} = \vec{OB} - \vec{OA} = \langle 1, 1, 1 \rangle - \langle 0, 0, 0 \rangle $$

$$ [AB]: x = 0 + 1(t),  y = 0 + 1(t),  z = 0 + 1(t) |  0 \leq t \leq 1 $$
$$  ds = \sqrt{1 + 1 + 1} = \sqrt{3} dt $$ . This is the magnitude of $\vec{AB}$

$$ \int_0^1 (t + \sqrt{t} + - t^2) \sqrt{3} dt $$

$$ [\frac{t^2}{2} + \frac{t^\frac{3}{2}}{\frac{3}{2}} - \frac{t^3}{3}] |_{t=0}^1 \sqrt{3} = \boxed{\frac{5\sqrt{3}}{6}} $$

\pagebreak

### Example 3

Find the mass of a thin wire lying along the curve $$ \vec{r(t)} = \sqrt{2} \vec{i} + \sqrt{2} \vec{j} + (4-t^2)\vec{k} | 0 \leq t \leq 1 $$

\underline{Solution:}

$$ {\vec{r(t)}\,}' = \langle \sqrt{2}, \sqrt{2}, -2t \rangle $$

$$ | {\vec{r(t)}\,}' |  = \sqrt{4t^2 + 2 + 2} = 2\sqrt{t^2 + 1} $$

$$ M = \int_0^1 3t * 2\sqrt{t^2 + 1} dt = 3 * \frac{(t^2+1)^\frac{3}{2}}{\frac{3}{2}} |_{t=0}^1 = \boxed{2(2\sqrt{2} - 1)} $$ 

## Work Type Integrals

$$ \boxed{W = \int_a^b \vec{F} \enspace \cdot \enspace \vec{T} \enspace ds} $$

### Definition

Let $\vec{F}$ be a continuous vector field defined along a smooth curve $(C)$ given by $\vec{r(t)}$ $\enspace$ | $\enspace$ a $\leq$ t $\leq$ b .

Then, the line integral of $\vec{F}$ along $(C)$ is:

$$ \oint_C \vec{F} \: \cdot \: \vec{T} \, ds = \oint_C  \vec{F} \: \cdot \: d\vec{r} = \int_a^b \vec{F\vec{r(t)}} \cdot \: {\vec{r(t)}\,}' dt $$

\pagebreak

## Line Integrals of Vector Fields

- Unit tangent depends on parameterization/orientation

### Definition

Let $\vec{F}$ be a continuous vector field along a curve $(C)$: $\vec{r(t)}$ = $\langle x(t), y(t), z(t) \rangle$ with $x, y, z$ differentiable.

Then the work type integral is:

$$ W = \oint_C \vec{F} \: \cdot \: \vec{T} \; ds = \oint_C \vec{F} \: d\vec{r} = \boxed{\int_a^b \vec{F\vec{r(t)}} \cdot \: {\vec{r(t)}\,}' dt}$$ 

### Notations

$\vec{F\vec{r(t)}}$ $\leftarrow$ represents the vector field F at the point $\vec{r(t)}$

![Flux of Vector Field](assets/Flux\ Of\ Vector\ Field.jpg)

\pagebreak

### Example

Find the work done by $$ \vec{F(x,y)} = x^2\vec{i} - xy\vec{j} $$

moving along the quarter-circle $$ \vec{r(t)} = \cos(t)\vec{i} + \sin(t)\vec{j} \: | 0 \leq t \leq \frac{\pi}{2}$$

\underline{Solution:}

We know:

\begin{table}[h!]
 \begin{tabular}{||c|c||} 
 \hline\hline
 x(t) & y(t) \\ [0.5ex] 
 \hline
 $\cos(t)$ & $\sin(t)$ \\
 \hline
 \end{tabular}
\end{table}

Replace all x and y values accordingly to achieve two vectors: 

$$ \vec{F}(\vec{r}(t)) = \langle \cos^2(t), -\sin(t)\cos(t) \rangle$$
$$ {\vec{r(t)}\,}' = \langle -\sin(t)\cos(t) \rangle $$

Set up the integral and solve:

$$ W = \int_0^\frac{\pi}{2} \langle \cos^2(t), -\sin(t)\cos(t) \rangle \: \cdot \: \langle -\sin(t)\cos(t) \rangle $$
$$ W = \int_0^\frac{\pi}{2} (-\sin(t)cos^2(t) - \sin(t)cos^2(t)) \; dt $$
$$ W = -2\int_0^\frac{\pi}{2} (sin(t)cos^2(t)) $$
$$ W = -2(\frac{-\cos^3(t)}{3}|_{t=0}^\frac{\pi}{2}) $$
$$ \boxed{-\frac{2}{3}} $$
This object is slowing down, as work can be both positive and negative.

\pagebreak

### Example 2
Evaluate $$\oint_C \vec{F} \: d\vec{r} $$

where:

$$ \vec{F}(x,y,z) = \langle xy, yz, zx \rangle $$

over $(C):$
\begin{gather*}
\begin{cases}
x = t \\
y = t^2 \\
z = t^3
\end{cases}
\end{gather*}

$$ 0 \leq t \leq 1 $$

\underline{Solution:}

$$ W = \int_0^1 \langle t^3, t^5, t^4 \rangle \; \cdot \; \langle 1, 2t, 3t^2 \rangle dt = \int_0^1 (t^3 + 2t^6 + 3t^6) dt $$
$$ W = \int_0^1(5t^6+t^3) $$
$$ \frac{t^4}{4} + \frac{5t^7}{7} |_{t=0}^1 $$
$$ \boxed{\frac{27}{28}} $$
