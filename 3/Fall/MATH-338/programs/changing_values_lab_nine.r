#!/usr/bin/env RScript

# changing the parameters and seeing how it affects power #

## given these parameters ##

n <- 53
probability_null <- 0.5
probability_alternative <- 0.7
alpha <- 0.05

## change the alternative hypothesis probability ##

probability_alternative_one <- 0.6
probability_alternative_two <- 0.8

critical_value_from_alternative_one_probability <- qbinom(alpha, size = n, prob = probability_alternative_one, lower.tail = FALSE)

critical_value_from_alternative_two_probability <- qbinom(alpha, size = n, prob = probability_alternative_two, lower.tail = FALSE)

power_from_alternative_one_probability <- pbinom(critical_value_from_alternative_one_probability, size = n, prob = probability_alternative_one, lower.tail = FALSE) + dbinom(critical_value_from_alternative_one_probability, size = n, prob = probability_alternative_one)

power_from_alternative_two_probability <- pbinom(critical_value_from_alternative_two_probability, size = n, prob = probability_alternative_two, lower.tail = FALSE) + dbinom(critical_value_from_alternative_two_probability, size = n, prob = probability_alternative_two)

# NOTE : changing your probability will increase you chances of failing to reject the null hypothesis #


## change the value of alpha ##

new_alpha <- 0.01

critical_value_from_changed_alpha <- qbinom(new_alpha, size = n, prob = probability_null, lower.tail = FALSE)

# NOTE : This will result in a smaller crititical region #

## change the value of t 
