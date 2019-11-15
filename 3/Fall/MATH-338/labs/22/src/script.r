#!/usr/bin/env RScript

library(dplyr)

straight_jeans2 <- read.csv("../../19/src/straight_jeans2.csv")

setosa.petal.length <- iris %>% filter(Species == "setosa") %>% select(Petal.Length)

#t.test(setosa.petal.length$Petal.Length, conf.level = 0.95)
iris_sv <- iris %>% filter(Species %in% c("setosa","versicolor"))
#t.test(Sepal.Length ~ Species, data = iris_sv, conf.level = 0.95)
t.test(x = straight_jeans2$maxWidthBackMens, y = straight_jeans2$maxWidthBackWomens, paired = TRUE, conf.level = 0.99)
