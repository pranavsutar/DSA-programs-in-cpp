
#include <bits/stdc++.h>

#define PB push_back
#define LL long long
#define ll left
#define rr right
#define pll(n) push(n->left)
#define lll(n) n->left
#define prr(n) push(n->right)
#define rrr(n) (n->right)

#define vii vector<int>
#define vvi vector<vii>
#define vvvi vector<vvi>
#define PB push_back
#define repp(n)     for (int i = 0; i < n; i++)
#define rrep(a, b)  for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define loop(i, n)  for (int i = 0; i < n; i++)

#define repr(i, a, b) for (int i = b-1; i >= a; i--)
#define loopr(i, n)  for (int i = n-1; i >=0; i--)

using namespace std;

// Converts Decimal to Binary
string nicebits(int a, int p){
    string s = "";
    while(a){
        s = s+ char(a%2 + '0');
        a=a/2;
    }
    while(s.length()<p){
        s = s+ "0";
    }
    // reverse(s.begin(),s.end());
    // cout <<"NBITS " << s <<'\n';
    return s;
}
int BintoDeci(string s){
    int l = s.length();
    if(l==1) return (s[0] - '0');
    return (s[0] - '0')*pow(2,l-1)+BintoDeci(s.substr(1));
}
int BintoDeci(int g){
    string s = to_string(g);
    return BintoDeci(s);
}

void printm(vii a)
{
    cout << "Vector\n";
    int n = a.size();
    rep(i, 0, n)
    {
        cout << a[i]<<" ";
        
    }cout << '\n';
    cout << "ITI Vector\n";
}
vii linCom(vvi b, int st, int comb, int p){
    int n = b.size(),j;
    vii v(n,0);
    string s = nicebits(comb,p);
    loop(j,n){
        for(int i = st; i< n /*min(st+p,n)*/; i++){
            v[j] |=( (s[i-st]-'0') & b[i][j]);
        }
    }
    // printm(v);
    return v;
}

// 4 Russian Multiplication
vvi Russian(vvi a, vvi b){
    int n = a.size(), p =round(log2(n));
    p = 4;
    // vvi table(n/p+1, vii(pow(2,p),0));
    vvvi table( n/p+1, vvi( pow(2,p)+1,vii(n,0)));
    //  Filling The Table:
    loop(i,n/p+1)/*for(int i = n/p;i>=0;i--)*/{
        loop(j,pow(2,p)){
            table[i][j] = linCom(b,i*p, j , p);            
        }
    }
    // cout << "The table\n";
    loop(i,n/p+1){
        loop(j,pow(2,p)){
            // loop(k,n) cout << table[i][j][k];
            // cout <<'\n';
        }
        // cout << "\n";
    }
// cout << "Table Filled\n";
// Retrieving the Table
    vvi c(n,vii(n,0));
    loopr(i,n){ // WE are obtaining  i-th row of C
        loop(k,n/p+1)/*for(int k = n/p;k>=0;k--)*/{ // We are in k-th p-set of table 
            int s = 0;
            repr(kk,p*k,min((k+1)*p,n)){
                s = s*10 + a[i][kk] ;
            }
            s = BintoDeci(s);
                        // cout <<"\t"<< s <<"\n";
            loopr(j,n){ // We are in j-th element of some row of table and c
                c[i][j] |= table[k][s][j];
            }
        }
    }
    return c;
}

vvi matrixmul(vvi a, vvi b)
{
    vvi v = Russian(a,b);
    return v;   
}

void printm(vvi a)
{
    cout << "Matrix\n";
    int n = a.size();
    rep(i, 0, n)
    {
        rep(j, 0, n) cout << a[i][j];
        cout << '\n';
    }
    cout << "ITI mAtrix\n";
}


vvi power(vvi A, int n)
{
    // cout << "Power\n";

    int N = A.size();
    vvi o(N, vii(N, 0));
    rep(i, 0, N)
    {
        o[i][i] = 1;
    }

    repp(n) o = matrixmul(o, A);

    // printm(o);
    return o;
    // return matrixmul (A, power (A, n - 1));
}
// Performs boolean OR operation on corresponding elements
vvi orrify(vvi a, vvi b, int n)
{
    // cout << "Orrify\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << '.';
            // if(a[i][j]==1  or b[i][j]==1)
            //     a[i][j] = 1;
            a[i][j] = a[i][j] | b[i][j];
        }
        // cout << '\n';
    }
    // printm(a);
    return a;
}
// For checking connectivity
vvi touch(vvi a, int n)
{
    // cout << "Touch\n";
    vvi o(n, vii(n, 0));
    rep(i, 0, n + 1)
    {
        o = orrify(o, power(a, i), n);
    }
    return o;
}

bool isConnected(vvi &adj, int n)
{
    // cout << "Connected\n";
    // int n = adj.size();
    vvi o(touch(adj, n));

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            // cout << o[i][j] << "|";
            if (o[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int shortestPath(vvi adj, int a, int b)
{
    int n = adj.size(), p ;
    if (a==b) return 0;
    if (adj[a][b] == 1 ) return 1;
    rep(p,1,n+1){
        vvi o(power(adj,p));
        if (o[a][b] > 0) return p;
    }

    return -1;
}

bool isAcyclic(vvi adj){
    int n = adj.size(), p ;

    rep(p,1,n+1){
        vvi o(power(adj,p));
        loop(i,n) {
            if (o[i][i] > 0) return false;
        }
    }
    return true;
}
int main()
{
    int n, m, i;
    cin >> n;
    vvi adj(n, vii(n, 0));

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            cin >> adj[i][j];
        }
    }
    cout << '\n';
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
    
    cout <<"Connectivity:\n";

    if (isConnected(adj, n))
        cout << "The Graph is Connected\n";
    else
        cout << "The Graph is not Connected\n";

    cout<<"\nShortest Path between TWO VERTICES\n";
    cout <<"Path from 0 to 3: " << shortestPath(adj,0 , 3 ) << '\n';
    cout <<"Path from 0 to last vertex: " << shortestPath(adj,0 , n-1 ) << '\n';
    cout <<"Path from 0 to second-last vertex: " << shortestPath(adj,0 , n-2 ) << '\n';
    cout <<"Path from last vertex to 0: " << shortestPath(adj,n-1 , 0 ) << '\n';

    cout << "\nCyclicity:\nThe Graph ";
    if(isAcyclic(adj)) cout << "Is NOT Cyclic\n";
    else cout << "Is Cyclic\n";

    cout << "\nShortest Path:\nEnter Number of TestCases: ";
    int fr,to,tt;cin>>tt;
    repp(tt){
        cout<<"\nPlease enter any two Vertices (any two integers from 0 to n-1):\n";
        cin>>fr>>to;
        cout<< "Shortest Path from "<<fr<<" to "<<to<<" is " << shortestPath(adj,fr,to)<<endl;
    }  

    return 0;
}
/*
For Checking Connectivity:

      0
     / 
    3___1
     \ /
      2
4
0 0 0 1
0 0 1 1
0 1 0 1
1 1 1 0


__________________
      0
     / 
    3___1
     \ 
      2
4
0 0 0 1
0 0 0 1
0 0 0 1
1 1 1 0
__________________
      0
    
    3___1
     \ /
      2
4
0 0 0 0
0 0 1 1
0 1 0 1
0 1 1 0
__________________



___
3
0 1 0
1 0 1
0 1 0

*/

/**
 * @brief 
 * ShortestPath and Cyclic Nature
// 3->2->1->0
      3
     / 
    2   0
     \ /
      1
4
0 1 0 0
0 0 1 0
0 0 0 1
0 0 0 0

__________________________
// 3->2->1->0->3->....
      3
     / \
    2   0
     \ /
      1
4
0 1 0 0
0 0 1 0
0 0 0 1
1 0 0 0
___________________________
0->1->2->3->4->5->6->7->0->...

7
0 1 0 0 0 0 0
0 0 1 0 0 0 0
0 0 0 1 0 0 0
0 0 0 0 1 0 0
0 0 0 0 0 1 0
0 0 0 0 0 0 1
1 0 0 0 0 0 0
_______________

5
0 0 0 0 1
0 0 1 1 0
0 1 0 1 0
0 1 1 0 1
0 1 0 0 1
__________________
__________________

8
0 0 0 0 1 1 1 0
0 0 1 1 0 0 0 1
0 1 0 1 0 0 0 0
0 1 1 0 1 1 0 0
0 1 0 1 0 1 1 1
0 1 1 0 1 0 0 0
0 1 0 0 1 0 1 1
1 0 0 0 1 1 0 1
__________________
__________________

7
0 0 0 1 1 1 0
0 1 1 0 0 0 1
0 0 1 0 0 0 0
0 1 1 0 1 0 0
0 1 1 0 1 0 0
0 0 0 1 0 1 1
1 0 0 1 1 0 1
_________________




 * 
 */