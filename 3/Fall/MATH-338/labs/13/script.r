#!/usr/bin/env RScript

original_bottom_weight <- 0.8
original_top_weight <- 1.2

mu <- 1.7
sigma <- 0.5

z_score_one <- -1.8
z_score_two <- -1

value_one <- pnorm(z_score_one)
value_two <- pnorm(z_score_two)

pnorm(original_bottom_weight, mean = mu, sd = sigma)
pnorm(original_top_weight, mean = mu, sd = sigma)

cumulative_proportion <- 0.92
upper_tail_prop <- 0.08
qnorm(cumulative_proportion)

qnorm(upper_tail_prop, lower.tail = FALSE)

qnorm(cumulative_proportion, mean = mu, sd = sigma)

qnorm(upper_tail_prop, mean = mu, sd = sigma, lower.tail = FALSE)
