#!/usr/bin/env Rscript

n <- 30
p <- 0.35
dbinom(15, size = n, p = p)
pbinom(10, size = n, p = p)
pbinom(18, size = n, p = p, lower.tail = FALSE)

pbinom(18, size = n, p = p) - pbinom(10, size = n, p = p, lower.tail = FALSE)

pbinom(5, n, p) - dbinom(5, n, p)

dbinom(18, size = n, p = p)

pbinom(13.5, n, p) 

pbinom(15, n, p) - dbinom(15, n, p)
