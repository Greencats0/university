---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
    \usepackage{subcaption}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
toc: true
---

\textbf{NOTE:} all equations containing the $\cdot$ symbol denote a DOT PRODUCT. Multiplication in formulas will be denoted with the $\times$ symbol to avoid confusion.

\newpage

# Kinetic Energy and Work

\underline{Kinetic:} energy of motion.

\underline{Work:} Force (along the direction of motion) $\cdot$ Displacement (two vectors dotted will always result in a scalar)

It is important to be aware of the work done by what force on what object.

If an applied force is referenced, it is an applied force
    - For example: If work done by "you" as opposed to work done by a spring force, etc


## Free Body Diagram

![Kinetic Energy](assets/kinetic_fbd){width=70%}

- Work done by $\vec{F}$ (pulling force)
- Work done by a specified force or combination of forces
    - Vector sum is denoted by $\Sigma$
    - $\vec{W}\textsubscript{net} = (\Sigma \vec{F}\textsubscript{i}) \cdot \Delta \vec{r}$
    - $\vec{F}\textsubscript{net} = \vec{W}\textsubscript{friction} + \vec{V}\textsubscript{normal} + \vec{W}\textsubscript{applied force} + \vec{W}\textsubscript{gravity}$
    - $\vec{W}\textsubscript{friction} < 0$ and will always act to decrease the kinetic motion.

## Work Formula

### Constant

$\vec{W} = \vec{F} \cdot \Delta\vec{r} = \vec{F} \cdot \Delta x \hat{i}$

This formula works when there is a \underline[constant] force

### Variable

$\vec{W} = \vec{F} \cdot d \vec{r}$

$\vec{W} = \int_{i}^{f} \vec{F} \cdot d\vec{r} dx$

This applies when the force is variable

\hl{Note:} $\vec{F} \cdot \Delta \vec{r} = |\vec{F}| \times |\Delta \vec{r}| cos(\theta)$

### General

$W = \int_{x\textsubscript{i}}^{x\textsubscript{f}} F(x) dx$

## 1D Constant Acceleration

$((\vec{V}\textsubscript{f})^2 - (\vec{V}\textsubscript{o})^2) = 2\vec{a}\Delta x$

This is derived from Newton's 2\textsuperscript{nd} Law

$\vec{a} = \frac{\vec{F}\textsubscript{net, ext}}{m}$

### Kinetic Energy Formula

$$K = \frac{m}{2} \times v^2$$

### 1-D Work Energy Theorem

$$\vec{F}\textsubscript{net, ext} \Delta x = \vec{W}\textsubscript{net}$$

$$\frac{m}{2} \times ((\vec{V}\textsubscript{f})^2 - (\vec{V}\textsubscript{o})^2) = \vec{W}\textsubscript{net}$$


## Units for Work

$\vec{W} \sim \vec{F} \times \Delta x \sim 1N \times 1 \, meter = \, Joule$

\hl{Kinetic energy has the same units as work}

## Displacement Vector

$\vec{r}\textsubscript{i} + \Delta \vec{r} = \vec{r}\textsubscript{f}$

$\Delta\vec{r} = \vec{r}\textsubscript{f} - \vec{r}\textsubscript{i}$

# Work done by a Spring Force

$\Delta\vec{K} = \vec{W}\textsubscript{net} = \vec{K}\textsubscript{f} - \vec{K}\textsubscript{i}$

Above is the kinetic-energy theorem

$$\vec{W}\textsubscript{net} = \int_{a}^{b} \vec{F}_n \cdot d \vec{r} = \vec{F}\textsubscript{net} \cdot \Delta\vec{r}$$

# Work done by a Gravitational Force

Tension does positive work, gravity does negative work

\newpage

# Spring Force

A variable force from a spring

\underline{Relaxed state:} neither compressed or extended

\underline{Restoring force:} attempting to put spring into a relaxed state

\underline{Displacement is the opposite of the spring force}

## Hooke's Law

$F\textsubscript{s} = -k\Delta x$

- $\vec{W}\textsubscript{net} > 0 \rightarrow \Delta k > 0 \rightarrow KE \uparrow$
- $\vec{W}\textsubscript{net} < 0 \rightarrow \Delta k < 0 \rightarrow KE \downarrow$

By integrating the function $\vec{F}\textsubscript{s}$ with respect to x, we can develop a formula that looks like this:

$$\vec{W}\textsubscript{s} = \frac{1}{2}k((x\textsubscript{i})^2 - (x\textsubscript{f})^2)$$

If starting from **relaxed state**, then $\vec{W}\textsubscript{s} = -\frac{1}{2}kx^2$

\newpage

# Power

Symbol "P" is used to denote power and it is the time rate of doing work.

$\frac{dW}{dt} \rightarrow$ this is instantaneous power (power at any given place in time)

Think acceleration; how fast the velocity changes per second of time.


$P\textsubscript{average} = \frac{W}{\Delta t} = \int_{i}^{f} P(t) dt$


# Potential Energy

Symbol "U"._

$\Delta U = -W$

Change in potential energy is negative work.

$\vec{F}\textsubscript{net} = \vec{F}\textsubscript{c} + \vec{F}\textsubscript{nc}$

Total force is the combination of conservative forces (forces that aim to keep the system in equilibrium) and non-conservative forces (forces that appose conservative forces)

- For conservative forces we can define/associate a potential energy "U" with that force{s}

## General Form of Work

$\Delta U = -\int_{x\textsubscript{i}}^{x\textsubscript{f}} F(x) dx$

\newpage

## Change in Potential Energy

Only depends on the initial and final points, not the path taken between them.

$U + C = (U\textsubscript{f} + C) - (U\textsubscript{i} + C) = \Delta U$

$\Delta U\textsubscript{g} = -Wg = mg\Delta y = mgh$

Potential energy is dependent on how high the object is and how massive it is.

## Work Energy Theorem : Potential

$W\textsubscript{c} + W\textsubscript{nc} = W\textsubscript{net} = \Delta K = - \Delta U - W\textsubscript{nc}$

- Valid for both $\vec{F}\textsubscript{c}$ and $\vec{F}\textsubscript{nc}$ forces

$\therefore \, \Delta K + \Delta U = W\textsubscript{nc}$ These are considered external "agents"

\hl{Work energy theorem is present when conservative and non-conservative forces are present}

# Mechanical Energy

All energy in a given system.

It is denoted by the letter "E".

$E = K + U$

Kinetic plus potential energy

$\therefore \, \, \Delta K + \Delta U$

Change in total work energy is work done by non-conservative forces

When no work is done by non-conservative forces (W\textsubscript{nc} = 0):

$\Delta E = \Delta K + \Delta K = 0$

$\implies E\textsubscript{f} = E\textsubscript{i}$

This is the conservation of mechanical energy, where energy is not lost in the system. Small amounts of energy can be used to trigger a large energy release.

\newpage 

## Reading a Potential Energy Curve

$F(x) = \frac{dU(x)}{dx}$

$F \Delta x =  \Delta W = - \Delta U$

- for "small enough" $\Delta x$, the following can be inferred $\rightarrow \Delta  U = -\vec{F}\Delta x$

\textbf{Reimann Sum Equivalent:} $\lim_{\Delta x\to\infty} \frac{\Delta U}{\Delta x} = F = -\frac{du}{dx}$ 

The above is the same as saying:

\textbf{Infinite sum:} $U = -\int F(x) dx \implies F = -\frac{du}{dx}$

\hl{Both are the same and can be used interchangeably.}

![Potential Energy Curve](assets/potential_energy_curve)

The following curve can be interpreted as:

- Low points represent the "restoring force", which is stable equilibrium.
- Peaks represent unstable equilibrium and can be activated with little force.

Equilibrium merely states that the sum ($\Sigma$) of the forces is zero. It does not mean however it is stable to stay there for a prolonged period of time. Since it is it requires a given amount of force $\vec{F}$

The above curve is a function of potential energy with respect to which is $U(x)$. These are called parametric functions, where the x position is a *parameter* of the function of potential energy. This allows us to find instantaneous potential energy **anywhere** along the x axis.

\newpage

### Inherently Unstable

![Cubic Graph](assets/cubic_graph){width=50%}

Any given force will a not be able to overcome the steep curve and will either rest in the recess (0, 0) or continue to drop off on the -x direction.


\newpage

# Conservation of Mechanical Energy

Recall that:

$E\textsubscript{mechanical} = K + U$

To conserve mechanical energy, this means that no amount of energy in a given system can leave. Therefore, this can only be implemented in a universe where friction is non-existent and thermodynamics does not work. These are examples of how energy can leave a given system.


