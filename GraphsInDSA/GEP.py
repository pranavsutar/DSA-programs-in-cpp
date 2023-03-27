adjl = dict()
n = int(input())

p = [ int(i) for i in input().split() ]
q = [ int(i) for i in input().split() ]
vis = [0]*1000
dist = [-1]*1000
def printList():
    for e in sorted(adjl):
        print(e,'->',adjl[e])
    print()

def bfs_s(src):
    q = [src]
    dist[src] = 0
    while q:
        node = q.pop(0)
        for nei in adjl[node]:
            if dist[nei]==-1:
                # print(nei, dist[node]+1)
                dist[nei] = dist[node]+1
                q.append((nei))




def bfs_sp(u,v):
    q = [u]
    dist[u] = 0
    while q:
        node = q.pop(0)
        for nei in adjl[node]:
            if dist[nei]==-1:
                # print(nei, dist[node]+1)
                dist[nei] = dist[node]+1
                if nei == v:
                    return dist[nei]
                q.append((nei))
    return -1

'''# shortest path between nodes n1 and n2 in an undirected graph
def bfs_sp(n1,n2):
    q = [n1]
    dist[n1] = 0
    while q:
        node = q.pop(0)
        for nei in adjl[node]:
            if dist[nei]==-1:
                dist[nei] = dist[node]+1
                q.append((nei))
                if nei == n2:
                    return dist[nei]
    return -1'''
# connectivity in undirected graph
def connected(n):
    return (0 not in dist[1:n+1])

# detect cycle in undirected graph
def dfs_c(src,par):
    global dist
    dist[src] = 1
    for nei in adjl[src]:
        if not dist[nei]:
            if dfs_c(nei,src):
                return True
        elif nei != par:
            return True
    return False

# detect cycle in directed graph
def dfs_c_d(src):
    dist[src] = 1 # 1 for distiting
    for nei in adjl[src]:
        if not dist[nei]:
            if dfs_c_d(nei): # if dfs_c_d(nei,src): then it will be undirected
                return True
        elif dist[nei] == 1:
            return True
    dist[src] = 2 # backtracking
    return False
# connected components in undirected graph
def connectedComponents(n):
    dist = [0]*(n+1)
    cc = 0
    for i in range(1,n+1):
        if not dist[i]:
            cc += 1
            dfs_c(i,-1)
    return cc    
for i,(e,f) in enumerate(zip(p,q)):
    if e in adjl:
        adjl[e].append(f)
    else:
        adjl[e] = [f]
    if f in adjl:
        adjl[f].append(e)
    else:
        adjl[f] = [e]
# # # # # printList()
sr = p[0]
for e in adjl:
    if len(adjl[e]) > len(adjl[sr]):
        sr = e
bfs_s(sr)
far = dist[:n+1].index(max(dist[:n+1]))
dist = [-1]*1000
bfs_s(far)
if -1 in dist[1:n+1]:
    print (-1)
else:
    print(max(dist[:n+1]))
print(connectedComponents(n))