#include <bits/stdc++.h> 
using namespace std; 
 
map<int, int> mp; 
int r, res, j, n; 
 
int helper(int *a) 
{ 
    mp.clear(); 
    r = n - 1, res = n, j = 0; 
    for (int i = 0; i < n; ++i) 
    { 
        r = n - i - 1; 
        int temp; 
        j = max(mp.find(a[i]) != mp.end() ? temp = mp[a[i]] : temp = 0, j); 
        mp[a[i]] = 1 + i; 
        res = min(res, min(j, r) + j + r); 
    } 
    return res; 
} 
 
int main() 
{ 
    int t; 
    cin >> t; 
    while (t--) 
    { 
        cin >> n; 
        int a[n]; 
        for (int i = 0; i < n; ++i) 
        { 
            cin >> a[i]; 
        } 
        cout << helper(a) << "\n"; 
    } 
    return 0; 
}