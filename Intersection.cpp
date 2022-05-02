/**
 * @file Intersection.cpp
 * @author Pranav Sutar (CS20B029)
 * @brief 
 * @version 0.1
 * @date 2022-04-24
 *  
 * 
 */


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
    int y1, hv, se, xs, ys;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    Node(int x, int y, int ori, int type)
    {
        data = x;
        y1 = y;
        hv = ori;
        se = type;
        left = NULL;
        right = NULL;
    }

    Node(int x, int y, int ori, int type, int xst, int yst)
    {
        data = x;
        y1 = y;
        hv = ori;
        se = type;
        xs = xst;
        ys = yst;
        left = NULL;
        right = NULL;
    }
};

    Node* insertBST(Node* root, int val){
        if(!root) return new Node(val);
        int dt = root->data;
        if(val<dt) root->left = insertBST(lll(root),val);
        else rrr(root) = insertBST(rrr(root),val);

        return root;
    }
    Node* insertBST(Node* root, int x, int y, int ori, int type){
        // cout<<"Insert 4 tuple\n";
        
        if(!root) return new Node(x,y,ori,type);
        int dt = root->data;
        if(x<dt) root->left = insertBST(lll(root),x,y,ori,type);
        else rrr(root) = insertBST(rrr(root),x,y,ori,type);

        return root;
    }
    Node* insertBST(Node* root, int x, int y, int ori, int type, int xst, int yst){
        // cout<<"Insert 6 tuple\n";
        if(!root) return new Node(x,y,ori,type,xst,yst);
        int dt = root->data;
        if(x<dt) root->left = insertBST(lll(root),x,y,ori,type,xst,yst);
        else rrr(root) = insertBST(rrr(root),x,y,ori,type,xst,yst);

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
    bool SearchBST(Node *root, int x, int y){
        if(!root) return false;
        if(root->data== x and root->y1 == y) return true;
        else if(root->data == x and root->y1 > y) return SearchBST(root->left,x,y);
        else if(root->data == x and root->y1 < y) return SearchBST(root->right,x,y);
        else if(root->data > x) return SearchBST(root->left,x,y);
        else return SearchBST(root->right,x,y);
    }
    Node* SearchBSTpt(Node *root, int x, int y){
        if(!root) return NULL;
        if(root->data== x and root->y1 == y) return root;
        else if(root->data == x and root->y1 > y) return SearchBSTpt(root->left,x,y);
        else if(root->data == x and root->y1 < y) return SearchBSTpt(root->right,x,y);
        else if(root->data > x) return SearchBSTpt(root->left,x,y);
        else return SearchBSTpt(root->right,x,y);
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
    Node* BSTdelete(Node* root, int x, int y){
        // cout << "BST Delete pair \n" ;
        if (!SearchBST(root,x,y)) return root;
        if(x<root->data) root->left = BSTdelete(root->left, x,y);
        else if(x>root->data) root->right = BSTdelete(root->right,x,y);
        else if(y<root->y1) root->left = BSTdelete(root->left, x,y);
        else if(y>root->y1) root->right = BSTdelete(root->right,x,y);
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
            root->y1 = temp->y1;
            root->right = BSTdelete(rrr(root),temp->data,temp->y1);
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
    void printIntersection(Node* root, int l, int u, int xp){
        if(root){
            int yy = root->y1;
            if(l<=yy && yy <=u ){
                cout <<'(' << xp<< ',' << yy <<")\n";
            }
            printIntersection(lll(root),l,u,xp);
            printIntersection(rrr(root),l,u,xp);
        }
    }

void findIntersection(priority_queue < vii, vvi, greater<vii> > minHeap){
    int n = minHeap.size(),hv,se;
    vii a;
    Node* root = NULL;
    cout << "Points Of Intersection are -\n";
    while(!minHeap.empty()){
        a = minHeap.top();
        minHeap.pop();
        hv = a[2]; se = a[3];
        if(hv==0){
            if(se == 0){
                // cout << "---TO BE INSERTED\n";
                
                root = insertBST(root,a[0],a[1],a[2],a[3],a[4],a[5]);
            }
            else if(se==1){
                // cout << "---TO BE DELETED\n";
                
                root = BSTdelete(root,a[4],a[5]);
            }
            else cout<<"ERROR se\n";

        }
        else if(hv==1){
            int ydown = a[4],yup= a[5], xp = a[0];
            // cout << "---INTERSEC. TO BE Printed\n";
            printIntersection(root,ydown,yup,xp);
        }
        else cout << "ERROR hv\n";
    }
    cout << "Points Printed\n";
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
/*        if(x1>x2){
            swap(x1,x2);
            swap(y1,y2);
        } 
*/
        if(y1 == y2){
            minHeap.push({x1,y1,0,0,x2,y2});
            minHeap.push({x2,y2,0,1,x1,y1});
        }
            
        else
            cout << "Not Horizontal \nWrong Input";        
    }
    cout<<"Enter the Vertical   Points\n";
    Node* root = NULL;
    repp(m){
        cin >> x1 >> y1 >> x2 >> y2 ;
        ////if( llast < x2 ) llast =  x2;
        ////if(y1>y2) swap(y1,y2);      
          
        if(x1 == x2){
            minHeap.push({x1,0,1,0,min(y1,y2),max(y1,y2)});
        }                     
        else
            cout << "Not Vertical \nWrong Input\n";        
    }
    // cout << "MinHeap Formed";
    // if(root) cout <<" NOT NULL\n";
    // else cout << "NULL\n";
    // cout << root->data; cout << '\n';
    // inorder(root); cout << '\n';
    // preorder(root);   
    last = min(last,llast);
    int first = minHeap.top()[0];
    findIntersection(minHeap);
    cout << "Function Executed\n";
    /*int ct = 1;
    while(!minHeap.empty()){
        // for_each( auto a : max_heap.top() ) cout << a << " " 
        cout << ct << ") ";
        loop(i,6) cout << minHeap.top()[i] << " ";
        cout << '\n' ;
        minHeap.pop();
        ct++;
    }
    */
    return 0;
    
}

/***
 * Sample Input 0

1
1
1 2 3 2

3 2 3 3
 
 * 
 */

/***
 * Sample Input 1

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
 */

/***
 * Sample Input 2
3
2

3 6 5 6
2 4 5 4 
1 3 2 3

4 3 4 7
7 2 7 6
 * 
 */
/***
 * Sample Input 3

6
3

3 6 5 6
2 4 5 4 
1 3 2 3
5 5 9 5
6 7 10 7
7 1 11 1

4 3 4 7
7 2 7 6
10 1 10 9

 * 
 */