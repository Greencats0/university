#!/usr/bin/env RScript

# P(X=x)
## dbinom (x, n, p)

# P(X <= x)
## pbinom(x, n, p)

# P(X < x)
## pbinom(x, n, p) - dbinom(x, n, p)

# P(X > x)
## pbinom(x, n, p, lower.tail = FALSE)

# P(X >= x)
## pbinom(x, n, p, lower.tail = FALSE) + dbinom(x, n, p)

# GOODNESS OF FIT TESTING
## mytable <- xtabs(frequency_var ~ var_one + var_two, data = data_given)

# TEST OF INDEPENDENCE
## chisq.test(mytable)
print("Helo")
