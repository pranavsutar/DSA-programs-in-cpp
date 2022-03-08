/*#include <iostream>
using namespace std;

float f(float m,float n){
    if(n==0) return 1;
    if(m==0) return 0;
    return (m*f(m,n-1) + n*f(m-1,n))/(m+n);
}

int main()
{
    float n;
    cout<<"Its running\b\b";
    cin>>n;
    cout<<f(n,n);
    // cout<<n<<" Finally!!!!!!!!";
    return 0;
}
*/

#include <bits/stdc++.h>
// #include <vector>
// #include <queue>
#define PB push_back
// #define ll left
// #define rr right
#define pll push(n->left)
#define prr push(n->right)

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
void levelOrder(Node *root)
{
    vector<int> v;
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    Node *n ;
    while (!q.empty())
    {
        n = q.front();
        q.pop();
        if (n)
        {
            // v.push_back(n->data);
            cout << n->data << " ";
            if (n->left)
                q.pll;
            if (n->right)
                q.prr;
        }
        else if (!q.empty())
            q.push(NULL);
    }
}

bool isAncestor(Node* anc, Node* child){
    //Checks whether anc is ancestor of Child or not
    if(anc == child) return true;
    if(!anc) return false;

    return isAncestor(anc->left,child) || isAncestor(anc->right, child) ;
}
Node* findLCA(Node* root,int l1,int l2 ){
    if(!root) return NULL;
    int key = root->data;
    if(key == l1 || key == l2) return root;

    Node* leftt = findLCA(root->left,l1,l2);
    Node* rightt = findLCA(root->right,l1,l2);

    if(leftt && rightt) return root;
    if((!leftt) && (!rightt)) return NULL;
    if(rightt) return rightt;
    if(leftt) return leftt;
}
int calDist(Node* root, Node* c ){
    if (!root || !isAncestor( root, c ))
        return -1;
    queue<Node* > q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    Node *n ;
    while (!q.empty())
    {
        n = q.front();
        q.pop();
        if (n)
        {
            if(n ==  c){
                break;
            }
            if (n->left)
                q.pll;
            if (n->right)
                q.prr;
        }
        else if (!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return level;
}
int CalD(Node* root, int k){
    // if (!root || !isAncestor( root, c ))
    //     return -1;
    queue<Node* > q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    Node *n ;
    while (!q.empty())
    {
        n = q.front();
        q.pop();
        if (n)
        {
            if(n->data ==  k){
                break;
            }
            if (n->left)
                q.pll;
            if (n->right)
                q.prr;
        }
        else if (!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return level;
}
int calDistance(Node* root, Node* n1, Node* n2){
    Node* n = findLCA(root, n1->data, n2->data);
    int d1 = calDist(n, n1);
    int d2 = calDist(n, n2);
    return d1+d2 ;
}
int calculateDist(Node* root, int l1, int l2){
     Node* n = findLCA(root, l1,l2 );
    int d1 = CalD(n, l1);
    int d2 = CalD(n, l2);
    return d1+d2 ;
 }

void rightView(Node* root){
    //To make it right View, refer the following
    vector<int> v;
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    Node *n ;
    while (!q.empty())
    {
        n = q.front();
        q.pop();
        if (n)
        {
            v.push_back(n->data);
            // cout << n->data << " ";
            if (n->left)
                q.pll;
            if (n->right)
                q.prr;
        }
        else if (!q.empty()){
            q.push(NULL);
            cout<<v[v.size()-1]<<" ";
            level++;
            v.clear();
        }
            
    }
    cout<<v[v.size()-1];
}

void flatten(Node* root){
    if(!root) return;
    flatten(root->left);
    flatten(root->right);

    Node* n = root->left;
    if(!n) return;
    while(n->right) n = n->right;
    n->right = root->right;
    root->right = root->left;
    root->left = NULL;
}

int sumAtK(Node *root, int k)
{
    int p = 0, level = 0;
    if (!root)
        return -1;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    Node *n = root;
    while (!q.empty())
    {
        n = q.front();
        q.pop();
        if (n)
        {
            // v.push_back(n->data);
            // cout<<n->data<<" ";
            if (level == k)
            {
                p += n->data;
            }
            if (n->left)
                q.pll;
            if (n->right)
                q.prr;
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }

    return p;
}


int sumHeight(Node* root){
    if(!root) return 0;
    return max(sumHeight(root->right),sumHeight(root->left) ) + root->data;
}
int maxSumOfPath(Node* root){
    
    if(!root) return 0;
    int ls = maxSumOfPath(root->left);
    int rs = maxSumOfPath(root->right);
    int lhs = sumHeight(root->left);
    int rhs = sumHeight(root->right);
    int cs = lhs + rhs + root->data;

    return max(cs, max(ls,rs));
}

int advDia(Node* root, int &h){}
int TreeHeight(Node *root)
{
    if (root)
        return 0;
    return max(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}
int Diameter(Node* root){
    if(!root) return 0;

    int ld= Diameter(root->left),
    rd = Diameter(root->right),
    lh = TreeHeight(root->left),
    rh = TreeHeight(root->right),
    cd = lh + rh + 1 ;

    return max(cd, max(ld,rd));
}
int SumofAllNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return SumofAllNodes(root->left) + SumofAllNodes(root->right) + root->data;
}
vector<tuple<int,int,int>> levelmatrix(Node* root, int p, int q){
    
    vector <tuple<int,int,int>> a;
    if(!root) return a;

    a.push_back({p,q,root->data});
    vector <tuple<int,int,int>> al(levelmatrix(root->left,p-1,q+1));
    vector <tuple<int,int,int>> ar(levelmatrix(root->right,p+1,q+1));
    
    a.insert(a.end(),al.begin(),al.end());
    a.insert(a.end(),ar.begin(),ar.end());
    return a;
}
void topview(Node* root)
{
    int o=0;
    vector <tuple<int,int,int>> a(levelmatrix(root,o,o));
    sort(a.begin(),a.end());
    cout<<get<2>(a[0])<<" ";
    for(int i=1;i<a.size();i++){
        if(get<0>(a[i]) != get<0>(a[i-1]))
        cout<<get<2>(a[i])<<" ";
    } 
    cout<<endl;
}
void bottomview(Node* root)
{
    int o=0;
    vector <tuple<int,int,int>> a(levelmatrix(root,o,o));
    for(int i =0;i<a.size();i++) get<1>(a[i]) *=-1;
    sort(a.begin(),a.end());
    cout<<get<2>(a[0])<<" ";
    for(int i=1;i<a.size();i++){
        if(get<0>(a[i]) != get<0>(a[i-1]))
        cout<<get<2>(a[i])<<" ";
    } 
    cout<<endl;
}

/*

              1
             / \
            2   3
           / \   \
          4   5   6
                 /
                7
                 \
                  8
                   \
                    9
*/
int main()
{
    cout<<"Working :\n";
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    //  = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->left->right = new Node(8);
    root->right->right->left->right->right = new Node(9);
    //  = new Node(8);
    // preorder(root); cout<<endl;
    // inorder(root);cout<<endl;
    // postorder(root);cout<<endl;
    // levelOrder(root);cout<< "\nMODIFIED:\n\n";
    // flatten(root);
    // preorder(root); cout<<endl;
    // inorder(root);cout<<endl;
    // postorder(root);cout<<endl;
    // levelOrder(root);
    // topview(root);
    // bottomview(root);
    cout << maxSumOfPath(root)<<"\n";
    // cout << endl<< sumAtK(root, 2) << "\n"<< SumofAllNodes(root);
    // rightView(root);
    // int d =0;
    // cout<< calculateDist(root, 2, 4);
    cout<<"\nIti Sampurna";
    return 0;
}

