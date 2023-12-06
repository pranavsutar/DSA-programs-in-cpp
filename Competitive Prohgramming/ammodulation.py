'''# Sum of XOR of all subarrays
# https://www.geeksforgeeks.org/sum-of-xor-of-all-subarrays/
def findXorSum(arr, n):
     
    # variable to store the final Sum
    Sum = 0
 
    # multiplier
    mul = 1
 
    for i in range(30):
 
        # variable to store number of sub-arrays
        # with odd number of elements with ith
        # bits starting from the first element
        # to the end of the array
        c_odd = 0
 
        # variable to check the status of the
        # odd-even count while calculating c_odd
        odd = 0
 
        # loop to calculate initial
        # value of c_odd
        for j in range(n):
            if ((arr[j] & (1 << i)) > 0):
                odd = (~odd)
            if (odd):
                c_odd += 1
         
        # loop to iterate through all the
        # elements of the array and update Sum
        for j in range(n):
            Sum += (mul * c_odd)
 
            if ((arr[j] & (1 << i)) > 0):
                c_odd = (n - j - c_odd)
 
        # updating the multiplier
        mul *= 2
     
    # returning the Sum
    return Sum
n = int(input())
arr = list(map(int, input().split()))
print(findXorSum(arr, n))'''


# LRU policy using linked list
# but without pruning

# cook your dish here

'''You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 '''
# cook your dish here
for _ in range(int(input())):
    s = input()
    l = s.count('L')
    r = s.count('R')
    u = s.count('_')
    print(u + max(l,r))