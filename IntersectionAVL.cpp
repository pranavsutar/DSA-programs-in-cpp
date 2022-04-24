/**
 * @file IntersectionAVL.cpp
 * @author Pranav Sutar (CS20B029)
 * @brief 
 * @version 0.1
 * @date 2022-04-24
 *  
 * Implemented Using AVL TREES
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
    int y1, hv, se, xs, ys,height;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
    Node(int x, int y, int ori, int type)
    {
        data = x;
        y1 = y;
        hv = ori;
        se = type;
        left = NULL;
        right = NULL;
        height = 1;
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
        height = 1;
    }
};

int getHeight(Node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}
Node *RR(Node *x)
{
    Node *y = x->left;
    Node *yr = y->right;

    y->right = x;
    x->left = yr;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    return y;
}
Node *LR(Node *x)
{
    Node *y = x->right;
    Node *yl = y->left;

    y->left = x;
    x->right = yl;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    return y;
}


    int FindBalance(Node *root)
    {
        if (root == NULL)
            return 0;
        return getHeight(root->right) - getHeight(root->left);
    }
    Node *insert(Node *root, int x, int y, int ori, int type,int xst, int yst )
    {
        if (root == NULL)
        {
            Node *t = new Node(x,y,ori,type,xst,yst);
            return t;
        }

        if (x < root->data)
            root->left = insert(root->left, x,y,ori,type,xst,yst);
        else if (x > root->data)
            root->right = insert(root->right, x,y,ori,type,xst,yst);
        
        else if(y<root->y1) root->left = insert(root->left, x,y,ori,type,xst,yst);
        else if(y>root->y1) root->right = insert(root->right,x,y,ori,type,xst,yst);
    // return root;
        // update the height of current Node (Update height of this ancestor Node)
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int bal = FindBalance(root);

        // LL
        if (bal < -1 && x < root->left->data)
            return RR(root);

        // LR
        if (bal < -1 && x > root->left->data)
        {
            root->left = LR(root->left);
            return RR(root);
        }
        // RL
        if (bal > 1 && x < root->right->data)
        {
            root->right = RR(root->right);
            return LR(root);
        }

        // RR
        if (bal > 1 && x > root->right->data)
            return LR(root);

        return root;
    }
    Node *minNode(Node *root) // to get the inorder successor
    {
        Node *temp = root;

        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }
    bool SearchAVL(Node *root, int x, int y){
            if(!root) return false;
            if(root->data== x and root->y1 == y) return true;
            else if(root->data == x and root->y1 > y) return SearchAVL(root->left,x,y);
            else if(root->data == x and root->y1 < y) return SearchAVL(root->right,x,y);
            else if(root->data > x) return SearchAVL(root->left,x,y);
            else return SearchAVL(root->right,x,y);
        }
    Node *DELETENODE(Node *root, int x,int y)
    {
        if (!SearchAVL(root,x,y)) return root;
        // NORMAL BST DELETE PROCESS
        if (root == NULL)
            return root;

        if (x < root->data)
            root->left = DELETENODE(root->left, x,y);
        else if (x > root->data)
            root->right = DELETENODE(root->right, x,y);
        else if(y<root->y1) root->left = DELETENODE(root->left, x,y);
        else if(y>root->y1) root->right = DELETENODE(root->right,x,y);
        // found data now delete this
        else
        {
            // no child
            if (root->left == NULL && root->right == NULL)
                return NULL;

            // one child
            else if (root->left == NULL)
            {
                Node *t = root->right;
                delete (root);
                return t;
            }
            else if (root->right == NULL)
            {
                Node *t = root->left;
                delete (root);
                return t;
            }
            else
            {

                // both child
                Node *temp = minNode(root->right); // find inorder successor in right subtree
                root->data = temp->data;
                root->y1 = temp->y1;
                root->hv = temp->hv;
                root->height = temp->height;
                root->se = temp->se;
                root->xs= temp->xs;
                root->ys= temp->ys;

                // delete the inorder successor
                root->right = DELETENODE(root->right, temp->data, temp->y1);
            }
        }

        // HEIGHT UPDATION
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int bal = FindBalance(root);

        // 4 cases
        // LL
        if (bal < -1 && FindBalance(root->left) < 0)
            return RR(root);

        // LR
        if (bal < -1 && FindBalance(root->left) >= 0)
        {
            root->left = LR(root->left);
            return RR(root);
        }
        // RL
        if (bal > 1 && FindBalance(root->left) < 0)
        {
            root->right = RR(root->right);
            return LR(root);
        }

        // RR
        if (bal > 1 && FindBalance(root->left) >= 0)
            return LR(root);

        return root;
    }

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
            cout<<root->data<<" "<<root->y1 << " " << root->hv <<" " << root->se << " " << root->xs <<" " << root->ys <<" | ";
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
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
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
    cout << "\nPoints of Intersection are -\n";
    while(!minHeap.empty()){
        a = minHeap.top();
        minHeap.pop();
        hv = a[2]; se = a[3];
        if(hv==0){
            if(se == 0){
                // cout << "---TO BE INSERTED\n";
                // inorder(root); cout<<"post insertion\n";
                
                root = insert(root,a[0],a[1],a[2],a[3],a[4],a[5]);
                // inorder(root);
            }
            else if(se==1){
                // cout << "---TO BE DELETED\n";
                // inorder(root); cout<<"post deletion\n";
                root = DELETENODE(root,a[4],a[5]);
                // inorder(root);
            }
            else cout<<"ERROR se\n";

        }
        else if(hv==1){
            int ydown = a[4],yup= a[5], xp = a[0];
            // cout << "---INTERSEC. TO BE Printed\n";
            // inorder(root);
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
        if( llast < x2 ) llast =  x2;
        if(y1>y2) swap(y1,y2);      
          
        if(x1 == x2){
            minHeap.push({x1,0,1,0,min(y1,y2),max(y1,y2)});
        }                     
        else
            cout << "Not Vertical \nWrong Input\n";        
    }

    last = min(last,llast);
    int first = minHeap.top()[0];
    findIntersection(minHeap);
    cout << "Function Executed\n";
    int ct = 1;
/*    while(!minHeap.empty()){        
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
 * Sample Input 4

1
1

1 1 5 1
5 1 5 5

 * 
 */
