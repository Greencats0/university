#!/usr/bin/env RScript

library(ggplot2)
library(dplyr)

iris_boxplot <- ggplot(iris, aes(x = Species, y = Sepal.Length)) + geom_boxplot() + labs(title = "Comparing three Iris species", x = "Species", y = "Length") + coord_flip()
#iris %>% group_by(Species) %>% summarize(mean = mean(Sepal.Length), sd = sd(Sepal.Length))
iris_anova <- aov(Sepal.Length ~ Species, data = iris)
TukeyHSD(iris_anova)
