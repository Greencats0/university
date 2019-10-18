#!/usr/bin/env RScript

library(ggplot2)
library(dplyr)

tree_height_plot <- ggplot(data = trees, mapping = aes(x = Height))
tree_height_histogram <- tree_height_plot + geom_histogram(binwidth = 5, center = 67.5) + labs(title = "Height of 31 Black Cherry Trees", x = "Height (feet)", y = "Number of Trees")

#print(tree_height_histogram)

summarize(trees, mean.height = mean(Height), sd = sd(Height))

summary(trees)

# IQR = 80 - 72 = 8
# Lower fence = 72 - (1.5) * 8 = 60
# Upper fence = 80 + (1.5) * 8 = 92

tree_height_boxplot <- tree_height_plot + geom_boxplot(aes(x = "", y = Height, group = NA))+labs(title = "31 Black Cherry Trees", x = "", y = "Height (feet)")
#print(tree_height_boxplot)

trees_transform <- mutate(trees, height_new = 0.3048 * Height - 10)

summarize(trees_transform, mean_height_new = mean(height_new), sd_height_new = sd(height_new))
