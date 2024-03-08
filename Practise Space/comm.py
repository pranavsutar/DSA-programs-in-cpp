# Given two strings a and b, return the size of substring matching in both the strings

def substring_match(a,b):
    n = len(a)
    m = len(b)
    dp = [[0 for _ in range(m+1)] for __ in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            if a[i-1] == b[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
    return dp[n][m]

a = 'apple'
b = 'pineapple'

print(substring_match(a,b))
