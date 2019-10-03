---
headers-include: |
	\usepackage{soul}
	\usepackage{color}
	\usepackage{amsmath}
fontfamily: lmodern,color,soul
geometry: "left=3cm,right=3cm,top=2cm,bottom=2cm"
---

Jared Dyreson

CPSC-223J TR @ 08:00 - 09:50

# Homework 2

## Chapter 3 (1-10, 16, 17, 19, 20) PG. 171

1. b
2. d
3. c
4. c
5. b
6. d
7. d
8. c
9. a
10. b (technically "a" as well if the function contains a recursive statement and a blank return statement is needed to break out of the initial condition)

\par\noindent\rule{\textwidth}{0.4pt}

16. a
17. d (more or less controlling who has the correct privileges to modify certain class data members. The complete opposite of a struct)
19. d
20. d (if you are using the predefined constructors, then each object instantiation will have the value of the initialized data member. Java will complain if the members are set but not initialised and will fall back to the default constructors of each data type you have set for data members.)

\newpage

## Chapter 4 (2-10, 12, 14, 16, 17) PG. 236

2. b
3. d
4. d (you can have variables with the same name scattered through out the same program but that can get confusing. Redeclaration within the \underline{same} scope is illegal because you have already instantiated it inside that scope. Oddly worded.)
5. a (you need to use the "this" keyword to signify you wanting to use the class' version of the variable)
6. c (unless using the "this" keyword to directly alter the variable of same name)
7. a
8. d
9. a
10. a

\par\noindent\rule{\textwidth}{0.4pt}

12. b (one for each object instantiated)

\par\noindent\rule{\textwidth}{0.4pt}

14. d

\par\noindent\rule{\textwidth}{0.4pt}

16. c
17. b
