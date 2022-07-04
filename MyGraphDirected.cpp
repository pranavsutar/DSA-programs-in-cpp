#include <bits/stdc++.h>


#define llll long long
/*Node Commands*/
#define ll left
#define rr right
#define pll(n) push(n->left)
#define lll(n) n->left
#define prr(n) push(n->right)
#define rrr(n) (n->right)
/*Vectors*/
#define vii vector<int>
#define vvi vector<vii>
#define vvvi vector<vvi>
#define PB push_back
/*Loops*/
#define repp(n)     for (int i = 0; i < n; i++)
#define rrep(a, b)  for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define loop(i, n)  for (int i = 0; i < n; i++)
/*Reverse Loops*/
#define repr(i, a, b) for (int i = b-1; i >= a; i--)
#define loopr(i, n)  for (int i = n-1; i >=0; i--)

using namespace std;
const int N = 1e5 + 2, MOD = 1e9 + 7;
int i;
vii liadj[N];
map<int,int> inDeg;
void showList(int n){
    cout << "Adjacency List:\n";
    rep(i,1,n+1){
        cout <<i <<"-> ";
        for(int x : liadj[i])
            cout << x << "|" ; cout << "\n";
    }    
}
void showAdj(vvi adj){
    cout << "Adjacency Matrix:\n";
    int n = adj.size();
    rep(i,1,n){
        rep(j,1,n) cout << adj[i][j] << " " ;cout << '\n';
    }    
}
bool isEdge(vvi adj, int v1, int v2, bool isDirected){
    if (isDirected) return adj[v1][v2];
    return adj[v1][v2] && adj[v2][v1];
}

// Breath First Search
void bfs(int n){
cout << "_____\nBreath First Search:\n";
    vii vis(n+1,0);
    queue<int> q;
    q.push(1); 
    vis[1] = true;
    punahPariksha:
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node <<"\n";
        for (auto i: liadj[node]){
            if(!vis[i]){
                vis[i]=true;
                q.push(i);
            }
        }
    }
    rep(i,1,n+1) if (vis[i]==0){
        vis[i]=true;
        q.push(i);
        goto punahPariksha;
    }    
}
void dfs(int n){
cout << "_____\nDeapth First Search:\n";
    vii vis(n+1,0);
    stack<int> s;
    s.push(1); 
    vis[1] = true;
    punahParikshaDwitiya:
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        cout << node <<"\n";
        for (auto i: liadj[node]){
            if(!vis[i]){
                vis[i]=true;
                s.push(i);
            }
        }
    }
    rep(i,1,n+1) if (vis[i]==0){
        vis[i]=true;
        s.push(i);
        goto punahParikshaDwitiya;
    }
    
}
void topoSort(int n){
    cout << "Topological Sorting :\n";
    auto inDegThis = inDeg;
    queue<int> q;
    
    vii vis(n+1,0);
    rep(i,1,n+1){
        if (inDegThis[i]==0)
        {
            cout <<"Indegree of "<< i << " is " <<inDegThis[i]<<"\n";
            vis[i]=1;
            q.push(i);
        }        
    }
    if (q.empty()){
        cout << "As the Graph is Cyclic, we couldn't do Topological Sort\nSorry\n";
        return;
    }
    punahParikshaaTrutiya:
    while(!q.empty()){
        i = q.front();q.pop();
        cout << i <<"\n";
        for(int in : liadj[i]){
            int p = --inDegThis[in];
            /*This is important*/
            if(!p){
                q.push(in);
                vis[in] = 1;
            }
        }
    }
    rep(i,1,n+1) if (vis[i]==0){
        vis[i]=1;
        q.push(i);
        goto punahParikshaaTrutiya;
    }
}


int main()
{
    cout << "Udbhava sthiti sanhaara kaarinim klesh-haariṇim|\nSarvam shreyaskarim sitaam natooham RamVallabhaam||\n";
    int n, m, x ,y;
    cin >> n >> m;
    vvi adj(n+1,vii(n+1,0));
    
    loop(i,m){
        cin >> x >> y;
        adj[x][y] = 1; // Points x->y
        //  adj[y][x] = 1;  
        liadj[x].push_back(y); // Points x->y
        // /*In Undirected Case*/ liadj[y].push_back(x);
        inDeg[y]++;
    }
    cout << isEdge(adj,2,5,true)<<endl;
    showAdj(adj);
    showList(n);
    bfs(n);
    dfs(n);
    return 0;
} // namespace std;


/*
#1
7 7
1 2
1 3
2 4
2 5 
2 6
2 7
7 3

#2 -> Unconnected
7 4
1 2
2 4
6 7
7 5

#3
8 2
1 5
3 8

*/