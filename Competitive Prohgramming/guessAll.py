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
       

# in a game, you can score 3,5 aor 10 at each step. find the number of ways to score N points.

# input: 20
# output: 4

# input: 13
# output: 2

# input: 8
# output: 1

def guessAll(n):
    ans = 0
    g10 = 0 # will count the number of time when if its possible by 5, then will it be possible by 10
    for i in range(n//3+1):
        for j in range(n//5+1):
            if 3*i+5*j==n:
                ans+=1
                if n - 3*i >= 10:
                    ans *= 2               
    return ans 

def count(n):
    #your code here
    dp = [0]*(n+1)
    dp[0]=1
    
    for i in range(3,n+1): 
        dp[i]+=dp[i-3] # if we can score 3 points at each step, then we can score i points in dp[i] ways.
        
    for i in range(5,n+1):
        dp[i]+=dp[i-5]
    
    for i in range(10,n+1):
        dp[i]+=dp[i-10]
        
    return dp[-1] 
    # This approach is correct because we are counting the number of ways to score n points.
    # So, we can score 3,5 or 10 points at each step.
    # So, we can either score 3 points or 5 points or 10 points at each step.


print(guessAll(20))
print(guessAll(13))
