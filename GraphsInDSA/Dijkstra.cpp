/**
 * @file Dijkstra.cpp
 * @date 2022-05-20
 * @brief Implementation of Dikstra Algorithm using Sets in C++
 * 
 */
#include <bits/stdc++.h>

#define PB push_back
#define ll left
#define rr right
#define ff first
#define ss second
#define pll(n) push(n->left)
#define lll(n) n->left
#define prr(n) push(n->right)
#define rrr(n) (n->right)
#define int long long

#define pii pair<int,int>
#define vii vector<int>
#define vvi vector<vector<int>>
#define PB push_back
#define repp(n) for (int i = 0; i < n; i++)
#define rrep(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define loop(i, n) for (int i = 0; i < n; i++)

using namespace std;
const int inf = LONG_MAX-2;a
signed main(){
    int n, m,u,v,w, source; cin >> n >> m;
    vii dist(n+1,inf);
    vector<vector<pair<int,int>>> graph(n+1);
    loop(i,m){
        cin >> u >>  v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});// -> for undirected case;

    }
    cin >> source;
    dist[source] = 0;
    set<pair<int,int>> s;
    priority_queue< pii, vector <pii> > pq;
    s.insert({0,source});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for (auto it: graph[x.ss])
        {
            if(dist[it.ff] > dist[x.ss]+it.ss){
                s.erase({dist[it.ff], it.ff});
                dist[it.ff] = dist[x.ss] + it.ss;
                s.insert({dist[it.ff], it.ff});
            }
        }
        
    }
    cout<<"_______________________________\n";
    rep(i,1,n+1){
        cout << i<<"--->\t";
        if( dist[i] != inf) cout << dist[i] << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
/*
Input Format-
no of vertices(n)
no of edges(m)
<the below m lines has info about each directed edge>
<start vertex> <end vertex> <weight of the vertex>

Input 1

4 4
1 2 24
1 4 20
3 1 3
4 3 12
1

_______________
Input 2

4 5
1 2 24
1 4 20
3 1 3
4 3 12
3 4 12
2
_______________
Input 3

6 8
1 2 4
5 4 18
3 1 3
4 3 12
3 4 30
1 5 25
2 6 40
4 6 14
3
_______________
Input 4a

6 7
1 4 10
1 2 20
2 5 4
2 3 15
3 6 2
6 5 5
5 4 3
1
_______________
Input 4b

6 7
1 4 9
1 2 20
2 5 1
2 3 15
3 6 6
6 5 3
5 4 2
1

 */