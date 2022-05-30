#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r){
    cout << "MERGE\n" ;
    int c[r-l+1] = {0}, i=l, j = m, k=0;
    while(i<m && j <r+1){
        if(a[i]<=a[j]){
            c[k] = a[i];
            i++;
        }
        else{
            c[k]= a[j];
            j++;
        }
        k++;
    }
    while(i<m){
        c[k] = a[i];
        k++; i++;
    }
    while (j<r+1)
    {
        c[k] = a[j];
        k++; j++;
    }
    for(i=l;i<=r;i++){
        a[i] = c[l-i];
    }    
}

void mergeSort(int a[],int i, int j){
    if(i>=j) return;
    int mid = (i+j)/2 + 1;
    mergeSort(a,i,mid-1);
    mergeSort(a,mid,j);
    merge(a,i,mid,j);
}

void MergeSort(int a[], int n){
    mergeSort(a,0,n-1);
}
bool BiSearch(int a[], int n, int key){
    if(n==1) return a[0] == key;
    int mid = n/2;
    if(a[mid] == key) return true;
    if(key < a[mid]) return BiSearch(a,mid,key);
    return BiSearch(a +mid + 1,n -mid -1,key);
}

int main()
{
    int t, n, m, key, i;
    cout << "WORKING\n";
    cin >> t;

    while (t--)
    {
        cin >> n 
            >> key;
        // >>m;
        int a[n];
        // vector<int> a(n) ,b(m);
        for (i = 0; i < n; i++)
            cin >> a[i];
            mergeSort(a,0,n-1);
        for(i=0;i<n;i++) cout << a[i] <<" "; cout << endl;
        cout<<BiSearch(a,n,key)<<"\n";
    }

    return 0;
}

/**
 *
 *  


 */
