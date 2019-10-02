#!/usr/bin/env Rscript

n <- 30
p <- 0.35

# getting EXACTLY fifteen questions correct

exactly_fifteen <- dbinom(15, size = n, p = p)
print(exactly_fifteen)

# AT MOST 10 questions correct

at_most_ten <- pbinom(10, size = n, p = p)
print(at_most_ten)
#pbinom(18, size = n, p = p, lower.tail = FALSE)

#pbinom(18, size = n, p = p) - pbinom(10, size = n, p = p, lower.tail = FALSE)

#pbinom(5, n, p) - dbinom(5, n, p)

#dbinom(18, size = n, p = p)

#pbinom(17, n, p) 

#pbinom(15, n, p) - dbinom(15, n, p)
