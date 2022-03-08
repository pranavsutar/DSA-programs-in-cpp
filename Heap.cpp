#include <bits/stdc++.h>
using namespace std;
#define vii vector<int>

int i;
/*
priority_queue <int, vii > max_heap;
priority_queue <int, vii, greater<int> > min_heap;

void insert(int x){
    if (min_heap.size() == max_heap.size()){
    
        //Base Case:
        if(! max_heap.size() ){
            max_heap.push(x);
            return;
        }
        if(x < max_heap.top()) max_heap.push(x);
        else min_heap.push(x);
    }
    else if (min_heap.size() < max_heap.size()) {
        if(x >= max_heap.size()) min_heap.push(x);
        else {
            min_heap.push(max_heap.top());
            
            max_heap.pop();
            max_heap.push(x);
        }
    }
    else { 
        if(x >= min_heap.size()) max_heap.push(x);
        else {
            max_heap.push(min_heap.top());
            
            min_heap.pop();
            min_heap.push(x);
        }
    }
    
}

float findMedian()
{
    if(min_heap.size() == max_heap.size()) return (float)(max_heap.top() + min_heap.top())/2 ;
    if(min_heap.size() > max_heap.size()) return min_heap.top();
    return max_heap.top();
}

void heapify(vector<int> &arr, int n, int i){//heapify kis aaray me karn ahai uska size , kahan se karna HAI 
    int maxIdx = i;                 //maxidx ko intialize kiya i se ,hence start point se 
    int l = 2*i + 1;                //left element of a parent node ,exists at 2i+1 th index
    int r = 2*i + 2;                //right exists at 2i+2 nd node 

    if(l<n && arr[l] > arr[maxIdx]){//ahar left child , upar wale se bada hai toh update kar denge 
        maxIdx = l;
    }
    if(r<n && arr[r] > arr[maxIdx]){//same goes for right too 
        maxIdx = r;
    }
    if(maxIdx != i){                //upar wali iterattions khatam hone ke baad agar maxidx i ke baharbar nahi hai ,toh swap karenge 
        swap(arr[i], arr[maxIdx]);

        heapify(arr, n, maxIdx);    //phir naye mile tree pe vapis heapify laga denge
    }

     
}



void heapSort(vector<int> &arr){
    int n = arr.size();
    
    for(int i=n/2-1; i>=0; i--){//i=n/2-1 , 1st node ke element ka index de dega 
        heapify(arr, n, i);//waha pe heapify call kar dunga last element n se le kar 1st i tak ke liye , hence 1st node se
    }//aur n/2-1 -- hai toh uske further neeche  

    for(int i=n-1; i>0; i--){// sare vec ke indexes me se 
        swap(arr[0], arr[i]);//swap kar do arr[0] and last wale 

        heapify(arr, i, 0);//bache hue pe heapify call kar do
    }
}
*/
class Node{
    public:
    int key;
    int m;
    Node** next;

    void decide(int mm){ // To decide the number of Children
        m = mm;
        next = new Node* [m];
        for(i=0;i<m; i++) next[i] = NULL ;
        
    }
    
    Node(int val){
        key = val;
        for(i=0;i<m; i++) next[i] = NULL ;
        
    }
    Node( int val, int mm){
        decide(mm);
        key = val;
        for(i=0;i<m; i++) next[i] = NULL ;
    }
};

Node* hinsert(Node* head, int v){
    int size = head->m;
    Node* h = new Node(v,size);
    if(!head){
        return h;
    }
    for(i=0; i<size; i++){
         if(head->right)
    }
}

int main(){
    /* 
    // int n;
    // while(true){
    //     cin>>n;
    //     insert(n);
    //     cout << findMedian();
    // }
    
    // vector<int>arr(n);
    // 

    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }
    
    // heapSort(arr);

    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    //  }
*/
    int n,k;
    cin>>k>>n;
    Node *head = new Node(k,n);
    cout<< head->key ;
    // vector<int> arr(n);


    return 0;
}