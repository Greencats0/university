#!/usr/bin/env python3.5

def bin2decFunc(bin):
    count = 0
    total = 0
    for i in reversed(str(bin)):
        count+=1
        if i == "0":
            pass
        else:
            total+=(2**(int(count)))
    return total
def weight(bin):
    count = 0
    for i in str(bin):
        if i == "1":
            count+=1
    return count
# print("Decimal:", bin2decFunc(10101))
# print("Weight:", weight(10101))
