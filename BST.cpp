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

int f[6] = {0,0,0,0,0,0};
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
            cout << ' ';
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
    return minBST(root->left);
}
bool SearchBST(Node *root, int val){
    if(!root) return false;
    if(root->data== val) return true;
    else if(root->data > val) return SearchBST(root->left,val);
    else return SearchBST(root->right,val);
}
Node* Minelepointer(Node* root){
    Node* curr = root;
    while(curr and curr->left) curr = curr->left;
    return curr;
}
Node* BSTdelete(Node* root, int key){

    if(key<root->data) root->left = BSTdelete(root->left, key);
    else if(key>root->data) root->right = BSTdelete(root->right,key);
    else{
        if(!root->left){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(!root->right){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = Minelepointer(root->right);
        root->data = temp->data;
        root->right = BSTdelete(rrr(root),temp->data);
    }
    return root;
    
}
int precessador(Node* root, float val){
    if(!root) return INT_MIN;
    int key = root->data;
    // if(!root->left && val < key) return INT_MIN;
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

int successor(Node* root, float val){
    if(!root) return INT_MAX;
    int key = root->data;
    if( key<val){
        if(root->right) return successor(root->right, val);
        else return INT_MAX;
    }
    if(key==val){
        if(root->right) return minBST(root->right);
        return INT_MAX;
    }
    if(root->left) return min(key,successor(root->left,val));
    return key;
}
int kthSmallest(Node* root, int k){
    int x = minBST(root);
    if(k==1){
        return x;
    }
    k--;
    while(k--){
        x = successor(root,x);
    }
    return x;
}
bool IsBST(Node* root, Node* min, Node* max){
    if(!root) return true;
    if( min and root->data < min->data) return false;
    if( max and root->data > max->data) return false;
    bool lval = IsBST(root->left, min , root);
    bool rval = IsBST(root->right, root, max);

    return lval and rval;
}


Node* BSTfromPre(int arr[],int &ind,int key,int min, int max, int n){
    if(ind>= n) return NULL;
    Node* root = NULL;
    if(key>min && key < max){
        root = new Node(key);
        ind++;
        if(ind < n){
            root->left = BSTfromPre(arr, ind,arr[ind], min, key,n);
        }
        if(ind<n){
            root->right = BSTfromPre(arr,ind,arr[ind], key, max, n);
        }
    }
    return root;
}
Node* BSTfromPre(int arr[], int n){
    int o = 0;
    return BSTfromPre(arr, o, arr[0], INT_MIN,INT_MAX, n);
}
/* Make Balanced BST from a sorted Array*/
Node* fromsorted(int a[], int n){
    if(n<1) return NULL;
    if(n==1){
        return new Node(a[0]);
    }
    int mid = (n-1)/2;
    Node* r = new Node(a[mid]);
    r->left = fromsorted(a,mid);
    r->right = fromsorted(a+mid+1, n - mid - 1);
    return r;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void calcPointers(Node* root,Node* &first,Node* &mid,Node* &last,Node* &prev){
    if(!root) return ;
    calcPointers(root->left,first,mid,last,prev);
    
    if(prev && root->data < prev->data){
        if (!root)
        {
            first = prev;
            mid = root;
        }
        else
        {
            last = root;
            mid = root;
        }        
    }
    prev = root;
    calcPointers(root->right,first,mid,last,prev);
}
void restore2(Node* root){
    Node *first = NULL, *mid = NULL, *last = NULL, *prev = NULL;

    calcPointers(root,first,mid,last,prev);
    
    
    // case 1
    if(first && last){
        swap(first->data,last->data);
    }// case 2
    else if(first && mid){
        swap(first->data, mid->data);
    }
}

int rootfinder(int start, int end){
    int i = -1,s = -1;
    for(int j =start;j<=end;j++){
        if(s<f[j]){
            s = f[j];
            i = j;
        }        
    }
    return i;
}
Node* AnscBST(int start, int end){
    if (start<=end){
        return new Node(start);
    }
    int rootind = rootfinder(start,end);
    Node* root  = new Node(rootind);
    root->left  = AnscBST(start,rootind-1);    
    root->right = AnscBST(rootind + 1,end);  
    return root;  
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
    // int b[5] = {10, 2, 1, 13, 11};
    // sort(a,a+10);
    // random_shuffle(a,a+10);
    // for(int i=0;i<10;i++) cout<<a[i]<<" "; cout<<endl;
    Node* root = buildBST(a,10);
    // Node* root = BSTfromPre(b,5);
    // Node* broot = fromsorted(a,10);
    // cout << precessador(root, 8)<<endl;
    // cout << IsBST(root,NULL,NULL) << endl ;
    // cout << successor(root, 8) ;
    // preorder(broot); cout<<endl;
    // inorder(broot);cout<<endl;
    // postorder(broot);cout<<endl;
    // levelOrder(broot);//cout<< "\nMODIFIED:\n\n";
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
    inorder(root);cout<<endl;
    cout<<minBST(root)<<endl;
    cout<<kthSmallest(root,8);
    cout<<"\nIti Sampurna";
    return 0;
}

