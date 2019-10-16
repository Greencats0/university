---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
---
# Lab 13


Jared Dyreson

1. Using the 68-95-99.7 rule, the middle 68% of squirrels should fall within what values? What range corresponds to the lowest 16% of squirrel weights? What range corresponds to the highest 16% of squirrel weights?

    \textbf{The values shoud be from 1.2 to 2.2 pounds for 68 percent. For the lowest range would be  < 1.2 (but not zero) and < 2.2 for the upper range of 16 percent}

2. Using the 68-95-99.7 rule, the middle 95% of squirrels should fall within what values? What range corresponds to the lowest 2.5% of squirrel weights? What range corresponds to the highest 2.5% of squirrel weights?

    \textbf{The value should be from 0.7 to 2.7 for the 95 percent. For the lowest range it would be < 0.7 (but not zero) and the upper range would be < 2.7}

3. Suppose we want to find the proportion of squirrels that weigh between 0.8 and 1.2 lbs. Standardize the weights of 0.8 lbs and 1.2 lbs. Write the z-scores corresponding to the two weights below.

    \textbf{$\frac{0.8 - 1.7}{0.5}$ $\rightarrow$ -1.8 for a weight of 0.8. $\frac{1.2 - 1.7}{0.5}$ $\rightarrow$ -1 for weight of 1.2. The formula is $\rightarrow$ (weight - median)/(sd). }

4. What are the cumulative proportions that correspond to your z-scores? Below, include your code and the answers as given by R.
    ```r
    z_score_one <- -1.8
    z_score_two <- -1

    pnorm(z_score_one)
    pnorm(z_score_two)
    ```
    - Cumulative proportion for 0.8 $\rightarrow$ 0.03593032
    - Cumulative proportion for 1.2 $\rightarrow$ 0.1586553 

5. By subtracting the two cumulative proportions, find the proportion of squirrels that weigh between 0.8 and 1.2 lbs.
    - Proportion would be $0.1586553 - 0.03593032 = 0.12272498$

\newpage

6. What are the cumulative proportions corresponding to 0.8 and 1.2 lbs, given the distribution of squirrel weights? Include your code and the cumulative proportions as given by R. Subtract the two values you get and verify your answer to Question #5.
    ```r
    original_bottom_weight <- 0.8
    original_top_weight <- 1.2

    mu <- 1.7
    sigma <- 0.5

    z_score_one <- -1.8
    z_score_two <- -1

    value_one <- pnorm(z_score_one)
    value_two <- pnorm(z_score_two)

    pnorm(original_bottom_weight, mean = mu, sd = sigma)
    pnorm(original_top_weight, mean = mu, sd = sigma)
    ```

    - Cumulative proportion for 0.8 $\rightarrow$ 0.03593032
    - Cumulative proportion for 1.2 $\rightarrow$ 0.1586553 

    The values are going to be the same because this is showing us we can switch between the standardize version and the original distribution. 

7. What is the cumulative proportion corresponding to the 8% heaviest squirrels?
    - 92% because of the compliment rule

8. What is the z-score that corresponds to this cumulative proportion? Below, include your code and the answer as given by R
    ```r
    cumulative_proportion <- 0.92
    qnorm(cumulative_proportion)
    ```
    \textbf{STDOUT: 1.405072}
9. Convert this z-score back to the original scale. What range of weights corresponds to the 8% heaviest squirrels?
    - $Z = \frac{x - \mu}{\sigma}$
    - $x = Z \times \sigma + \mu$
    - $x = 1.405072 \times 0.5 + 1.7 = 2.402536$

10. By substituting the appropriate numbers into one of the commands above, verify your answer to Question #9. Below, include your code and the answer as given by R.
    ```r

    cumulative_proportion <- 0.92
    upper_tail_prop <- 0.08
    qnorm(cumulative_proportion)

    qnorm(upper_tail_prop, lower.tail = FALSE)

    qnorm(cumulative_proportion, mean = mu, sd = sigma)

    qnorm(upper_tail_prop, mean = mu, sd = sigma, lower.tail = FALSE)
    ```
