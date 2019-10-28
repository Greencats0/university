
#!/usr/bin/env RScript

# import libraries, will complain about namespace

library(ggplot2)
library(dplyr)

# make the flower plot

petal_length <- iris %>% filter(Species == "setosa") %>% select(Petal.Length)
petal_plot <- ggplot(data = petal_length, mapping = aes(x = Petal.Length))
petal_plot_histogram <- petal_plot + geom_histogram(binwidth = 0.175, center = 1.5) + labs(title = "Length of 50 Setosa Petals", x = "Length (centimeters)", y = "Number of Flowers")

#print(petal_plot_histogram)

n <- 50
mu_naught <- 1.3
mu_alternate <- 1.5
sigma <- 0.5
alpha <- 0.05
critical_value <- qnorm(alpha, mean = mu_naught, sd = sigma/sqrt(n), lower.tail = FALSE)

print(critical_value)

power <- pnorm(critical_value, mean = mu_alternate, sd = sigma/sqrt(n), lower.tail = FALSE)

print(power)

pnorm(1.462, mu_naught, sigma/sqrt(n), lower.tail = FALSE)
