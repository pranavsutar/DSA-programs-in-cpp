n = int(input())
# accepting n hexgonal points
points = []
for _ in range(n):
    x, y = map(int, input().split())
    points.append((x, y))
# print(points)
#  enumerating the points and creating a graph
adjl = [[] for _ in range(n)]
edges = []


def check(x1,y1,x2,y2):
    if x1 == x2:
        return abs(y1-y2) <= 1
    if y1 == y2:
        return abs(x1-x2) <= 1
    if x1 == x2 + 1 and y1 == y2 + 1:
        return True
    if x2 == x1 + 1 and y2 == y1 + 1:
        return True
    return False
    return (abs(x1-x2) < 2 and abs(y1-y2) < 2)
for i in range(n):
    for j in range(i+1, n):
        x1, y1 = points[i]
        x2, y2 = points[j]
        # if check(x1,y1,x2,y2) then add edge i, j
        if check(x1,y1,x2,y2):
            adjl[i].append(j)
            adjl[j].append(i)
            edges.append((i, j))
# printing adjaceny list
# for i in range(n):
#     print(i,'->',adjl[i])

# count of connected components using dsu
parent = [i for i in range(n)]
rank = [0 for _ in range(n)]
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
def countCC():
    for u,v in edges:
        union(u,v)
    cc = set()
    for i in range(n):
        cc.add(find(i))
    return len(cc)
# def countCC():
#     for i in range(n):
#         for j in adjl[i]:
#             union(i,j)
#     cc = set()
#     for i in range(n):
#         cc.add(find(i))
#     return len(cc)

print(countCC())
