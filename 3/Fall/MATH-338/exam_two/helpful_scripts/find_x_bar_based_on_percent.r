#!/usr/bin/env RScript

## EXAMPLE PROBLEM CONTEXT

#In a population of Siberian flying squirrels in western Finland, assume that the the number of pups born to each female over her lifetime has mean 𝜇=3.66 and standard deviation 𝜎=2.9598.

#The distribution of squirrel pups born is non‑normal because it takes only whole, non‑negative values.

#Determine the mean number of pups, x bar,
#such that in 70% of all random samples of such squirrels of size 𝑛=40, the mean number of pups born to females in the sample is less than 𝑥⎯⎯⎯.

#Give your answer to at least two decimal places.

percent <- 0.7
standard_deviation <- 2.9598
n <- 40
mu <- 3.66

(qnorm(percent)*(standard_deviation/sqrt(n)))+mu
