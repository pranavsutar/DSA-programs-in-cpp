#include <bits/stdc++.h>

#define PB push_back
#define ll long long
#define lll left
#define rrr right
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
    // reverse(s.begin(),s.end());
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
  
    // cout << " MM\n";
    int n = a.size();
    vvi c(n, vii(n, 0));

    loop(i, n)
    {
        loop(j, n)
        {
            loop(k, n)
            {
                c[i][j] |= (a[i][k] & b[k][j]);
            }
        }
    }
    return c;

   
}

void Verify(vvi a, vvi b, int n){
    loop(i,n) loop(j,n) if(a[i][j] != b[i][j]) {
        cout << "UNEQUAL!!!!!!!!!!!!!!!!!!\n";
        return;
    }
    cout <<n<<" EQUAL\n";
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


int main(){
    repp(100){
    int n = 2+rand()%7;
    vvi a(n,vii(n,0));
    loop(i,n){
        loop(j,n){
            a[i][j] = rand()%2;
        }
    }
    vvi b(n,vii(n,0));
    loop(i,n){
        loop(j,n){
            b[i][j] = rand()%2;
        }
    }
    printm(a);
    printm(b);
    vvi cm(matrixmul(a,b));
    vvi cr(Russian(a,b));
    Verify(cm,cr,n);}
    return 0;
}