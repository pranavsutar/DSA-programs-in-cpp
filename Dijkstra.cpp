
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

#define vii vector<int>
#define vvi vector<vector<int>>
#define PB push_back
#define repp(n) for (int i = 0; i < n; i++)
#define rrep(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define loop(i, n) for (int i = 0; i < n; i++)

using namespace std;
const int inf = INT_MAX;
int main(){
    int n, m,u,v,w, source; cin >> n >> m;
    vii dist(n+1,inf);
    vector<vector<pair<int,int>>> graph(n+1);
    loop(i,m){
        cin >> u >>  v >> w;
        graph[u].push_back({v,w});
        // graph[v].push_back({u,w}); -> for undirected case;

    }
    cin >> source;
    dist[source] = 0;
    set<pair<int,int>> s;
    s.insert({0,source});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for (auto it: graph[x.ss])
        {
            if(dist[it.ff] > dist[x.ss]+it.ss){
                s.erase({dist[it.ss], it.ff});
                dist[it.ff] = dist[x.ss] + it.ss;
                s.insert({dist[it.ff], it.ff});
            }
        }
        rep(i,1,n+1){
            if(dist[i] != inf) cout << dist[i] << " ";
            else cout << -1 << " ";
        }       
    }
    return 0;
}
/*
Input 1

4 4
1 2 24
1 4 20
3 1 3
4 3 12
1

 */