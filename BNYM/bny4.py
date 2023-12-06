#
# Complete the 'maximumBinary' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. INTEGER numberOfBits
#  2. INTEGER maximumOperationsAllowed
#  3. STRING_ARRAY arr of Binary Strings of length numberOfBits
#
def onesComplement(s):
    # remove leading zeros
    r = ['0']*len(s)
    for i,e in enumerate(s):
        if e == '0':
            r[i] = '1'

    return ''.join(r)
            
def maximumBinary(numberOfBits, maximumOperationsAllowed, arr):
    # Write your code here
    # In an operation, you can find 1's complement of any binary string in the array
    changed = set()
    # arr.sort()

    n = len(arr)
    op = 0; iter = 0
    while op < maximumOperationsAllowed:
        mn = min(arr)
        # check if its onesComement is greater than mn
        if onesComplement(mn) > mn:

            if mn in changed:
                break
            arr.remove(mn)
            arr.append(onesComplement(mn))
            changed.add(mn)
            op += 1
        iter += 1
        if iter == n:
            break

    # Return sum of all binary strings in the array in binary form
    ret =  sum([int(s,2) for s in arr])
    return bin(ret)[2:]

def sol(numberOfBits, maximumOperationsAllowed, arr):

    arr = [e[:numberOfBits] for e in arr]

    arr.sort(key = lambda x: int(onesComplement(x),2) - int(x,2), reverse = True)
    n = len(arr)
    op = 0; 
    for i,e in enumerate(arr):
        if op == maximumOperationsAllowed:
            break
        if onesComplement(e) > e:
            arr[i] = onesComplement(e)
            op += 1
    # Return sum of all binary strings in the array in binary form
    ret =  sum([int(s,2) for s in arr])
    return bin(ret)[2:]

n = input()
print(onesComplement(n))
# import math
# import os
# import random
# import re
# import sys





# if __name__ == '__main__':
#     fptr = open(os.environ['OUTPUT_PATH'], 'w')

#     numberOfBits = int(input().strip())

#     maximumOperationsAllowed = int(input().strip())

#     arr_count = int(input().strip())

#     arr = []

#     for _ in range(arr_count):
#         arr_item = input()
#         arr.append(arr_item)

#     result = maximumBinary(numberOfBits, maximumOperationsAllowed, arr)

#     fptr.write(result + '\n')

#     fptr.close()
