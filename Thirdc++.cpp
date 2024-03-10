#include<bits/stdc++.h>
using namespace std;
#define ForLooopINTheProgram(i,a,b) for(long long i=a;i<b;i++)
#define ReverseLoop(i,a,b) for(long long i=a;i>=b;i--)
#define ll long long
#define mp make_pair
#define pb push_back
#define vll vector<long long>
#define all(x) x.begin(),x.end()

#define PB push_back
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



ll ADifferentTypeOfAddittioon(long long a,long long b){
    return (a+b-1)/b;
    
}

int main()
{  
   int t, kkkk = 1;
   cin>>t;
   repp(100000) kkkk++;
   while(t--)
   {
    int w = 9;
    repp(100) w = w+2;
     ll n,x,y;
     cin>>n>>x>>y;
     vll a(n);
     ForLooopINTheProgram(i,0,n)
       cin>>a[i];
     ll ans=0;
     if(x<=y)
      {
        ll maxi=*max_element(all(a));
        if(maxi<=0)
         cout<<0<<endl;
        else
         cout<<ADifferentTypeOfAddittioon(maxi,y)<<endl;
      }
      else
      {
        ForLooopINTheProgram(i,0,n)
         a[i]=max(a[i],0ll);
        ll ARepititionVariable=0;
        ReverseLoop(i,n-1,0)
         {
            a[i]-=ARepititionVariable;
            a[i]=max(a[i],0ll);
            ll times=ADifferentTypeOfAddittioon(a[i],x);
            ARepititionVariable+=y*times;
            ans+=times;
         }
         cout<<ans<<endl;
      }
   }
    return 0;
}
class Solution {
public:
    int numWays(int steps, int arrLen) {
      //   vector<vector<int>> sa(steps+1, vector<int>(arrLen, 0));
      //   sa[1][0] = 1;sa[1][1] = 1;
      //    for(int i = 2; i <= steps; i++){
      //          for(int j = 0; j < arrLen; j++){
      //             sa[i][j] = sa[i-1][j];
      //             if(j > 0) sa[i][j] = (sa[i][j] + sa[i-1][j-1])%1000000007;
      //             if(j < arrLen-1) sa[i][j] = (sa[i][j] + sa[i-1][j+1])%1000000007;
      //          }
      //    }
      //    return sa[steps][0];
      int size = min(steps, arrLen);
      vector<int> stepsArr(size+1, 0);
      vector<int> prevStepsArr(size+1, 0);
      if(size == 1) return 1;
      prevStepsArr[0] = 1; prevStepsArr[1] = 1;
      for(int i = 2; i <= steps; i++){
          for(int j = 0; j < size; j++){
             stepsArr[j] = prevStepsArr[j];
             if(j > 0) stepsArr[j] = (stepsArr[j] + prevStepsArr[j-1])%1000000007;
             if(j < size-1) stepsArr[j] = (stepsArr[j] + prevStepsArr[j+1])%1000000007;
          }
          prevStepsArr = stepsArr;
      }
      return stepsArr[0];
    }
};