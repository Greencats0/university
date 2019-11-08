#!/usr/bin/env RScript

# we need the initial and alternate mean values
# also the difference of them but only as a positive integer

mu0 <- 53.75
mu1 <- 56.75
delta <- abs(mu0 - mu1)

# one standard deviation value
sigma <- 10.34

# population size
n <- 75
# sig.level
alpha <- 0.05

power.t.test(n = n, delta = delta, sd = sigma, sig.level = alpha, type = "one.sample", alternative = "one.sided")

# gives the power or how accurate the reading is
