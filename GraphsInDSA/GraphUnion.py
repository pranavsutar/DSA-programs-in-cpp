def printList():
    for i,l in enumerate(adjl[1:]):
        print(i+1,'->',l)
    print()
def printMat():
    for i,l in enumerate(adjm[1:]):
        print(i+1,'->',l[1:])
    print()

def find(v):
    global parent
    if parent[v] == v:
        return v
    parent[v] = find(parent[v])
    return parent[v]
    # return find(parent[v])

def union(a,b):
    global parent,size
    a = find(a)
    b = find(b)
    if a!=b:
        if size[a]<size[b]:
            parent[a] = b
            size[b] += size[a]
        else:
            parent[b] = a
            size[a] += size[b]
    # print(parent)

# Minimum Spanning Tree using Kruskal's Algorithm
# Logic: Sort all the edges in increasing order of their weights.
#        Add the edges one by one to the MST if they don't form a cycle.
#        If they form a cycle, then discard them.
#        Repeat this process until all the vertices are connected.
#        The edges that are added to the MST are the minimum spanning tree.
# Time Complexity: O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time.
#                  After sorting, we iterate through all edges and apply find-union algorithm.
#                  The find and union operations can take atmost O(LogV) time.
#                  So overall complexity is O(ELogE + ELogV) time.
#                  The value of E can be atmost O(V^2), so O(LogV) are O(LogE) same.
#                  Therefore, overall time complexity is O(ElogE) or O(ElogV)
# Space Complexity: O(V+E) for adjacency list and O(V^2) for adjacency matrix
#                   for storing the graph. O(V) extra space for storing parent and size arrays
#                   for union-find algorithm.
#                   So, overall space complexity is O(V+E) or O(V^2)
def kruskal():
    print('Kruskal:')
    global adjl,parent,size
    N = len(adjl) - 1
    for i in range(1,N+1): # for all vertices 
        parent[i] = i  # make a set of each vertex
        size[i] = 1  # size of each set is 1
    edges = []
    for i in range(1,N+1): # for all vertices
        for nei in adjl[i]: # for all neighbours of vertex i
            if nei[0]>i: # if neighbour is greater than vertex i i.e. (i,nei) is not a duplicate edge
                edges.append((nei[1],i,nei[0]))
    edges.sort()

    for w,u,v in edges:
        if find(u)!=find(v):
            union(u,v)
            print(u,v,w)
    print()

# Minimum Spanning Tree using Prim's Algorithm
# Logic: Start with any vertex, add all its edges to the priority queue.
#        Pick the edge with the minimum weight from the priority queue.
#        If the edge connects two vertices that are already in the MST, discard it.
#        Otherwise, add it to the MST.
#        Repeat this process until all the vertices are connected.
#        The edges that are added to the MST are the minimum spanning tree.
# Time Complexity: O(ElogV). The outer loop will run V times and the inner loop will run E times.
#                  The inner loop will run E times because we are adding all the edges to the priority queue.
#                  The priority queue will take O(logV) time to insert an edge.
#                  So, overall time complexity is O(ElogV).
# Space Complexity: O(V+E) for adjacency list and O(V^2) for adjacency matrix
#                   for storing the graph. O(V) extra space for storing parent and size arrays
#                   for union-find algorithm.
#                   So, overall space complexity is O(V+E) or O(V^2).

def prim():
    print('Prim:')
    global adjl,parent,size
    N = len(adjl) - 1
    for i in range(1,N+1): # Initializations
        parent[i] = i
        size[i] = 1
    edges = []
    for i in range(1,N+1): # for all vertices
        for nei in adjl[i]: # for all neighbours of vertex i
            if nei[0]>i: # if neighbour is greater than vertex i i.e. (i,nei) is not a duplicate edge
                edges.append((nei[1],i,nei[0]))
    edges.sort()  
    count = 0 
    for w,u,v in edges:
        if find(u)!=find(v):
            union(u,v)
            print(u,v,w)
            count += 1
        if count == N-1:
            break
    print()

    # N = len(adjl) - 1
    # for i in range(1,N+1):
    #     parent[i] = i
    #     size[i] = 1
    # edges = []
    # for i in range(1,N+1):
    #     for j in range(i+1,N+1):
    #         if adjm[i][j] != 0:
    #             edges.append((adjm[i][j],i,j))
    # edges.sort()
    # # print(edges)
    # for e in edges:
    #     if find(e[1]) != find(e[2]):
    #         union(e[1],e[2])
    #         print(e[1],e[2])
    # print(parent)
    # print(size)
    # print()

# n = int(input('No. of Vertices'))
# m = int(input('No. of Edges'))
n = int(input())
m = int(input())
adjl = [ [] for k in range(n+1)]
adjm = [[0 for _ in range(n+1)] for _ in range(n+1)]
parent = [_ for _ in range(n+1)]
size = [1 for _ in range(n+1)]

bipartite = True
vis = [False]*(n+1)
col = [0]*(n+1)
for _ in range(m):
    u,v,w = [int(x) for x in input().split()]
    adjm[u][v] = w
    adjm[v][u] = w
    adjl[u].append([v,w])
    adjl[v].append([u,w])
prim()
kruskal()
# print()
# printList()
# printMat() 
# print(col)
