n,m = [int(x) for x in input().split()]

adjl = [[] for _ in range(n+1)]
edges = []
visited = [False for _ in range(n+1)]

# DSU

parent = [i for i in range(n+1)]
rank = [0 for _ in range(n+1)]
def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]
def union(x,y):
    x = find(x)
    y = find(y)
    if x == y:
        return
    if rank[x] < rank[y]:
        parent[x] = y
    elif rank[x] > rank[y]:
        parent[y] = x
    else:
        parent[y] = x
        rank[x] += 1


for _ in range(m):
    u,v = [int(x) for x in input().split()]
    adjl[u].append(v)
    adjl[v].append(u)
    edges.append((u,v))

for u,v in edges:
    union(u,v)

# Step 1: Count the number of connected components

def dfs(u):
    visited[u] = True
    for v in adjl[u]:
        if not visited[v]:
            dfs(v)

def countCC():
    cc = 0
    for i in range(1,n+1):
        if not visited[i]:
            dfs(i)
            cc += 1
    return cc
_c = countCC()
# Enumerate the connected components
d = dict()
t= 0
for e in parent[1:]:
    if e not in d:
        d[e] = t
        t += 1
print(d)

def countCCWithExactly1Cycle():
    cc = countCC()
    ccCyclicComponents = [0 for _ in range(_c)]
    for u,v in edges:
        if find(u) == find(v):
            ind = d[find(u)]
            ccCyclicComponents[ind] += 1
    return ccCyclicComponents

print(countCCWithExactly1Cycle())
print(parent[1:],countCC())
