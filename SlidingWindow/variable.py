def use(f,e):
    if e in f:
        f[e] += 1
    else:
        f[e] = 1
def throw(f,e):
    if e in f:
        f[e] -= 1
        if f[e]==0:
            f.pop(e)

# Given a String, find the length of longest substring with non-repeating characters
def lengthOfLongestSubstring1( s: str) -> int:
    ans = 0; curr = ''
    for c in s:
        ans = max(ans,len(curr))
        if c in curr:
            i = curr.index(c)                
            curr = curr[i+1:]            
        curr += c
    ans = max(ans,len(curr))
    return ans

def lengthOfLongestSubstring2(a: str) -> int:
    ans = 0; n = len(a)
    i = 0; j = 0;
    f = dict()
    # j +=1   
    while j<n:            
        use(f,a[j])                     
        while (i<n) and (a[j] in f) and (f[a[j]]>1):
            throw(f,a[i])
            i += 1
        ans = max(ans, j-i+1)
        # j +=1
    ans = max(ans, n-i)
    return ans

# Given an Array, find the length of smallest sub-array with sum >= t
def minSubArrayLen1( t, a):
    n = len(a)
    # Base Cases
    if t>sum(a):
        return 0
    if t==sum(a):
        return n
    i = 0; j =0; ans = n; cs = 0;
    
    while j <n and i<=j:
        cs += a[j];j +=1
        if cs > t:
            while cs >=t:
                cs -= a[i]
                i+= 1
            i-=1
            cs += a[i]
        if cs >= t:
            ans = min(ans, j-i) 
        # while sc<t:
        #     cs += a[j];j+=1  --> Ye nahi karnaa hain
        # print(i,j,j-i,cs,ans)  
    return ans
def minSubArrayLen2( t, a):
    n = len(a)
    if t>sum(a): # Corner Case
        return 0
    i = 0; ans = n; cs = 0;
    for j in range(n):
        cs += a[j]
        while cs >=t:
            ans = min(ans, j-i+1) 
            cs -= a[i]
            i+= 1 
    return ans
   

for _ in range(int(input())):
    s = input()
    print(lengthOfLongestSubstring1(s))
    print(lengthOfLongestSubstring2(s))

'''
7
alpha
om namah shivaay
pranavManoharSutar
SHUBHANKAR
Udbhava sthiti sanhaara kaarinim klesh-haariṇim| Sarvam shreyaskarim sitaam natooham RamVallabhaam||
Udbhavasthitisanhaarakaarinimklesh-haariṇim|SarvamshreyaskarimsitaamnatoohamRamVallabhaam||
pranav
'''