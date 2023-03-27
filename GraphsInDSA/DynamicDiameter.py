# Given a Graph with n vertices which is a tree
n = int(input())
adjl = [[] for i in range(n+1)]
edges = []
farthest = 0

for i in range(n-1):
    u, v = map(int, input().split())
    adjl[u].append(v)
    adjl[v].append(u)
    edges.append((u, v))

# Find the diameter of the tree and the two vertices at the ends of the diameter
def find_diameter():
    global farthest
    q = [1]
    visited = [False] * (n+1) # visited[i] = True if i is visited
    visited[1] = True
    prev = [0] * (n+1) # prev[i] = j if i is visited after j
    while q:
        u = q.pop(0)
        for v in adjl[u]:
            if not visited[v]:
                visited[v] = True
                prev[v] = u # v is visited after u
                q.append(v)
    farthest = u # farthest is the last vertex visited
    diameter = 0
    q = [u]
    visited = [False] * (n+1)
    visited[u] = True
    while q:
        u = q.pop(0)
        for v in adjl[u]:
            if not visited[v]:
                visited[v] = True
                prev[v] = u
                q.append(v)
                diameter += 1
    return diameter, u, farthest

diameter = find_diameter()
dia, u, v = diameter[0], diameter[1], diameter[2]
print(diameter)
for i in range(1,n+1):
    if i == u or i == v:
        print(dia+1)
    else:
        print(dia)
