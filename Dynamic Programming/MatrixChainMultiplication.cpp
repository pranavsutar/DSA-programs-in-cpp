#include <bits/stdc++.h>

#define PB push_back
#define llll long long
#define ll left
#define rr right
#define pll(n) push(n->left)
#define lll(n) n->left
#define prr(n) push(n->right)
#define rrr(n) (n->right)
#define int long long
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

int mcm(vii a, int n){
    vvi  dp(n+1, vii (n+1,LONG_MAX-INT_MAX/2));
    rep(i,0,n+1)
        rep(j,i,n+1){
            if ( i>=j ) {
                dp[i][j] = 0;
            }
            else{
                rep(k,i,j-1){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + a[i-1]*a[k]*a[j] );
                }
            }
        }
    // cout << dp[3][0]<< " ";
    // loop(i,n+1){
    //     loop(j,n+1) cout << dp[i][j] <<" "; cout << endl;
    // }
    return dp[1][n-1];
}

int mcm(vii a, int i, int j){
    if (i>=j) return 0;
    int ans = LONG_MAX-INT_MAX/2;
    rep(k,i,j-1){
        ans = min(ans , mcm(a,i,k) + mcm(a,k+1,j) + a[i-1]*a[k]*a[j]);
    }   
    return ans;
}

signed main()
{
    int n; cin >> n;
    vii a(n);
    loop(i,n) cin >> a[i];
    // cout << mcm(a,1,n-1);
    cout << mcm(a,n-1);
    // int c =0 ;
    // rep(l,10,40) rep (p, 10, 40) c ++;
    // cout << c;
    return 0;
}