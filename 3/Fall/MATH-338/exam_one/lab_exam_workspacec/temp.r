#!/usr/bin/env RScript

library(ggplot2)
library(dplyr)
data <- read.csv("~/Downloads/carrots.csv")
summary(apply(data, 2, as.factor))
nrow(data)
dim(data)[1]

carrot_plot <- qplot(data$Condition, geom= "bar")
carrot_plot_labeled <- carrot_plot + labs(title= "", x = "Condition", y = "Rating")
print(carrot_plot_labeled)

