#!/usr/bin/env Rscript


# this program can read in a CSV file and print the summary of the file

data <- read.csv("../labs/lab_one_spreadsheet.csv")
summary(data)

# you can also print the contents of the CSV file directly

#print(data)
