#!/usr/bin/env RScript

library(dplyr)

C <- 0.95
alpha <- 1 - C
n <- 4
t_star <- qt(alpha/2, df = n-1, lower.tail = F)

mu <- 1.7
sigma <- 0.5

n_samples <- 1000

normal_matrix <- matrix(0, nrow = n_samples, ncol = n)
set.seed(338)
for(i in 1:n_samples){
        normal_matrix[i,] <- rnorm(n = n, mean = 1.7, sd = 0.5)
}
mean_vector <- apply(normal_matrix, 1, mean)
sd_vector <- apply(normal_matrix, 1, sd)
squirrel_df <- data.frame(mean = mean_vector, sd = sd_vector)

squirrel_CI <- squirrel_df %>% mutate(se = sd/sqrt(n), CI.low = mean - t_star*se, CI.high = mean + t_star*se)

squirrel_CI <- squirrel_CI %>% mutate(hit = CI.low <= 1.7 & CI.high >= 1.7)

prop.hit <- sum(squirrel_CI$hit)/n_samples

original_bottom_weight <- 1.106229899
original_top_weight <- 3.042801
#1 - pnorm(original_bottom_weight, mean = mu, sd = sigma)
setosa.petal.length <- iris %>% filter(Species == "setosa") %>% select(Petal.Length)
t.test(setosa.petal.length$Petal.Length, conf.level = 0.95)
