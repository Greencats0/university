#!/usr/bin/env Rscript

# this program will emulate a dice rolling program

# a list of possible values of each side of the dice

S<- c(1, 2, 3, 4, 5, 6)

# the probability for each roll. The len of S and Prob MUST be the same

Prob <-c(1/6, 1/6, 1/6, 1/6, 1/6, 1/6)

# amount of times the program will run
n_rolls <- 10

# random variable

set.seed(338)

# actual rolling mechanic
rolls <- sample(x=S, size=n_rolls, prob=Prob, replace=TRUE)

# the sum of all outcomes
num_sixes <- sum(rolls==6)

print(num_sixes)

# your average

mean(rolls)
