import graphlib
def printList():
    for i,l in enumerate(adjl[1:]):
        print(i+1,'->',l)
    print()
def printMat():
    for i,l in enumerate(adjm[1:]):
        print(i+1,'->',l[1:])
    print()

def checkBipartiteSource(adjl,s,p):
    global col,bipartite
    if not col[s]:
        col[s] = 1
    tcol = col[s]
    for v in adjl[s]:
        # if v == p:
        #     continue
        if col[v] == 0:
            col[v] = 3 - tcol
        elif col[v] == tcol:
            # print(col[v],v,tcol,s)
            bipartite = False
            return

    
def checkBipartite(adjl):
    global col
    for ind,l in enumerate(adjl[1:]):
        for i in l:
            if not bipartite:
                return
            if col[i] ==0:
                col[i] = 1
            # print(col)
            checkBipartiteSource(adjl,i,ind+1)

def shortestDistance():
    global adjl,adjm
    N = len(adjl) - 1
    for i in range(1,N+1):
        for j in range(1,N+1):
            if adjm[i][j] == 0:
                adjm[i][j] = 1000000000
    for k in range(1,N+1):
        for i in range(1,N+1):
            for j in range(1,N+1):
                adjm[i][j] = min(adjm[i][j],adjm[i][k]+adjm[k][j])
    for i in range(1,N+1):
        for j in range(1,N+1):
            if adjm[i][j] == 1000000000:
                adjm[i][j] = 0
    printMat()

def dfsSource(adjl,s,p):
    global vis
    vis[s] = True
    for v in adjl[s]:
        if v == p:
            continue
        if not vis[v]:
            dfsSource(adjl,v,s)
def dfs():
    global vis, adjl
    for i in range(1,len(adjl)):
        if not vis[i]:
            dfsSource(i)

 
# n = int(input('No. of Vertices'))
# m = int(input('No. of Edges'))
n = int(input())
m = int(input())
adjl = [ [] for k in range(n+1)]
adjm = [[0 for _ in range(n+1)] for __ in range(n+1)]
edges = []
bipartite = True
vis = [False]*(n+1)
col = [0]*(n+1)
for _ in range(m):
    u,v= [int(x) for x in input().split()]
    adjm[u][v] = 1
    adjm[v][u] = 1
    adjl[u].append(v)
    adjl[v].append(u)
    edges.append([u,v])
    edges.append([v,u])
# print()
# printList()
# printMat()
# print(col)
# checkBipartite(adjl)
# print(bipartite)
dfs(adjl)
# shortestDistance()


'''
7 
7
1 2
1 3
2 4
2 5
2 6
2 7
7 3

7 
7
1 2 1
1 3 1
2 4 1
2 5 1
2 6 1
2 7 1
7 3 1
'''
    