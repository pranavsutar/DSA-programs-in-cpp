# Kadne

def Kadne(arr, startInd, endInd):
    maxSoFar = 0
    maxEndingHere = 0
    for i in range(startInd, endInd+1):
        maxEndingHere = maxEndingHere + arr[i]
        if maxEndingHere < 0:
            maxEndingHere = 0
        elif (maxSoFar < maxEndingHere):
            maxSoFar = maxEndingHere
    return maxSoFar

a = [1, 2, 3, -6,7,-3 , 2]

def printKadneSubarray(arr, startInd, endInd):
    maxSoFar = 0
    maxEndingHere = 0
    start = 0
    end = 0
    s = 0
    for i in range(startInd, endInd+1):
        maxEndingHere = maxEndingHere + arr[i]
        if maxEndingHere < 0:
            maxEndingHere = 0
            s = i + 1
        elif (maxSoFar < maxEndingHere):
            maxSoFar = maxEndingHere
            start = s
            end = i
    return arr[start:end+1], start, end
# print(Kadne(a, 0,len(a)-1))
# print(printKadneSubarray(a, 0, len(a)-1))

def sol(arr):
    n = len(arr)
    a, start, end = printKadneSubarray(arr, 0, n-1)
    if len(a) >2:
        return sum(a)
    else:
        