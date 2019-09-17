---
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
---

# Formula Cheat Sheet

## Velocity

Rate at which a particle moves with per unit per second

### One dimension

Formula: \hl{$V=V\textsubscript{o} + at$}

Usage: Find the velocity of a particle in one dimensional space

Example: A ball is thrown from the top of a six story building, find the velocity of the particle when it hits the ground after 10 seconds. Assume no air resistance and no terminal velocity.

- $a = 9.8 m/s$
- $t = 10 s$
- $v\textsubscript{o} = 0$

$\therefore v = 0 + 9.8(10) = 98 m/s\textsuperscript{2}$


## Free Fall Acceleration

Formula: \hl{$y = y\textsubscript{o} + v\textsubscript{o}t + \frac{1}2{}at\textsuperscript{2}$}

Usage:

Example: A ball is thrown from the top of a building 90 meters above the ground as a \emph{projectile}. It takes 10 seconds for the ball to hit the ground. What was the initial velocity of the ball?

- $a = -g = -9.81 m/s$
- $t = 10 s$
- y = 90 m


$0 = 90 + (10)V\textsubscript{o} - 490.5$

$0 = -400.5 + 10V\textsubscript{o}$

$400.5 = 10V\textsubscript{o}$

$V\textsubscript{o} = 40.05$

**Apply velocity formula:** $V = 40.05 - 9.81(10)$

$V = -58.05 m/s$

This is \emph{downward speed}

\newpage

## Vectors

### Addition and Subtraction

\hl{It is commutative and associative.}

$\vec{S} = \vec{A} + \vec{B} = \vec{B} + \vec{A}$

$(\vec{A} + \vec{B})+\vec{C} = \vec{A} + (\vec{B} + \vec{C})$

Example: 

$\vec{A} = <1,2,3>$

$\vec{B} = <4,5,6>$

$\vec{C} = \vec{A} + \vec{B} = <(1+4), (2+5), (3+6)>$

$\vec{C} = <5,7,9>$

### Multiplication

#### Dot/Scalar Product

$\vec{A} \bullet \vec{B} = \cos\phi$

\hl{Result is a scalar and is commutative.}

Example:

$\vec{A} = <1,2,3>$

$\vec{B} = <4,5,6>$

$\phi = 45$

$|\vec{A}| = \sqrt{13}$

$|\vec{B}| = \sqrt{77}$

$\vec{A} \bullet \vec{B} = \sqrt{13} * \sqrt{77} * \cos(45)$

#### Cross/Vector Product


$\vec{A} = <1,2,3>$

$\vec{B} = <4,5,6>$

$\vec{A} \times \vec{B}$

\hl{Produces an orthogonal (perpendicular) vector to both $\vec{A}$ and $\vec{B}$}

#### Misc

$a\textsubscript{x} = a\cos\theta$

$a\textsubscript{y} = a\sin\theta$

$|a| = \sqrt{a((\cos\theta)\textsuperscript{2} + (\sin\theta)\textsuperscript{2})}$

$arctan(\frac{a\textsubscript{x}}{a\textsubscript{y}}) = \theta$

$\cos\phi = \frac{\vec{A} \bullet \vec{B}}{|\vec{A}| * |\vec{B}|}$

Magnitude of $\vec{A} \times \vec{B} = |\vec{A}| * |\vec{B}| * \sin\phi$

\newpage

## Projectile Motion (Two Dimensions)

Tracking a particle that has parabolic motion. This is the positive half of angular motion.

### Velocity


#### Components

- $V\textsubscript{ox} = V\textsubscript{o}\cos(\theta\textsubscript{o})$
- $V\textsubscript{oy} = V\textsubscript{o}\sin(\theta\textsubscript{o})$

#### Instantaneous

- $V\textsubscript{x} = x\textsubscript{o} + V\textsubscript{ox} t$
- $V\textsubscript{y} = V\textsubscript{o} y - gt$

### Range

#### Horizontal

Description: track how far a particle will land when used as a projectile

Formula: \hl{$R = \frac{V\textsubscript{o}^2 \sin(2\theta\textsubscript{o})}{g}$}

#### Vertical

Description: track how high a particle will achieve when used as a projectile

Formula: \hl{$VR = \frac{V\textsubscript{o}^2\sin^2\theta}{2g}$}

### Position in space

#### X Coordinate

Formula: \hl{$x = x\textsubscript{o} + V\textsubscript{ox} t$}

#### Y Coordinate

Formula: \hl{$y = y\textsubscript{o} + V\textsubscript{oy} t - \frac{1}{2}gt^2$}

### Equation of the path of motion

Description: use this when the component of time is unknown

Formula: \hl{$\Delta y = \tan\theta\textsubscript{o} \Delta x - \frac{g \Delta x^2}{2V\textsubscript{o}^2 \cos^2\theta}$}

\newpage
## Angular Motion

### Polar Coordinates

Positions along the circle given a radius $|\vec{r}|$ and an angle denoted as $\theta$

Formula(s):

- $x = r\cos\theta$
- $y = r\sin\theta$

The above assumes that $|\vec{r}|$ does **not** change

### Uniform Circular Motion

Description: constant angular velocity ($\omega$)

Formula: \hl{$\theta = \theta\textsubscript{o} + \omega t$}

Vector representing uniform circular motion: $\vec{r}(t) = <x(t), y(t)>$

Where the components are:

- $x(t) = r\cos(\theta\textsubscript{o} + \omega t)$
- $y(t) = r\sin(\theta\textsubscript{o} + \omega t)$

Misc information

- $\omega = 2\pi f$ ($f$ being the cycles per second = Hertz)
- $f = \frac{1}{T}$ (rotation period)


#### Velocity for Uniform Circular Motion

Description: velocity in polar coordinates

Formula: \hl{$\frac{d\vec{r}}{dt}(\vec{r}) = <-\omega r\sin(\theta\textsubscript{o} + \omega t), \omega r\cos(\theta\textsubscript{o} + \omega t)>$}

Magnitude of velocity: \hl{$|\vec{v}(t)| = \sqrt{v\textsubscript{x}^2 + v\textsubscript{y}^2} = \omega r$}

#### Acceleration for Uniform Circular Motion

Description: acceleration in polar coordinates

Formula: \hl{$\frac{d^2\vec{r}(t)}{dt} = <- \omega^2 r \cos(\theta\textsubscript{o}+\omega t), - \omega^2 r \sin(\theta\textsubscript{o}+\omega t)>$}

The above formula will decay to:

\hl{$\vec{a} = - \omega^2 \vec{r}(t)$}

Pull out the negative and the components of the vector are $\vec{r}(t)$

Magnitude of acceleration is: \hl{$|\vec{a}(t)| = \omega^2 r = \frac{V^2}{r}$}
