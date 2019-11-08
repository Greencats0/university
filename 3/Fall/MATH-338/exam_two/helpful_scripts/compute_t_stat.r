#!/usr/bin/env RScript

library(dplyr)
# given the sample mean of two populations and the standard error
# we can compute the t-statistic with this simple formula

x_bar <- 0.11791
std_error <- 0.05242
t_stat <- x_bar/std_error

# if we are given a dataset and a mean, we can use the t.test() function call

mu <- 1.3
spl <- iris %>% filter(Species == "setosa") %>% select(Petal.Length)

# array of values
spl_selected <- spl$Petal.Length

t.test(spl_selected, mu = 1.3, alternative = "g")

# the alternative will change based on the ALTERNATIVE hypothesis
# h_a: \mu < 0 
# ^ we use "l"
