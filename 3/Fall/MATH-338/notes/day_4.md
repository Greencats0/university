---
headers-include: |
	\usepackage{textgreek}
---
# Day Four Notes


## Outline

1. Statistical Terminology
2. Sampling Distributions

## Statistical Terminology

### Tidy Data

Each column represents a variable

Header row will contain the name of the \underline{variable}

Each row represents a \underline{case}

Each value goes in its own cell.

**Good form:** left most column contains \underline{label} variable whose values are unique IDs for the cases

One row could represent:

- a patient
- a particular test for that patient
- all patients seen by a doctor

\underline{Merging datasets}: you need to pair like data

### Data Dictionary

For each variable:

- name of the variable
- type of the variable
- units of measurement
- description

#### Type of Variable

Numerical (Quantitative): int, float, double

Categorical (Qualitative): string, classes, char, software-specific variable type


Typically, we \underline{do not} select only one case from the population. We instead select a \underline{subset} of the population: \underline{sample}. A sample will always exist in the real world.

\newpage

## Statistical Terminology (Continued)
Variables vary between \underline{cases}.

Statistics vary between \underline{samples}

Parameters vary between \underline{populations}. 

## Frequentist Statistics

\underline{Parameters} are constants, but we don't know their value.

Statistics are \underline{random variables} that describe "randomly select a sample of some fixed size, record values of a variable for each case in the sample, and \underline{summarize} the value".

## In this class

\underline{Numerical variables:} we use $\mu$ to represent \underline{population mean} and $\bar{X}$ to represent \underline{sample mean}

\underline{Categorical variables:} we use "p" to represent \underline{population proportion} of outcome in a particular category.

We use $\hat{p}$ to represent \underline{sample proportion} of outcomes in a particular category.

\newpage

## Example

A clinical trial compares two bladder cancer drugs:

- Drug A (Company's "new" drug)
- Drug B (Current best drug)

They recruit 200 subjects with bladder cancer and assign 100 to take Drug A and 100 to take Drug B

### Questions

- What is the case
- We can consider this study to have 2 "hypothetical" populations. What are they?
- What are the two samples from those hypothetical populations? (subset of a larger group/population)
- Name an outcome the drug company might be interested in. Is that outcome a numerical or categorical variable?
- What statistic might we use to summarize that outcome in a sample
- What is the corresponding parameter in the hypothetical population.

### Answers

- A case is one patient with bladder cancer
- Everyone on Drug A (all bladder cancer patients, if they took Drug A) and everyone on Drug B 
- 100 people who took Drug A and 100 people who took Drug B
- How much more effective is Drug A compared to Drug B. This would yield a numerical value. (Reduction in tumor size, cancer remission/not in remission)
- \underline{Sample mean ($\bar{X}$)} tumor reduction. \underline{Sample proportion/sample percent} of patients who are in remission.
- \underline{Population} mean tumor reduction and \underline{population} proportion in remission

\newpage

## Sampling Distribution

These are things that do not have real world equivalences.

The probability distribution of a statistic is its \underline{sampling distribution}

Distribution of a statistic over \underline{all possible samples} of a given size from the \underline{sample population}. **Must** specify size of sample.

To find a sampling distribution:

1. \underline{Simulation:} approximate the sampling distribution by simulating samples.
2. \underline{Asymptotic behavior:} as the number of samples $\rightarrow \infty$, what does the distribution look like?

## Properties of Sampling Distributions

Let X be the statistic we use to estimate a parameter $\theta$ for a population. X is an \underline{unbiased} estimator of $\theta$ if $\mu\textsubscript{x} = \theta$. Otherwise X is \underline{biased} and the amount of **bias** is $\mu\textsubscript{x} - \theta$.

The variability of X describes the amount by which individual realizations of X are "spread" about $\mu\textsubscript{x}$.

We can summarize variability by variance, standard deviation, \underline{standard error}, \underline{margin of error}
