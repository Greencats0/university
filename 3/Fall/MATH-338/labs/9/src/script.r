#!/usr/bin/env RScript

# amount of subjects
n <- 53
# initial probabilty (null hypothesis)
p0 <- 0.5
# changing probability (alternate hypothesis)
p1 <- 0.7
alpha <- 0.05

critical_value <- qbinom(alpha, size = n, prob = p0, lower.tail = FALSE)
print(critical_value)
power <- pbinom(critical_value, size = n, prob = p1, lower.tail = FALSE)
print(power)

p2 <- 0.6
p2_power <- pbinom(critical_value, size = n, prob = p2, lower.tail = FALSE)

p3 <- 0.8
p3_power <- pbinom(critical_value, size = n, prob = p3, lower.tail = FALSE)

new_alpha <- 0.01
new_critical_value <- qbinom(new_alpha, size = n, prob = p0, lower.tail = FALSE) + 1

new_p1_power <- pbinom(new_critical_value, size = n, prob = p1, lower.tail = FALSE)

very_high_alpha <- 0.1
new_critical_based_on_alpha <- qbinom(very_high_alpha, size = n, prob = p1, lower.tail = FALSE)
print(new_critical_based_on_alpha)
very_high_p2_power <- pbinom(new_critical_based_on_alpha, size = n, prob = p1, lower.tail = FALSE)

print(new_p1_power)
print(very_high_p2_power)

alpha <- 0.05
n <- 30
problem_10_critical <- qbinom(alpha, size = n, prob = p1, lower.tail = FALSE) 
n <- 25
problem_10_power <- pbinom(problem_10_critical, size = n, prob = p1, lower.tail = FALSE)
n <- 100
problem_11_power <- pbinom(problem_10_critical, size = n, prob = p1, lower.tail = FALSE) 

print(problem_10_power)
print(problem_11_power)
