#!/usr/bin/env Rscript

S <- c(1, 2, 3, 4, 5, 6)
Prob <-c(1/6, 1/6, 1/6, 1/6, 1/6, 1/6)
n_rolls <- 100000000
set.seed(338)
rolls <- sample(x=S, size=n_rolls, prob=Prob, replace=TRUE)
num_sixes <- sum(rolls==6)
print(num_sixes)
mean(rolls)
