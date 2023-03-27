#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
struct Node* heads[100];
void insert(int data, int n){
    struct Node* temp = new Node();
    temp->data = data;
    temp->next = heads[n];
    heads[n] = temp;
}
void print(int n){
    struct Node* temp = heads[n];
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        heads[i] = NULL;
    }
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        insert(data, 0);
    }
    for(int i=0;i<n;i++){
        print(i);
    }
    return 0;
}
