#!/usr/bin/env Rscript

# imported libraries

library(ggplot2)
library(dplyr)

data <- read.csv("HairEyeColor.csv")

summary(apply(data, 2, as.factor))
nrow(data)
dim(data)[1]

## Plot bar graph no color with only eye color and occurences

eye_plot <- qplot(data$Eye, geom= "bar")
eye_plot_labeled <- eye_plot + labs(title= "", x = "Eye Color", y = "Occurences")
print(eye_plot_labeled) ## 

eye_counts <- count(data, Eye)
eye_pcts <- round((eye_counts$n/sum(eye_counts$n)*100), 1)
eye_plot_pcts <- eye_plot_labeled + annotate("text", x = seq(1,4), y = eye_counts$n+10, label = paste(eye_pcts, "%", sep = ""))
eye_gender_plot <- ggplot(data = data, mapping = aes(x = Eye))
eye_gender_barplot <- eye_gender_plot + geom_bar(aes(fill = Sex), position = "dodge") + labs(title = "Relation of Eye Color to Gender", x = "Eye Color", y = "Occurrences")

# this prints to a file called RPlot.pdf
#print(eye_gender_barplot)
