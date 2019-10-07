#!/usr/bin/env RScript

# this script is taken directly from lab 8

## number of elements in sample space

n <- 53

## probability of the null hypothesis being correct (there is a 50% chance the dog will pick the bowl with food in it)

p_null <- 0.5

## probability of the alternative hypothesis being correct (there is now a 70% this hypothesis will be correct)

p_alternative <- 0.7

# the conventionalmax value of alpha (the "desired" probability of committing a Type I Error)

alpha <- 0.05

## get the critical region value. This will represent the range of values that corresponds to the rejection of the Null Hypothesis

critical_value <- qbinom(alpha, size = n, prob = p_null, lower.tail = FALSE)

## find the power, which is going to be the threshold for keeping the null hypothesis 

power <- pbinom(critical_value, size = n, prob = p_alternative, lower.tail = FALSE) + dbinom(critical_value, size = n, prob = p_alternative)

## if the power is greater than 80% or 0.80, we fail to reject the null hypothesis

beta_value <- 1 - power


