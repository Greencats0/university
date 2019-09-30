#!/usr/bin/env RScript

# Given the number of successes (x), the number of individuals in a sample (n), and the probability of an event happening (p).

x <- 398
n <- 856
p <- 0.5

binom.test(x = x, n = n, p = p)

# if this value falls below the alpha value, we can successfully reject the null hypothesis and accept the alternative hypothesis

# get the output via bash command here
# echo "binom.test(x = 398, n = 856, p = 0.5)" | R --no-save | grep -o 'p-value = [0-9].*'
