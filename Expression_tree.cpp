#include <bits/stdc++.h>
using namespace std;

class node {
public:
    string data;
    node* left;
    node* right;

    node(string s)
    {
        data = s;
        left = NULL;
        right = NULL;
    }
};
 int precedence(char x)
{
    cout<<"Precedence\n";
    switch(x)
    {
        case '/' : return 4;
        case '*' : return 3;
        case '+' : return 2;
        case '-' : return 2;
    }
    return 100;
}
void inorder(node* root){
//     cout << "\ninorder: " ;
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
bool isOperator(char x){
    return (x == '+' || x==  '/' || x== '-' || x== '*' );
}

int calculate(node *root){
    cout<<"Calculate\n";
    if(!root) return 0;
    
    if(root->left == NULL && root->right == NULL ){
        return stoi(root->data) ;
    }
    // if(!isOperator(root->data[0]) ){
    //     return stoi(root->data) ;
    // }

    string s = root->data;
    if(s=="/") return calculate(root->left)/calculate(root->right);
    if(s=="+") return calculate(root->left)+calculate(root->right);
    if(s=="-") return calculate(root->left)-calculate(root->right);
    if(s=="*") return calculate(root->left)*calculate(root->right);
    
    return -1;
}

string getString(char x)
{
    string s(1, x); 
    return s;  
}

int chooseLeast(string s){
    cout<<"chooseLeast";
    int i, l = s.length();
    char c=s[0];
    int p = precedence(s[0]), ind =-1;
    for(i=0; i<l; i++) if(isOperator(s[i])) {
        if(precedence(s[i]) <= p){
            ind = i;
            p = precedence(s[i]);
        }
    }
    if(ind == -1) cout<< "Wrong Action" ;
    return ind;
}

node* BuildExpTree(string s){
    cout<<"BuildTree\n";

    bool b = true;
    int i ;
    for(i=0;i<s.length();i++){
	    	if(isOperator(s[i])){
			b = false; break;
		}
    } 
    if(b){
        return new node(s);        
    }

    int ic = chooseLeast(s);
    string c = getString(s[ic]) ;
    node* root = new node(c);
    root->left = BuildExpTree(s.substr(0,ic));
    root->right = BuildExpTree(s.substr(ic+1));
    return root;
}

int main()
{
    string s ; cin>>s;
    node* root = BuildExpTree(s);

    inorder(root);
    cout << calculate( root);
    cout << "\nEND";
    return 0;
}
 