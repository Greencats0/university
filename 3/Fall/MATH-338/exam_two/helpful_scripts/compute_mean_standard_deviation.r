#!/usr/bin/env RScript

# read in the data from an outside source

load(file="data.rda")

# assign the contents of a certain row to hold the vector of elements
data <- `ex04-001c`$EGGCNT

# compute the mean and standard deviation
sample_data_mean <- mean(data)
sample_data_sd <- sd(data)

# profit

print(sample_data_mean)
print(sample_data_sd)

