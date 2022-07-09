
def ugly(n):
    dp = [0]*(n+1);dp[1] = 1
    c2=c3=c5 = 1
    
    for i in range(2,n+1):
        dp[i] = min(2*dp[c2],3*dp[c3],5*dp[c5])
        if dp[i] == 2*dp[c2]:
            c2 += 1
        if dp[i] == 3*dp[c3]:
            c3 += 1
        if dp[i] == 5*dp[c5]:
            c5 += 1
    # print(dp)
    return dp[n]

print(ugly(15))
print(ugly(150))