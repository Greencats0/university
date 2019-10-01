#!/usr/bin/env Rscript


# sample size

n <- 100

# event probability

p <- 0.17

# probability of getting EXACTLY 15 right

exactly_fifteen <- dbinom(15, size = n, p = p)
print(exactly_fifteen)

pbinom(10, size = n, p = p)
pbinom(18, size = n, p = p, lower.tail = FALSE)

pbinom(18, size = n, p = p) - pbinom(10, size = n, p = p, lower.tail = FALSE)

pbinom(5, n, p) - dbinom(5, n, p)

dbinom(18, size = n, p = p)

pbinom(17, n, p) 

pbinom(15, n, p) - dbinom(15, n, p)
