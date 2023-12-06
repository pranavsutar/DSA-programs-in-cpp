def minDistBetweenTwoNodesinGraph(adjl,src,dest):
    q = []
    q.append(src)
    visited = [False for _ in range(len(adjl))]
    visited[src] = True
    dist = [0 for _ in range(len(adjl))]
    while len(q) > 0:
        node = q.pop(0)
        for child in adjl[node]:
            if not visited[child]:
                dist[child] = dist[node] + 1
                visited[child] = True
                q.append(child)
    return dist[dest]

for _ in range(int(input())):
    n, c0 = map(int, input().split()) # c0 is black colored, others are white
    sequence = list(map(int, input().split())) # it is the sequence in each node is colored black
    black = [0 for _ in range(n+1)]
    black[c0] = 1
    # n-1 edges of the tree are given, we will use them to build the adjacency list
    adjl = [[] for _ in range(n+1)]
    for _ in range(n-1):
        u, v = map(int, input().split())
        adjl[u].append(v)
        adjl[v].append(u)
    curr_min = minDistBetweenTwoNodesinGraph(adjl,c0,sequence[0])
    black[sequence[0]] = 1
    print(curr_min, end=' ')
    for i in range(1, len(sequence)):
        # the minimum distance between any two black node to be printed
        for j in range(1, n+1):
            if black[j] == 1:
                curr_min = min(curr_min, minDistBetweenTwoNodesinGraph(adjl,sequence[i],j))
        print(curr_min, end=' ')
        black[sequence[i]] = 1
    print()