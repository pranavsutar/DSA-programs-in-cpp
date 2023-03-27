def dev(s):  
    n = len(s)
    dp = [[0 for _ in range(n+1)] for __ in range(n+1)]
    for size in range(1,n+1):
        for start in range(n-size+1):
            end = start + size - 1
            if s[start:end+1] == s[start:end+1][::-1]:
                dp[start][end] = 0
            else:
                dp[start][end] = n-1
                for k in range(start,end):
                    dp[start][end] = min(dp[start][end],dp[start][k] + dp[k+1][end]+1)
    # print(dp)
    return dp[0][n-1]
    
# cook your dish here
for _ in range(int(input())):
    s = input()

    print(dev(s))
