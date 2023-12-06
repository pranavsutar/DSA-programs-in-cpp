# Calculate the number of connected components in an undirected graph.
def dfs(node):
    visited[node] = True
    for i in adj[node]:
        if not visited[i]:
            dfs(i)

for _ in range(int(input())):
    n,m = map(int,input().split())
    adj = [[] for i in range(n+1)]
    for i in range(m):
        u,v = map(int,input().split())
        adj[u].append(v)
        adj[v].append(u)

    visited = [False]*(n+1)

    ans = 0
    for i in range(1,n+1):
        if not visited[i]:
            ans+=1
            dfs(i)
    print(ans)

