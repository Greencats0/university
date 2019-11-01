#!/usr/bin/env RScript

library(dplyr)
library(ggplot2)

n_squirrels <- 100
n_samples <- 1000
normal_matrix <- matrix(0, nrow = n_samples, ncol = n_squirrels) 
set.seed(338)  
for(i in 1:n_samples){  
normal_matrix[i,] <- rnorm(n = n_squirrels, mean = 1.7, sd = 0.5)
}  

mean_vector <- apply(normal_matrix, 1, mean)
sd_vector <- apply(normal_matrix, 1, sd)
squirrel_df <- data.frame(mean = mean_vector, sd = sd_vector)
squirrel_df <- squirrel_df %>% mutate(se = sd/sqrt(n_squirrels), t = (mean - 1.7)/se)
squirrel_plot <- ggplot(data = squirrel_df, mapping = aes(x = t))
squirrel_density <- squirrel_plot + geom_histogram(aes(y = ..density..),  binwidth = 0.1, center = 0) + stat_function(fun = dnorm, n = 101, args = list(mean = 0, sd = 1)) + labs(title = "Simulated t-statistics (n = 100) of Sample Mean Squirrel Weights", x = "T-Statistic", y = "Density")
print(squirrel_density)

a <- pt(2, 3, lower.tail = FALSE)
b <- pt(-2, 3)
print(a + b)
