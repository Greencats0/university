#!/usr/bin/env RScript

star <- c(11, 27, 25, 25)
probs <- c(0.25, 0.25, 0.25, 0.25)

chisq.test(star, p=probs)

chisq.test(star, p=probs, simulate.p.value = TRUE)
