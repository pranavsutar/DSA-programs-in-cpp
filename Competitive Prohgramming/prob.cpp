#include <bits/stdc++.h>

#define PB push_back
#define llll long long
#define ll left
#define rr right
#define ff first
#define ss second
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

int sol(int a[],int  n){
    float sum=0, avg=0; int ans = 0;
    for(int i=0; i<n; i++){
        sum+=a[i];
        avg = sum/(i+1);
        if (avg == 1){
            ans++;
        }
    }
    return ans;
}

int main()
{
   int t,n,p,q; cin >> t; while(t--){
       cin >> n; int a[n];
         for(int i=0; i<n; i++)
              cin >> a[i];

        cout << sol(a,n) << endl;

       
   }

    return 0;
}
