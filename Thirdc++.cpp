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