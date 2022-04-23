
#include <bits/stdc++.h>

#define PB push_back
#define ll left
#define rr right
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

vvi matrixmul(vvi a, vvi b)
{
    cout << " MM\n";
    int n = a.size();
    vvi c(n, vii(n, 0));

    loop(i, n)
    {
        loop(j, n)
        {
            loop(k, n)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
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
    cout << "Power\n";

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

vvi orrify(vvi a, vvi b, int n)
{
    cout << "Orrify\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << '.';
            // if(a[i][j]==1  or b[i][j]==1)
            //     a[i][j] = 1;
            a[i][j] = max(a[i][j], b[i][j]);
        }
        cout << '\n';
    }
    printm(a);
    return a;
}

vvi touch(vvi a, int n)
{
    cout << "Touch\n";
    vvi o(n, vii(n, 0));
    rep(i, 0, n + 1)
    {
        o = orrify(o, power(a, i), n);
    }
    return o;
}

bool isConnected(vvi &adj, int n)
{
    cout << "Connected\n";
    // int n = adj.size();
    vvi o(touch(adj, n));

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            cout << o[i][j] << "|";
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
    if (adj[a][b] == 1 or a==b) return 0;
    rep(p,1,n+1){
        vvi o(power(adj,p));
        if (o[a][b] > 0) return p;
    }
    return p;
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
    // printm(power(adj, 1));
    // loop(i, n + 1)
    // {
    //     cout << i << '\n';
    //     printm(power(adj, i));
    // }

    // if (isConnected(adj, n))
    //     cout << "The Graph is Connected\n";
    // else
    //     cout << "The Graph is not Connected\n";

    cout <<"Path between 0 and 3 -" << shortestPath(adj,0 , 3 ) << '\n';
    cout <<"Path between 1 and 2 -" << shortestPath(adj,1 , 2 ) << '\n';
    cout <<"Path between 0 and 2 -" << shortestPath(adj,0 , 2 ) << '\n';
    return 0;


}
/*
4
0 0 0 1
0 0 1 1
0 1 0 1
1 1 1 0

4
0 0 0 1
0 0 0 1
0 0 0 1
1 1 1 0

4
0 0 0 0
0 0 1 1
0 1 0 1
0 1 1 0

3
0 1 1
1 0 1
0 1 0

*/

/**
 * @brief 
 * ShortestPath
// 3->2->1->0
4
0 1 0 0
0 0 1 0
0 0 0 1
0 0 0 0


 * 
 */