#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PB push_back
#define vii vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define mii map<int, int>

vii parent, Size;
vvvi adjl;
vvi edges;
int i,j,u,v,w,n,m,cost=0,count;
int find(int x){
    if (parent[x]== x) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void Union(int x,int y){
    x = find(x); y = find(y);
    if (x==y) return;
    if (Size[x] < Size[y]) swap(x,y);
    parent[y] = x;
    Size[x] += Size[y];
}
vvi Kruskal(int src){
    vvi OptimalEdges;
    // int n = adjl.size()-1;
    for(i=0;i<parent.size();i++) parent[i] = i;
    Size.resize(parent.size(),1);
    priority_queue <vii,vvi,greater<vii>> pq;
    for ( auto edge: adjl[src]){
        pq.push({edge[1],src,edge[0]});
    }
    int count = 0;cost = 0;
    while(!pq.empty()){
        vii edge = pq.top();  pq.pop();
        u = edge[1], v = edge[2], w = edge[0];
        if (find(u) == find(v)) continue;
        count++; cost += w;
        OptimalEdges.push_back({u,v,w});
        Union(u,v);
        for ( auto edge: adjl[v]){
            pq.push({edge[1],v,edge[0]});
        }
    }
    return OptimalEdges;
}
    
int main(){
    cin>>n>>m;
    parent.resize(n+1);
    Size.resize(n+1,1);
    adjl.resize(n+1);
    edges.resize(m);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        Size[i]=1;
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjl[u].PB({v,w});
        edges[i]={w,u,v};
    }
    // a priority queue with each element as a vector
    priority_queue<vii, vector<vii>, greater<vii>> pq;
    // for(int i=1;i<=n;i++){
    //     for(auto x:adjl[i]){
    //         pq.push({x[1],i,x[0]});
    //     }
    // }
    // choose a random vertex and add all its edges to the priority queue
    int src=1;
    for(auto x:adjl[src]){
        pq.push({x[1],src,x[0]}); // weight, src, dest
    }
    // int cost=0, count= 0;
    vvi OptimalEdges;
    // while (!pq.empty() and count < n){
    //     vii temp = pq.top(); // temp -> 0:weight, 1:src, 2:dest
    //     pq.pop();
    //     int u = temp[1], v = temp[2], w = temp[0]; 
    //     if (find(u) == find(v)) continue;
    //     cost += w; count++;
    //     OptimalEdges.PB({u,v});
    //     Union(u,v);
    //     for(auto x:adjl[v]){
    //         pq.push({x[1],v,x[0]});
    //     }        
    // }
    OptimalEdges = Kruskal(src);
    cout<<"Cost of MST is "<<cost<<endl;
    cout<<"Edges in MST are "<<endl;
    for(auto x:OptimalEdges){
        cout<<x[0]<<" "<<x[1]<<endl;
    }

    return 0;
}
/*
Input
Test Case 1
4 5
1 2 1
1 3 3
4 1 6
2 3 4
3 4 2

Test Case 2
8 13
1 2 1
1 3 2
1 4 3
2 5 4
2 6 5
3 5 6
3 6 7
4 6 8
4 7 9
5 8 10
6 8 11
7 8 12
1 8 13

 Output
Test Case 1
Cost of MST is 6
Edges in MST are
1 2
3 4
1 3

Test Case 2
Cost of MST is 34
Edges in MST are
1 2
1 3
2 5
3 5
4 6
5 8
1 4
*/