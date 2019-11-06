#!/usr/bin/env RScript

library(ggplot2)
library(dplyr)

data_one <- read.csv("straight_jeans.csv")
data_two <- read.csv("straight_jeans2.csv")

#ggplot(data_one, aes(x = maxWidthBack)) + geom_histogram(binwidth = 0.5, center = 12.25) + facet_grid(menWomen ~ .) + labs(title = "Comparing max width back between men and women")

#ggplot(data_one, aes(x = minWidthBack)) + geom_histogram(binwidth = 0.5, center = 12.25) + facet_grid(menWomen ~ .) + labs(title = "Comparing min width back between men and women")


#t.test(maxWidthBack ~ menWomen, data = data_one)
#t.test(minWidthBack ~ menWomen, data = data_one)

jeans_diff <- data_two %>% mutate(maxWidthBackDiff = maxWidthBackMens - maxWidthBackWomens, minWidthBackDiff = minWidthBackMens - minWidthBackWomens)

ggplot(jeans_diff, aes(x = maxWidthBackDiff)) + geom_histogram(binwidth = 0.5, center = 0.25) + labs(title = "Jeans Difference (Max -> Mens)")
