---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
---
# Day 6

## Outline

1. Types of Studies
2. Design Experiments
3. Why studies go wrong

## Types of Studies

### Observational

We simply observe things and do not manipulate them

![observing](assets/observing_clipart){width=25%}

### Experimental

Manipulate one or more explanatory variables and record response variables

Try to prove cause and effect

![experimenting](assets/experimenting_clipart){width=25%}

\newpage

## Design of Experiments: Terminology

Manipulated explanatory variables: \hl{experimental variables, factors}

- Treat as a categorical variables
- Values are called \underline{levels} of the factor

A set of conditions caused by combining levels of different factors: \underline{treatment}

Recorded response variables: \underline{outcomes}

### Example One

Experiment to compare two weight-loss drugs

Two separate factors

- Drug (A & B)
- Diet (Normal & Special)

Full factorial experiment: 4 treatments

- Drug A & normal diet
- Drug B & normal diet
- Drug A & special diet
- Drug B & special diet

### Example Two

Visitors to a website.

Two separate factors

- Placement of an ad (top/bottom)
- Background color (blue/red)

Full factorial experiment: 4 treatments

- Top & Blue
- Bottom & Blue
- Top & Red
- Bottom & Red

\newpage

### Interacting Variables

Factors can be \underline{interacting variables} effect of factor one on response \underline{changes} depending on value on factor two.

![Interaction effect](assets/interaction_effect_graph){width=45%}

![No interaction effect](assets/no_interaction_graph){width=45%}

\newpage

### Confounding Variable

Two variables (factors or not manipulated explanatory variables) are \underline{confounding} variables if their effects on response cannot be disentangled/distinguished.

Often but not always, confounding variables are related to each other.

\underline{Lurking} variables are potential confounding variables that we ignore during study design.

**Formal definition**: \hl{In statistics, a confounder is a variable that influences both the dependent variable and independent variable, causing a spurious association. Confounding is a causal concept, and as such, cannot be described in terms of correlations or associations.}

#### Examples

- Age

### Three Principles of Experimental Design


#### Control

Subjects on each treatment should be as "similar" as possible

"controlling" for effects of other variables than our experimental variable

#### Randomization

Treatments should be \underline{randomly assigned} to subjects

#### Replication/Repetition

Other people can repeat your experiment on similar subjects and get similar results

We have enough subjects to "eliminate" variability issues

\newpage

### Types of Experimental Designs

#### Completely Random Design

Subjects assigned a treatment entirely at random

#### Block Design

Non randomly divide our subjects into groups ("blocks") based on potential confounding variables, then assign treatments \underline{within} each block.

![Block Design](assets/block_design_graph){width=70%}

#### Matched Pairs Design (Paired Design)

Special case of block design with blocks size of two (only looking at one treatment with two levels)

![Matched Pair Design](assets/matched_pair_design){width=50%}

\newpage

#### Repeated measures design 

More than two levels

\underline{Idea:} get you & someone as similar to you as possible.

Randomly assign you to one treatment and assign your "pair" to other treatment

Often, we have same subjects undergo all treatments or record response at multiple times.

These are matched pairs/repeated measures designs in which \underline{order} of treatments is manipulated/randomized.

![Repeated Measure Designs](assets/repeated_measure_desgin){width=50%}

One of the levels of treatment is \underline{control} level

Group whose treatment entirely control levels = \underline{control group}

\hl{In this class: one control group $\geq 1$ "treatment group"}

\newpage

## Why Studies Go Wrong

1. You accidentally introduce a confounding variable 
	- "Placebo effect": Otherwise ineffective treatment "works" because people think it will
	- Effects due to people involved in experiment knowing who is in each group
	- \underline{Blinding/masking}: not letting experimenters or subject know which group anyone is in
	- \underline{Double blind}: neither subject nor experimenter know
2. Equipment failure/mistake in recording data
3. Hawthorne Effect
	- If people know they're in the study they change their behavior
4. Subjects are not representative of the target population
	- Using rats for experiments where rats did not respond the way they needed to
5. Treatments are not representative of real world conditions
