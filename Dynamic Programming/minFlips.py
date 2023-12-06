n,m = [int(x) for x in input().split()]
'''
# memoization
mem = [[-1 for _ in range(n+1)] for __ in range(m+1)]
def count(A,B,k,n):
    # global mem
    if n == 0:
        if k == 0:
            mem[k][n] = 0
            # print("mem[{}][{}] = {}".format(k,n,mem[k][n]))
            return 0
        mem[k][n] = 10**12
        # print("mem[{}][{}] = {}".format(k,n,mem[k][n]))
        return 10**12
    # if k < 0:
    #     mem[k][n] = 10**12
    #     return 10**12
    if mem[k][n] != -1:
        return mem[k][n]
    c1 = c2 = 10**12
    if k>=A[n-1]:
        c1 = count(A,B,k-A[n-1],n-1)
    if k>=B[n-1]:
        c2 = count(A,B,k-B[n-1],n-1)
    if c1 == 10**12 and c2 == 10**12:
        mem[k][n] = 10**12
        # print("mem[{}][{}] = {}".format(k,n,mem[k][n]))
        return 10**12
    if c1 < c2:
        mem[k][n] = c1+1
        # print("mem[{}][{}] = {}".format(k,n,mem[k][n]))
        return c1+1
    mem[k][n] = c2
    # print("mem[{}][{}] = {}".format(k,n,mem[k][n]))
    return c2
'''
# Bottom up ==> For solving whole problem in O(nm) time
def MinFlips(A,B,k,n):
    p = [[10**12 for _ in range(k+1)] for __ in range(n+1)]
    for i in range(n+1): # i is the number of cards => n
        for j in range(k+1): # j is the sum => k
            # Base Cases
            if i == 0:
                if j == 0:
                    p[i][j] = 0
            else:
                c1 = 10**12; c2 = 10**12
                if j>=A[i-1]:                    
                    c1 = p[i-1][j-A[i-1]]
                if j>=B[i-1]:
                    c2 = p[i-1][j-B[i-1]]
                if (c1 == 10**12) and (c2 == 10**12):
                    p[i][j] = 10**12
                elif c1 < c2:
                    p[i][j] = c1+1
                else:
                    p[i][j] = c2
    for i in range(k,-1,-1):
        if p[n][i] == 10**12:
            print(-1)
        else:
            print(p[n][i])

 
A = []
B = []
for _ in range(n):
    a,b = [int(x) for x in input().split()]
    A.append(a); B.append(b)

MinFlips(A,B,m,n)
# Time Complexity: O(nm)
