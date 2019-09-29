---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
---

# Day 10

# Outline

1. "Null Hypothesis Significance Testing"
2. When Null Hypothesis Significance Testing goes horribly wrong

\newpage


## Null Hypothesis Significance Testing

**Recall**

- identifying a parameter is not "too hard"
- identify its value under H\textsubscript{0} is trivial
- However, identifying its value under H\textsubscript{a} is difficult in practice
- Under N-P (Neyman-Pearson): define minimum \underline{effect size}
- But often, we have \underline{no idea}
- This is what we have been doing for the past 70 years and it does not require any subject knowledge. "It just works". Will also allow us to get the `P` value.

**NHST:** just give the inequality in alternative hypothesis H\textsubscript{a}

Suppose H\textsubscript{0}: $\theta = \theta\textsubscript{0}$

- $\theta \rightarrow$ arbitrary parameter
- $\theta\textsubscript{0} \rightarrow$ its value under H\textsubscript{0}

N-P: 

- H\textsubscript{1}: $\theta = \theta\textsubscript{1}$
- $\theta\textsubscript{1} \rightarrow$ its value under H\textsubscript{1}

**NHST:** Choose from

- H\textsubscript{a}: $\theta > \theta\textsubscript{0}$
	- Theory says $\theta$ should be bigger
	- One-tailed, one-sided hypothesis testing
- H\textsubscript{a}: $\theta < \theta\textsubscript{0}$
	- Theory says $\theta$ should be smaller
	- One-tailed, one-sided hypothesis testing
- H\textsubscript{a}: $\theta \ne \theta\textsubscript{0}$
	- No idea what to expect or theory suggests arguments for \underline{both} > **AND** < 
	- Two-tailed, two-sided hypothesis testing

**NOTE:** method of collecting data tells us what $\theta$ is (what $\theta\textsubscript{0}$ is) and may suggest H\textsubscript{a}

\underline{When in doubt:} use the H\textsubscript{a} version with $\ne$

## Next Step

Define a test statistic whose value will be computed from sample data

**N-P:** Find its distribution under \underline{both} H\textsubscript{0} & H\textsubscript{1}

**NHST:** Find its distribution under H\textsubscript{0} \underline{but} we don't know its distribution under H\textsubscript{a}

## Next Step

Define a critical region of the test statistic such that if the observed value is in critical region, accept H\textsubscript{1}

**NHST:** Define a critical region such that if in critical region, \underline{reject H\textsubscript{0}}.

If not in critical region, \underline{fail to reject H\textsubscript{0}}

\newpage

### Example (Theory) : Jury

Start off assuming innocence (H\textsubscript{0}) [Null Hypothesis]

- Prosecution presents evidence (test statistic observed value)
- Jury decides if it enough evidence
	- Enough evidence (in critical region) $\rightarrow$ reject the assumption of innocence and declare guilty (reject H\textsubscript{0} and acccept H\textsubscript{a})
	- Not enough evidence (not in critical region) $\rightarrow$ fail to reject presumptions of innocence. He might still be guilty but the evidence is not damming enough to convince us otherwise. We fail to reject H\textsubscript{0} or the Null Hypothesis

In NHST, define \underline{significance level} (not $\alpha$ but works like $\alpha$)

This can go horribly wrong because power is not taken into account. There is not a big enough sample size.

## P-Value

A measure of the "strength" of the evidence against H\textsubscript{0}

\hl{ALWAYS COMPUTED AFTER OBSERVATION}

Official definition: probability of obtaining our observed value of the test statistic, or a value \underline{as or more favorable to H\textsubscript{a}}, \underline{\underline{if}} H\textsubscript{0} is true.

- P(X $\ge$ x\textsubscript{observed} | H\textsubscript{0} is true) when H\textsubscript{a}: $\theta > \theta\textsubscript{0}$
- P(X $\le$ x\textsubscript{observed} | H\textsubscript{a} : $\theta < \theta\textsubscript{0}$) 

*Things go weird for two-tailed tests*

\hl{Usually}: P(X is equally or less likely than x\textsubscript{observed} | H\textsubscript{0} is true) but sometimes we get one-tailed p-values

### "How likely is it that I got this lucky or luckier?"

When P-Value $\le$ significance level

1. H\textsubscript{0} is true and I got really lucky $\leftarrow$ I \underline{will} make a \hl{Type I Error}
2. H\textsubscript{0} is not true and H\textsubscript{a}

Either way, I reject H\textsubscript{0} and conclude H\textsubscript{a} is true

When P-Value > significance level

1. H\textsubscript{0} is true
2. H\textsubscript{0} is not true, but we don't have "unlikely enough" evidence

Either way, we fail to reject H\textsubscript{0} (make no conclusion so default to assumption H\textsubscript{0} is true)

\newpage

### Example (Book Exercise 8.20)

Study of children, program \underline{intended} to increase consumption of whole grains. At end of program, sample of 86 children got a snack.

- 48 children chose whole grain
- 38 chose regular

Suppose that before program, children were equally likely to pick either snack. Do we have enough evidence to claim the program works as intended?

#### Step 1 (Identify Parameter of Interest)

Use it to write H\textsubscript{0} and H\textsubscript{a}.

- `p` = Proportion of all children who choose whole grain (generalized results)
- H\textsubscript{0} : `p = 0.5`
- H\textsubscript{a} : `p > 0.5`

#### Step 2 (Identify Test Statistic and its sampling distribution under H\textsubscript{0})

Let `X` = number of success (number of children in sample choosing whole grain)

$X \sim B(n=86\, , p=0.5)$

### Step 3 (Observe data and calculate value of test statistic)

X\textsubscript{observed} = 48

#### Step 4 (Calculate \underline{EITHER} the critical region or the P-Value)

\underline{P-Value is way easier to compute when you have software}

```r
binom.test(x = 48, n = 86, p = 0.5, alternative = "g")
```

From software: p-value = 0.166

#### Step 5 (Determine whether or not to reject H\textsubscript{0})


**5% is our cut-off**

Since 0.166 > 0.05, our results are \underline{likely enough} under H\textsubscript{0} therefore, we fail to reject H\textsubscript{0}

#### Step 6 (Write what "reject H\textsubscript{0}" or "fail to reject H\textsubscript{0}" means in context)

We do not have "statistically signifiant" evidence to claim that the program is working. It is reasonable to continue with the assumption that it is not.

\newpage


## When Null Hypothesis Significance Testing goes horribly wrong

1. Very small samples
2. Very large samples
	- Neyman-Pearson: p = 0.5 vs p = 0.50001
	- NHST: p = 0.5 vs p > 0.5
3. Significance level is \underline{not} arbiter of importance (2 and 3 are practically the same)
4. Lots of tests
5. P-hacking

\newpage
