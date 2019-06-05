#!/usr/bin/env python3.5

def weight(bin):
    count = 0
    for i in str(bin):
        if i == "1":
            count+=1
    return count

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

def isSigned(bin):
    return str(bin).startswith("1")
def isUnsigned(bin):
    return str(bin).startswith("0")
def formtwoscomp(bin):
    bin = [ bool(i) for i in str(bin) ]
    # for i, j in bin and range(len(bin)):
    #     print(i, j)
    print(bin)
    #     if int(i) == 0:
    #         bin[i] = "1"
    #     else:
    #         bin[i] = "0"
    # return bin
