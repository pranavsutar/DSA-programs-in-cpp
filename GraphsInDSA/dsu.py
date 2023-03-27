# Input : Graph
n,m = int(), int()
n = int(input())
m = int(input())
adjl = [[] for _ in range(n+1)]
adjm = [[0 for _ in range(n+1)] for _ in range(n+1)]
vis = [False for _ in range(n+1)]
dist = [float('inf') for _ in range(n+1)]
edge = []

# dsu 
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
        
# print(parent[1:])
# union(1,2)
# print(parent[1:])
# union(3,4)
# union(3,5)
# print(parent[1:])
# union(1,3)
# print(parent[1:])


for _ in range(m):
    u, v = map(int, input().split())
    # add edge u, v
    adjl[u].append(v)
    adjl[v].append(u) # undirected graph
    adjm[u][v] = 1
    adjm[v][u] = 1 # undirected graph
    edge.append((u, v))
    # edge.append((v, u)) # undirected graph


# to check cycle
def checkCycle():
    for u,v in edge:
        if find(u) == find(v):
            return True
        union(u,v)
    return False
if checkCycle():
    print("Cycle is present")
else:
    print("Cycle is not present")

    # count number of connected components
def countCC():
    cc = 0
    for i in range(1,n+1):
        if parent[i] == i:
            cc += 1
    return cc

def dfs_s(src,ccvis):
    stack = [src]
    ccvis[src] = True
    for nei in adjl[src]:
        if not ccvis[nei]:
            stack.append(nei)
            dfs_s(nei,ccvis)

def connectedCount(n):
    ccvis = [False for _ in range(n+1)]
    cc = 0
    for i in range(1,n+1):
        if not ccvis[i]:
            dfs_s(i,ccvis)
            cc += 1
    return cc
    
print(connectedCount(n))
print(countCC())
# # disjoint set union
# class DSU:
#     def __init__(self, n):
#         self.parent = [i for i in range(n+1)]
#         self.rank = [0 for _ in range(n+1)]
#         self.size = [1 for _ in range(n+1)]
#         self.n = n
#         self.components = n

#     def find(self, a):
#         acopy = a
#         while a != self.parent[a]:
#             a = self.parent[a]
#         while acopy != a:
#             self.parent[acopy], acopy = a, self.parent[acopy]
#         return a

#     def union(self, a, b):
#         a = self.find(a)
#         b = self.find(b)
#         if a != b:
#             if self.rank[a] < self.rank[b]:
#                 a, b = b, a
#             self.parent[b] = a
#             self.size[a] += self.size[b]
#             if self.rank[a] == self.rank[b]:
#                 self.rank[a] += 1
#             self.components -= 1

#     def connected(self, a, b):
#         return self.find(a) == self.find(b)

#     def getsize(self, a):
#         return self.size[self.find(a)]

#     def getcomponents(self):
#         return self.components



"""Consider the problem of making change for n cents using the fewest number of
coins. Assume that each coin's value is an integer.
a. Describe a greedy algorithm to make change consisting of quarters, dimes,
nickels, and pennies. Prove that your algorithm yields an optimal solution.
b. Suppose that the available coins are in the denominations that are powers of c,
i.e., the denominations are c0; c1;...;ck for some integers c>1 and k >= 1.
Show that the greedy algorithm always yields an optimal solution.
c. Give a set of coin denominations for which the greedy algorithm does not yield
an optimal solution. Your set should include a penny so that there is a solution
for every value of n.

Solution:
a. Greedy algorithm:
    1. Sort the coins in decreasing order of their value.
    2. Start with the largest coin and keep adding it to the solution until the sum
    of the coins becomes greater than the amount to be changed.
    3. Repeat step 2 for the next largest coin.
    4. Repeat step 2 and 3 until the amount to be changed becomes 0.
    5. If the amount to be changed becomes negative, then the last coin added to
    the solution is not required. Remove it from the solution and add the next
    largest coin to the solution.

    Proof:
    Let's say we have a set of coins {c1, c2, c3, ..., cn} and we want to find the
    minimum number of coins required to make change for a given amount. Let's   
    assume that the greedy algorithm gives us a solution with n coins.
    

b. Greedy algorithm always yields an optimal solution:
    Let's say we have a set of coins {c1, c2, c3, ..., cn} and we want to find the


"""