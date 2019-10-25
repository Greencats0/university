#!/usr/bin/env RScript
alpha <- 0.05
old_mu <- 8.9
mu <- 10.9
sigma_from_sample <- 2.5/sqrt(6)

critical_value <- qnorm(alpha, old_mu, sigma_from_sample, lower.tail = FALSE)

pnorm(critical_value, mu, sigma_from_sample, lower.tail = FALSE)
