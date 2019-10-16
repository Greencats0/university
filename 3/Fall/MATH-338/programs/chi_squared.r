#!/usr/bin/env RScript

# compute p-value from CHI


value <- pchisq(6.9100, df=2, lower.tail=FALSE)
alpha <- 0.05

if(value > alpha){
	print("Fail to reject because p-value is greater than alpha")
}

print(value)

# because value is less than alpha, there is signifigant evidence against their claim, reject the null
