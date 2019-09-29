#!/usr/bin/env RScript

n <- 53
p <- 0.5

X <- 27

binom.test(x = X, n = n, p = p, alternative = "g")
binom.test(x = X, n = n, p = p, alternative = "l")
