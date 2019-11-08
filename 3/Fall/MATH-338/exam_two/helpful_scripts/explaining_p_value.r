#!/usr/bin/env RScript

# pt() is used to calculate a p-value
# pt(t-statistic, degrees of freedom)
# example (two tailed)

t_stat <- -2.249
# total sample size of 36 because df = n - 1
degrees <- 35
alpha <- 0.05

# notice how we run the command twice, one with a + t_stat and - t_stat (lower.tail flag)
# we could have simply doubled the first component, as shown below
p_value <- pt(t_stat, df = degrees) + pt(-t_stat, df = degrees, lower.tail = F)
simple_p_value <- 2 * pt(t_stat, df = degrees)

# if you're evaluated p-value is less than your sig level
# we REJECT THE NULL
# else 
# WE FAIL TO REJECT THE NULL
# HERE CODE

if(p_value < alpha){
        # the minimum 5% threshold has not been met
        message("reject the null")
}else{
        message("fail to reject the null")
}

# this is an example of computing the p-value for one-tailed

t <- 3.069
n <- 30
df <- n-1

# notice how we didn't add the other component with the negative t-stat?
p_value <- pt(t, df = df, lower.tail = FALSE)

if(p_value < alpha){
        # the minimum 5% threshold has not been met
        message("reject the null")
}else{
        message("fail to reject the null")
}
