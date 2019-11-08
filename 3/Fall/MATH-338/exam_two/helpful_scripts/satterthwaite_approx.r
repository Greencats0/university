#!/usr/bin/env RScript

# we calculate a value for degrees of freedom (but this is almost never an integer)

# we need the t-statistic using this formula

x_bar_one <- 23.1
x_bar_two <- 21.4

n_one <- 200
n_two <- 202

s_one <- 8.2
s_two <- 12.5

top <- x_bar_one - x_bar_two
bottom <- sqrt((s_one)**2/n_one + (s_two)**2/n_two)

t_stat <- top/bottom

# we are given the degrees of freedom but it is calculated using the Satterthwaite formula
# the function is broken and it is really not necessary
# the value is going to be most likely given to you, it is a messy formula

satter <- function (s_one, s_two, n_one, n_two){
        top <- (((s_one)**2/n_one)+((s_two)**2)/n_two)**2
        bottom <- (1/(n_one -1))*(((s_one)**2/n_one)**2) + (1/(n_two -1))*(((s_one)**2)/n_two)**2
        print(top/bottom)
}

df <- satter(s_one, s_two, n_one, n_two)

