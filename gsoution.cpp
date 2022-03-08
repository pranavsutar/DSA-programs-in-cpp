#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int v){
        data = v;
        left = NULL;
        right = NULL;
    }

};

unsigned int precedence(char x)
{
    switch(x)
    {
        case '/' : return 4;
        case '*' : return 3;
        case '+' : return 2;
        case '-' : return 2;
    }
    return -1;
}

bool isOperator(char x){
    if(x == ('+' || '/' || '-' || '*' );
}

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


// void print(Node* nn){
//     Node* n = nn;
//     while(n){
//         cout<<n->data;
//         n = n->next;
//     }
// }


bool BiSearch(int a[], int n, int key){
    if(n==1) return a[0] == key;
    int mid = n/2;
    if(a[mid] == key) return true;
    if(key < a[mid]) return BiSearch(a,mid,key);
    return BiSearch(a +mid + 1,n -mid -1,key);

}

int main()
{
    int t, n, m, key, i;
    cout << "WORKING\n";
    cin >> t;

    while (t--)
    {
        cin >> n >> key;
        // >>m;
        int a[n],b[n];
        // vector<int> a(n) ,b(m);
        for (i = 0; i < n; i++)
            cin >> a[i];
            sort(a,a+n);

        cout<<BiSearch(a,n,key)<<"\n";
    }

    return 0;
}

/**
 *
 *  


 */
