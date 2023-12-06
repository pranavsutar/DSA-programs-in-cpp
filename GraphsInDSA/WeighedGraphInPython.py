import graphlib
from math import dist
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
    if not col[s]: # if not visited i.e. grey
        col[s] = 1
    for nei,wei in adjl[s]:
        if not col[nei]: # if not visited i.e. grey
            col[nei] = 3-col[s] # 1->2, 2->1 , i.e. black->white, white->black
            checkBipartiteSource(adjl,nei,s) # recursively check for neighbours
        elif col[nei] == col[s]: # if neighbour is visited and is same colour as the present node
            bipartite = False # then it is not bipartite
            return
        elif col[nei] == 3-col[s]: # if neighbour is visited and is different colour as the present node
            continue # then check for next neighbours
def checkBipartite(adjl):
    global col,bipartite
    col = [0]*(n+1)
    bipartite = True
    for i in range(1,n+1): # for each node
        if not col[i]: # if not visited i.e. grey
            checkBipartiteSource(adjl,i,0) # check for bipartiteness
    return bipartite
        
# Dijkstra's algorithm
def dijkstra(adjl,s):
    global dist
    dist = [float('inf')]*(n+1)
    dist[s] = 0
    q = [s]
    while q:
        node = q.pop(0)
        for nei,wei in adjl[node]:
            if dist[nei] > dist[node]+wei:
                dist[nei] = dist[node]+wei
                q.append(nei)
    # q = graphlib.PriorityQueue()
    # q.put((0,s))
    # while not q.empty():
    #     wei,node = q.get()
    #     for nei,wei in adjl[node]:
    #         if dist[nei] > dist[node]+wei:
    #             dist[nei] = dist[node] + wei
    #             q.put(tuple([dist[nei],nei]))
    for i in range(1,n+1):
        print(i,'->',dist[i])

# Bellman-Ford algorithm
def bellmanFord(adjl,s):
    global dist # dist is a global variable
    dist = [float('inf')]*(n+1)
    dist[s] = 0
    for _ in range(n-1):
        for j in range(1,n+1):
            for nei,wei in adjl[j]:
                if dist[nei] > dist[j]+wei:
                    dist[nei] = dist[j]+wei
    for j in range(1,n+1):
        for nei,wei in adjl[j]:
            if dist[nei] > dist[j]+wei:
                print('Negative cycle') 
                return
    for i in range(1,n+1):
        print(i,'->',dist[i])

# Floyd-Warshall algorithm
def floyd(adjl):
    global dist
    dist = [[float('inf')]*(n+1) for _ in range(n+1)]
    for i in range(1,n+1):
        dist[i][i] = 0
    for i in range(1,n+1):
        for nei,wei in adjl[i]:
            dist[i][nei] = wei
    for k in range(1,n+1):
        for i in range(1,n+1):
            for j in range(1,n+1):
                if dist[i][j] > dist[i][k]+dist[k][j]:
                    dist[i][j] = dist[i][k]+dist[k][j]
    # to check for negative cycle
    for i in range(1,n+1):
        if dist[i][i] < 0:
            print('Negative cycle')
            return
    for i in range(1,n+1):
        print(i,'->',dist[i][1:])

def Floyd(adjm):
    global dist
    dist = [[float('inf')]*(n+1) for _ in range(n+1)]
    for i in range(1,n+1):
        dist[i][i] = 0
    for i in range(1,n+1):
        for j in range(1,n+1):
            if adjm[i][j]:
                dist[i][j] = adjm[i][j]
    for k in range(1,n+1):
        for i in range(1,n+1):
            for j in range(1,n+1):
                if dist[i][j] > dist[i][k]+dist[k][j]:
                    dist[i][j] = dist[i][k]+dist[k][j]
    # to check for negative cycle
    for i in range(1,n+1):
        if dist[i][i] < 0:
            print('Negative cycle')
            return
    for i in range(1,n+1):
        print(i,'->',dist[i][1:])

    
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
    u,v,w = [int(x) for x in input().split()]
    adjm[u][v] = w
    adjm[v][u] = w
    adjl[u].append([v,w])
    adjl[v].append([u,w])
    edges.append([u,v,w])
    edges.append([v,u,w])
src = int(input())
# print()
# printList()
# printMat()
# print(col)
if (checkBipartite(adjl)):
    print('Bipartite')
else:
    print('Not Bipartite')
# dijkstra(adjl,src)
bellmanFord(adjl,src)
# Floyd(adjm)
# floyd(adjl)

'''
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
    