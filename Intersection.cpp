
#include <bits/stdc++.h>

#define PB push_back
#define ll left
#define rr right
#define pll(n) push(n->left)
#define lll(n) n->left
#define prr(n) push(n->right)
#define rrr(n) (n->right)

#define vii vector<int>
#define vvi vector<vector<int>>
#define PB push_back
#define repp(n) for (int i = 0; i < n; i++)
#define rrep(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define loop(i, n) for (int i = 0; i < n; i++)

using namespace std;
class Node
{
public:
    int data;// data is x coordinate of vertical line
    int y1, y2;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    Node(int x, int v1, int v2)
    {
        data = x;
        y1 = v1;
        y2 = v2;
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
    Node* insertBST(Node* root, int val, int v1, int v2){
        if(!root) return new Node(val,v1,v2);
        int dt = root->data;
        if(val<dt) root->left = insertBST(lll(root),val,v1,v2);
        else rrr(root) = insertBST(rrr(root),val,v1,v2);

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


void findIntersection(priority_queue < vii, vvi, greater<vii> > minHeap, Node* root, int first, int last){
    int n = minHeap.size();
    repp(n){
        
    }


int main()
{
    int h, v, n, m, i, j, p, l, k, rot, x, y, z, x1, x2, y1, y2;
    cout<<"Enter number of Horizontal Lines\n"; cin >> n;
    cout<<"Enter number of Vertical   Lines\n"; cin >> m;
    cout<<"\nEnter the Horizontal Points\n";
    int last = INT_MIN, llast = INT_MIN;
    // vvi h,v; 
    priority_queue < vii, vvi, greater<vii> > minHeap;
    priority_queue < vii, vvi, greater<vii> > vert;
    repp(n){
        cin >> x1 >> y1 >> x2 >> y2 ;
        if( last < x2 ) last =  x2;
        if(x1>x2) swap(x1,x2);
        if(y1 == y2)
            minHeap.push({x1,x2,y1});
        else
            cout << "Not Horizontal \nWrong Input";        
    }
    cout<<"\nEnter the Vertical   Points\n";
    Node* root = NULL;
    repp(m){
        cin >> x1 >> y1 >> x2 >> y2 ;
        if( llast < x2 ) llast =  x2;
        if(y1>y2) swap(y1,y2);      
          
        if(x1 == x2)   {
            //vert.push({x1,y1,y2});
            root = insertBST(root,x1,y1,y2);
        }                     
        else
            cout << "Not Vertical \nWrong Input";        
    }
    // cout << "BST Formed";
    // if(root) cout <<" NOT NULL\n";
    // else cout << "NULL\n";
    // cout << root->data; cout << '\n';
    // inorder(root); cout << '\n';
    // preorder(root);   
    last = min(last,llast);
    int first = minHeap.top()[0];
   
    while(!minHeap.empty()){
        // for_each( auto a : max_heap.top() ) cout << a << " " ;
        loop(i,3) cout << minHeap.top()[i] << " ";
        cout << '\n' ;

        minHeap.pop();
    }
    return 0;
    
}

/***
 * Sample Input

4
4
2 4 6 4
3 8 9 8
5 1 8 1
0 9 9 9

2 2 2 5
5 1 5 9
1 7 1 9
7 3 7 7
 
 * 
 * 
 */