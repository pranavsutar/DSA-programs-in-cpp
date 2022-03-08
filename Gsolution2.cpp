#include <bits/stdc++.h>
using namespace std;


// bool valid(int a, int b , int c ){
//     return (2*b == a+c) || (a+c)%(2*b)==0 || (2*b-a)%c == 0 || (2*b - c)%a == 0 ;
// }
// bool search(int a[], int n, int key)
// {
//     if(n==0) return false;
//     return search(a,n-1,key) || a[n-1] == key ;
// }

// vector<int> merge(vector<int> a, vector<int> b, int n, int m)
// {
//     vector<int> vv;
//     if(m==0 && n==0) return vv;
//     if(m==0){
//         vector<int> v(a);
//         return v;
//     }
//     if(n==0){
//         vector<int> v(b);
//         return v;
//     }
//     vector<int> v(merge(a,b,n-1,m-1));
//     if(a[n-1]>=b[m-1]){
//         v.push_back(b[m-1]);
//         v.push_back(a[n-1]);
//         return v;
//     }
//     if(a[n-1]<b[m-1]){
//         // vector<int> v(merge(a,b,n,m-1));
//         v.push_back(a[n-1]);
//         v.push_back(b[m-1]);
//         return v;
//     }
//  return v;
// }
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node* prev;
//     Node(int v){
//         data = v;
//         next = NULL;
//         prev = NULL;
//     }
// };
// class DLL{
//     public:
//     Node* head;
//     void push(int v){
//         Node* n = new Node(v);
//         // next= &n;
//         // n->prev = ;
//         n->next = NULL;
// }
// };
// int average(int a[],int n){
//     if(n==1) return a[0];
//     return ((n-1)*average(a,n-1) + a[n-1])/n;
// }
// int* sort(int a[],int n){
//     if(n==1)
//      return a;
//     int b[n],i,j;
//     // sort(a+1,n-1);
//     i=0;
//     while(a[0]>sort(a+1,n-1)[i]) i++;
//     for(j=0;j<=i;j++){
//         b[j] = sort(a+1,n-1)[j];
//     }
//     b[j] = a[0];
//     for(;j<n;j++) b[j] = sort(a+1,n-1)[j-1];
//     return b;
// }
// bool isSorted(int a[], int n){
//     if(n==1) return true;
//     return isSorted(a+1,n-1) && a[0]<=a[1];
// }

// void print(Node* nn){
//     Node* n = nn;
//     while(n){
//         cout<<n->data;
//         n = n->next;
//     }
// }
// bool AP(int a[], int n){
//     if(n<=2) return true;
//     return (a[0]- a[1] == a[1] - a[2]) && AP(a+1,n-1);
// }
// void darr(int a[], int n)
// {
//     if (n >= 1)
//     {
//         int p = n/2;
//         darr(a, p);
//         cout << a[p] << " ";
//         darr(a + p + 1, n - p - 1);
//     }
// }
// void parr(int a[], int n){
//     if(n<=2){
//         cout<<a[0]<<" ";
//         return;
//     }
//     int p = n/2;
    
//     parr(a,p+1);
//     parr(a+p+1,n-p-1);
//     cout<<a[1]<<" ";
// }
// void modify(int a[], int b[], int n){
//     int p = log2(n),i,j=0;
//     b[j]  = a[0];
//     j++;
//     p = pow(2,p);
//     while(p){
//         for(i=0;i<n;i+=p) if(i%(2*p)){
//             b[j] = a[i];
//             j++;
//         }
//         p = p/2;
//     }   
// }
bool BiSearch(int a[], int n, int key){
    if(n==1) return a[0] == key;
    int mid = n/2;
    if(a[mid] == key) return true;
    if(key < a[mid]) return BiSearch(a,mid,key);
    return BiSearch(a +mid + 1,n -mid -1,key);

}
// 1...p-1,p,p+1,...n
// 0...,p-1,p,p+1,......n-1 -- p+k = n-1
// void bogo(int a[],int n){
//     while(!isSorted(a,n)){
//         random_shuffle(a,a+n);
//         swap(a[0],a[n-1]);
//     }
// }
void Print(int a[], int n){
    if(n>0){
        cout<< a[0]<<" ";
        Print(a+1,n-1);
    }    
}
void groups(int a[], int n, int k){
    int i =0;
    for(; i<n-k; i+=k){
        // Print(a+i,k);
        // cout<<"| ";
        reverse(a+i,a+i+k);
    }
    // Print(a+i,min(k,n-i));
    reverse(a+i,a+i+min(k,n-i));
    
}



// void sweep(int a[], int from, int to, int n){
//         int p,j;
//         if(from == to) return;
//         if(from<to){
//             p = a[from];
//             j = from;
//             while(j<to){
//                 a[j] = a[j+1];
//                 j++;
//             }
//             a[j] = p;
//         }
//         else {
//             p = a[from];
//             j = from;
//             while(j>to){
//                 a[j] = a[j-1];
//                 j--;
//             }
//             a[to] = p;
//         }
//     }
int main()
{
    int t, n, m, key, to ,from,i;
    cout << "WORKING\n";
    cin >> t;

    while (t--)
    {
        cin >> n 
        >> key ;
        int a[n],b[n];
        // vector<int> a(n) ,b(m);
        for (i = 0; i < n; i++)
            cin >> a[i];
            Print(a,n); cout<<endl;
            groups(a,n,key);
            // sweep(a,from,to,n);
            Print(a,n);cout<<endl;
            // sort(a,a+n);
        // for(i=0;i<m;i++) cin>>b[i];
        // vector<int> c(merge(a,b,n,m)) ;
        // bogo(a,n);
        // for(i=0;i<n;i++) cout<<a[i]<<" ";
        // cout<< endl;
        // darr(a, n);
        // cout<<BiSearch(a,n,key)<<"\n";
    //     modify(a,b,n);
    // for(i=0;i<n;i++) cout<<b[i]<<" ";
    // cout<<endl;
    //     cout << endl;
    }

    return 0;
}

/**
 *
 *  @brief
 4 10
-10 50
80 50
80 -10
-10 -10


 * @brief
 *
 *
 *
 4 15
 0 50
 60 50
 -10 -20
 20 -20


 */
