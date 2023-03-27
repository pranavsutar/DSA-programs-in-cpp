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

int main()
{
   int t; cin >> t; while(t--){
       
       int n, l;
       cin>>n>>l;

       vector<int> a(n), k(l);
       
       for(auto &e: a)
        cin>>e;

        for(auto &e: k)
        cin>>e;

        vector<pair<int, int>> b;

        b.PB({a[0], 0});

        for(int i=1; i<n; i++)
        {
            if(a[i] > b.back().ff)
                b.PB({a[i], i});
        }

        llll prefSum[n] = {0};

        prefSum[0] = a[0];

            for(int i=1; i<n; i++)
                prefSum[i] = prefSum[i-1] + a[i];

        auto getSum = [&](int l, int r)
        {
            if(l == 0)
                return prefSum[r];
            return prefSum[r] - prefSum[l-1];
        };

        b.PB({2e9, n});

        for(auto e: k)
        {
            int pos = -1;

            int low=0, high=b.size()-1;

            while (low <= high)
            {
                int mid = (low + high) / 2;

                if (b[mid].ff > e)
                {
                    pos = b[mid].ss-1;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }

            if(pos != -1)
                cout<<getSum(0, pos)<<" ";
            else
                cout<<0<<" ";
        }
        cout<<"\n";
   }

    return 0;
}
