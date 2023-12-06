# https://atcoder.jp/contests/dp/tasks/dp_g

# Traveling Salesman Problem

# Input:
# n, m
# next m lines: u, v, w
# n: number of nodes
# m: number of edges
# u, v: nodes
# w: distance between u and v

# Output:
# Find the length of the shortest path from start to end (0 to n-1)

'''
Sample Input:

5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1

Sample Output:
5'''

n, m = map(int, input().split())
AdjList = [[] for _ in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    AdjList[u-1].append((v-1, w))
    AdjList[v-1].append((u-1, w))

# print minimum distance from 0 to n-1, and -1 if no path exists

# Dijkstra's algorithm
import heapq

def dijkstra(s):
    dist = [float('inf')] * n
    dist[s] = 0
    pq = [(0, s)]
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in AdjList[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))
    return dist

dist = dijkstra(0)
print(dist[n-1] if dist[n-1] != float('inf') else -1, end='')


# https://atcoder.jp/contests/dp/tasks/dp_g

import sys
sys.setrecursionlimit(10**6)

def dfs(v):
    if dp[v] != -1:
        return dp[v]
    dp[v] = 0
    for u in graph[v]:
        dp[v] = max(dp[v], dfs(u) + 1)
    return dp[v]

n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
    x, y = map(int, input().split())
    graph[x-1].append(y-1)

dp = [-1] * n
ans = 0
for i in range(n):
    ans = max(ans, dfs(i))
print(ans)

# Path: Competitive Prohgramming\LongestPat