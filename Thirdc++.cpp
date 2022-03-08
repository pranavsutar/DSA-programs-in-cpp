#include <bits/stdc++.h>
#include <cinttypes>
using namespace std;
/* 
class Node
{
    public:
    int key;
    Node* ptr; 
};
 

Node* XOR (Node *a, Node *b)
{
    return reinterpret_cast<Node *>(
      reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
}

void insert(Node **head_ref, int key)
{
    Node *new_node = new Node();
    new_node->key = key;
 
    new_node->ptr = *head_ref;
 
    if (*head_ref != NULL)
    {
        (*head_ref)->ptr = XOR(new_node, (*head_ref)->ptr);
    }

    *head_ref = new_node;
}

bool SearchList (Node *head, int k)
{
    bool ans = false;
    Node *curr = head;
    Node *prev = NULL;
    Node *next;
 
    while (curr != NULL)
    {
        if(curr->key == k){
            return true;
        }
        // cout<<curr->key<<" ";
        next = XOR (prev, curr->ptr);
        prev = curr;
        curr = next;
    }
    return false;
}
bool Binsearch(Node* head, int k){
    if (head == NULL) return false;
    
}


struct Node* delEnd(struct Node** head)
{
    // Base condition
    if (*head == NULL)
    
        printf("List is empty");
    else {
  
        // Stores XOR pointer
        // in current node
        struct Node* curr = *head;
  
        // Stores XOR pointer of
        // in previous Node
        struct Node* prev = NULL;
  
        // Stores XOR pointer of
        // in next node
        struct Node* next;
  
        // Traverse XOR linked list
        while (XOR(curr->ptr, prev) != NULL) {
  
            // Forward traversal
            next = XOR(prev, curr->ptr);
  
            // Update prev
            prev = curr;
  
            // Update curr
            curr = next;
        }
        // If the Linked List contains more than 1 node
        if (prev != NULL)
            prev->ptr = XOR(XOR(prev->ptr, curr), NULL);
  
        // Otherwise
        else
            *head = NULL;
  
        // Delete the last node from memory
        free(curr);
    }
  
    // Returns head of new linked list
    return *head;
}
*/

int main ()
{
    // int n,k,i; cin>>n; int a[n];
    // for(i=n-1; i>=0; i--) cin>>a[i];
    // cin>>k;

    // Node *head = NULL;
    // for(i=0;i<n;i++) insert(&head, a[i]);

    // cout<<SearchList(head,k);
    short hex = 7;
    cout << hex;
 
    return 0;
}
 
