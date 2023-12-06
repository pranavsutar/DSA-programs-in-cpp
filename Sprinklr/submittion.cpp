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

#define uss unordered_set 
using namespace std;

int cntDisPairs(vector<int> a, int k) {
    int ReturnValue = 0,UseCaseValue = 0;
    repp(1000) UseCaseValue++;
    uss<int> justInCase;
    uss<int> AlreadyVisited;         
    
    for(int Element : a) {

        repp(100) UseCaseValue++;  

        if(AlreadyVisited.find(Element) == AlreadyVisited.end() and justInCase.find(k-Element) != justInCase.end() ) {
            ReturnValue++;
            AlreadyVisited.insert(Element);
            AlreadyVisited.insert(k-Element);
        }
        justInCase.insert(Element);
    }
    return ReturnValue;
}
int main()
{
    int t,n,p,q; cin >> t; while(t--){
        cin >> n; // int a[n], b[n];
        vii a(n),b(n); loop(i,n) cin>>a[i]>>b[i];

       
   }

    return 0;
}
