#include <bits/stdc++.h>
// #include <vector>
// #include <queue>
#define PB push_back
// #define ll left
// #define rr right
#define pll(n) push(n->left)
#define lll(n) n->left
#define prr(n) push(n->right)
#define rrr(n) (n->right)

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
int inorder(Node* root, int x){
    
    if(root){
       int y;
        inorder(root->left);
        if(root->data == x) return y;
         y = root->data;
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
                q.pll(n);
            if (n->right)
                q.prr(n);
        }
        else if (!q.empty())
            q.push(NULL);
    }
}

Node* insertBST(Node* root, int val){
    if(!root) return new Node(val);
    int dt = root->data;
    if(val<dt) root->left = insertBST(lll(root),val);
    else rrr(root) = insertBST(rrr(root),val);

    return root;
}
Node* buildBST(int arr[],int n){
    if(n==0) return NULL;
    Node* root = NULL;
    for(int i=0;i<n;i++) root = insertBST(root,arr[i]);
    return root;
}
int maxBST(Node* root){
    if(!root->right) return root->data;
    return maxBST(root->right);
}
int minBST(Node* root){
    if(!root->left) return root->data;
    return maxBST(root->left);
}

int precessador(Node* root, float val){
    if(!root) return INT_MIN;
    int key = root->data;
    if(!root->left && val < key) return INT_MIN;
    if(val == key){
        if(root->left) return maxBST(root->left);
        else return INT_MIN;
    } 
    if(val<key){
        if(root->left) return precessador(root->left, val);
        else return INT_MIN;
    } 
    if(val>key){
        if(root->right) return max(key,precessador(root->right, val));
        return key;
    } 
}

int main()
{
    cout<<"Working :\n";
    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // //  = new Node(5);
    // root->right->right = new Node(6);
    // root->right->right->left = new Node(7);
    // root->right->right->left->right = new Node(8);
    // root->right->right->left->right->right = new Node(9);
    //  = new Node(8); 
    int a[10] = //{1,3,2,1,2,3,4,5,3,2};
    {5,6,7,9,1,2,4,8,10,3};
    // random_shuffle(a,a+10);
    for(int i=0;i<10;i++) cout<<a[i]<<" "; cout<<endl;
    Node* root = buildBST(a,10);
    cout << precessador(root, 5.9);
    // preorder(root); cout<<endl;
    // inorder(root);cout<<endl;
    // postorder(root);cout<<endl;
    // levelOrder(root);//cout<< "\nMODIFIED:\n\n";
    // flatten(root);
    // preorder(root); cout<<endl;
    // inorder(root);cout<<endl;
    // postorder(root);cout<<endl;
    // levelOrder(root);
    // topview(root);
    // bottomview(root);
    // cout << maxSumOfPath(root)<<"\n";
    // cout << endl<< sumAtK(root, 2) << "\n"<< SumofAllNodes(root);
    // rightView(root);
    // int d =0;
    // cout<< calculateDist(root, 2, 4);
    cout<<"\nIti Sampurna";
    return 0;
}

