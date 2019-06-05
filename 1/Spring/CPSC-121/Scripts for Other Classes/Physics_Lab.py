#!/usr/bin/env python3.5

listF = [55.65, 54.60, 55.35, 54.7, 53.50, 55.40, 55.40, 55.40, 54.50, 55.9, 53.95]
deviationList = []
squaredDeviationList = []
sumOfList = 0
sumOfDeviation = 0
for number in listF:
    sumOfList+=number
averageOfData = sumOfList / len(listF)
for number in listF:
    deviation = number - averageOfData
    deviation = round(deviation, 2)
    deviationList.append(deviation)
    sumOfDeviation+=deviation
averageOfDeviation = sumOfDeviation / len(listF)
for deviation in deviationList:
    squaredDeviation = deviation**2
    squaredDeviation = round(squaredDeviation, 2)
    squaredDeviationList.append(squaredDeviation)

print("Average:", round(averageOfData, 2))
print("Deviation from list")
for i in deviationList:
    print(i)
print("Squared deviation")
for i in squaredDeviationList:
    print(i)
checkSum = 0
for i in deviationList:
    checkSum+=i
checkSum = round(round(checkSum, 2) / len(deviationList), 2)
if checkSum == 0.0:
    print("Data is valid")
else:
    print("Oops, something went wrong")
