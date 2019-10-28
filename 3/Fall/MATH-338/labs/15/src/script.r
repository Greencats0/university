#!/usr/bin/env RScript

library(ggplot2)

set.seed(338)

# inital information given

n_squirrels <- 4
mu <- 1.7
sigma <- 0.5

# run a mini simulation

normal_draws <- rnorm(n = n_squirrels, mean = mu, sd = sigma)

# compute the mean and standard deviation of the data

m <- mean(normal_draws)
standard <- sd(normal_draws)


# Much larger simulation

n_samples <- 1000

normal_matrix <- matrix(0, nrow = n_samples, ncol = n_squirrels)

# reset the seed

set.seed(338)

for(i in 1:n_samples){
    normal_matrix[i,] <- rnorm(n = n_squirrels, mean = mu, sd = sigma)
}

mean_vec <- apply(normal_matrix, 1, mean)
sd_vec <- apply(normal_matrix, 1, sd)

# find the actual mean and standard deviation of the simulations

actual_mean <- mean(mean_vec)
actual_standard_deviation <- sd(sd_vec)

# find approximate probability of obtaining the a sample weight between 0.8 and 1.2  

original_bottom_weight <- 0.8
original_top_weight <- 1.2

# replace mean_sample_means and sd_sample_means with your answers to question 4 
mean_sample_means = 1.7
sd_sample_means = 0.25

## this actually computes the probability

bottom <- pnorm(original_bottom_weight, mean = mean_sample_means, sd = sd_sample_means)
top <- pnorm(original_top_weight, mean = mean_sample_means, sd = sd_sample_means)
percent_range <- top - bottom

# time to plot the data


squirrel_df <- data.frame(mean = mean_vec, sd = sd_vec)
squirrel_plot <- ggplot(data = squirrel_df, mapping = aes(x = mean))
squirrel_density <- squirrel_plot + geom_histogram(aes(y = ..density..),  binwidth = 0.1, center = 1.7) + stat_function(fun = dnorm, n = 101, args = list(mean = mean_sample_means, sd = sd_sample_means)) + labs(title = "Simulated Sample Means (n = 4) of Squirrel Weights", x = "Sample Mean Weight", y = "Density")  
#print(squirrel_density)

#sum(mean_vec > 0.8 & mean_vec < 1.2)
pnorm(2.074515, mean = mean_sample_means, sd = sd_sample_means, lower.tail = FALSE)
