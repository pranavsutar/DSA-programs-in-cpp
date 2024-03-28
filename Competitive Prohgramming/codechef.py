n = 10**5
bn = [int(bin(i)[2:]) for i in range(1,32)]
bn = list(filter(lambda x: x<=n ,bn))[::-1]
dp = [None for i in range(n+1)]
dp[1] = True
for i in range(2,n+1):
    if i%10 >1:
        dp[i] = False
        continue
    poss = False
    bnn = list(filter(lambda x: x<=i and i%x == 0,bn))
    for j in bnn:
        if dp[i//j]:
            poss = True
            # if i==99: print (j)
            break
    dp[i] = poss
        
for _ in range(int(input())):
    n = int(input())

    print("YES" if dp[n] else "NO")



