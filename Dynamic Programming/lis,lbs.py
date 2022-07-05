def longestIncSubseq(a):
    n = len(a)
    lis=[0]*n
    lis[0] = 1
    for i in range(1,n):
        lis[i] = 1
        for k in range(i):
            if a[k]<a[i]:
                lis[i]= max(lis[i],1 + lis[k] )
    print(lis)
    print('Longest Increasing Subsequence: ',end ="")
    return max(lis)

def longestBotanicalSubseq(a):
    n = len(a)
    lis=[0]*n
    lis[0] = 1
    for i in range(1,n):
        lis[i] = 1
        for k in range(i):
            if a[k]<a[i]:
                lis[i]= max(lis[i],1 + lis[k] )
    lds=[0]*n
    lds[-1] = 1
    for i in range(n-2,-1,-1):
        lds[i] = 1
        for k in range(i+1,n):
            if a[k]<a[i]:
                lds[i]= max(lds[i],1 + lds[k] )
    lbs = [x+y-1 for x,y in zip(lis,lds)]
    print(lis)
    print(lds)
    print(lbs)
    # print()
    return max(lbs)

a = [1,2,3,8,9,4,5,6,7,1]
b = [2,4,6,8,1,3,5,7,9,11]
print(longestIncSubseq(a))
print(longestIncSubseq(b))
print(longestBotanicalSubseq(a))
print(longestBotanicalSubseq(b))