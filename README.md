# CPlusPlus
 DSA and other stuff programs

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
#define repp(n)    for(int  i=0; i < n ; i ++ )
#define rrep(a,b)  for(int  i=a; i < b ; i ++ )
#define rep(i,a,b) for(int  i=a; i < b ; i ++ )
#define loop(i,n)  for(int  i=0; i < n ; i ++ )

using namespace std;


vvi matrixmul (vvi a, vvi b)
{
    cout <<" MM\n";
    int n = a.size();
    vvi c( n, vii(n,0));
    
    loop(i,n){
        loop(j,n){
            loop(k,n){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return c;
}

vvi   power (vvi A, int n)
{
  if (n<1)
    {
      vvi o (n + 1, vii (n + 1, 0));
      rep (i, 0, n)
      {
	o[i][i] = 1;
      }
      return o;
    }

  if (n == 1){
      cout << "Power\n";
      return A;
  }
    

  return matrixmul (A, power (A, n - 1));
}

void orrify (vvi a, vvi b, int n)
{
    cout << "Orify\n";
  rep (i, 0, n)
  {
    rep (j, 0, n)
    {
      a[i][j] = max (a[i][j], b[i][j]);
    }
  }
}

vvi touch (vvi a, int n)
{
    cout << "Touch\n";
  vvi o(n , vii (n, 0));
  rep (i, 0, n + 1)
  {
    orrify (o, power (a, i),n);
  }
  return o;
}

bool isConnected (vvi adj)
{
    cout <<"Connected\n";
    int n = adj.size();
  vvi o (touch (adj, adj.size ()));
  rep (i, 0, n)
  {
    rep (j, 0, n)
    {
        cout  <<o[i][j]<<"|";
      if (adj[i][j] == 1)
    	{
    	    return false;
    	}
    }
  }
  return true;
}

int main ()
{
  int n, m, i;
  cin >> n ;
  vvi adj (n, vii (n , 0));
  
 rep(i,0,n){
     rep(j,0,n){
         cin >>  adj[i][j] ;
     }
}

  rep (i, 0, n)
  {
    rep (j, 0, n)
    {
      cout << adj[i][j] << ' ';
    }
    cout << '\n';
  }
  
  if (isConnected(adj)) cout << "The Graph is Connected\n";
  else cout << "The Graph is not Connected\n";
  

  return 0;
}
