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

# Path: Competitive Prohgramming\LongestPathAtcoder.py