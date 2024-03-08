#
# Complete the 'maximalPermutation' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY container
#  2. INTEGER_ARRAY firstPositions
#  3. INTEGER_ARRAY secondPositions
#  4. INTEGER_ARRAY slides
#
'''<p>Create an algorithm to generate the lexicographically maximal permutation of a circular list of integers using the operations described below.&nbsp; There will be two index arrays,&nbsp;<em>firstPosition</em>&nbsp;and&nbsp;<em>secondPosition.</em>&nbsp; The circular list of integers to permute is called&nbsp;<em>container</em>.&nbsp; To demonstrate a circular list, for the list <em>[a,b,c]</em>, <em>a</em>&nbsp;follows&nbsp;<em>c</em>&nbsp;and <em>c</em>&nbsp;precedes&nbsp;<em>a</em>. Finally, there will be an integer array, <em>slides.</em></p>

<p>&nbsp;</p>

<p>For each element <em>i</em>&nbsp;of&nbsp;<em>slides</em>, perform the following operations:</p>

<p>&nbsp; &nbsp; 1.&nbsp; &nbsp; Determine the index within&nbsp;<em>container</em>&nbsp;which corresponds to&nbsp;<em>firstPosition[i] - slides[i]</em>&nbsp;</p>

<p>&nbsp; &nbsp; 2.&nbsp; &nbsp; Determine the index within&nbsp;<em>container</em>&nbsp;which corresponds to&nbsp;<em>secondPosition[i] + slides[i]</em></p>

<p>&nbsp;</p>

<p>The values at any of those index pairs may be swapped. A value may be swapped any number of times. For example, if the container is [0, 1, 2] and if two rules allow a swap of element 0 <em>⇆ 1, and 1 ⇆ 2, </em>then the first swap can be used to yield<em> [1, 0, 2], </em>then the second swap can be used to yield<em> [1, 2, 0] </em>and then again using the first swap yields<em> [2, 1, 0]. </em>Once the universe of possible swaps has been generated, determine the maximal permutation.&nbsp;</p>

<p>&nbsp;</p>def maximalPermutation(container, firstPositions, secondPositions, slides):
    # Write your code here
    # Find the lexicographically maximal permutation of a circular list of integers using the operations described below
'''


# without numpy
def argmin(a):
    m = a[0]
    i = 0
    for j in range(1,len(a)):
        if a[j]<m:
            m = a[j]
            i = j
    return i

def argmax(a):
    m = a[0]
    i = 0
    for j in range(1,len(a)):
        if a[j]>m:
            m = a[j]
            i = j
    return i



# Only for numbers between 0 and 1
def frac_bin(number, thd=12):
    res = ""
    number = number - int(number)
    # calculate till termination condition
    while number>0:
        number *= 2
        res += str(int(number))
        number -= int(number)
        thd -= 1
        if thd==0:
            return False
    return res

def sol(num,deno):
    # highest power of 2 common in both
    h = 1
    while num%2==0 and deno%2==0:
        num //= 2
        deno //= 2
        h *= 2
    
    number = num/deno
    res = frac_bin(number)
    if res==False:
        return -1
    l = len(res)
    r = 0
    # print(f'num={num},deno={deno},h={h},res={res},l={l}')
    for i,e in enumerate(res):
        if e=='1':
            r += (2**(i+1)-1)*(2**(l-i-1))
    return r*h
    

# cook your dish here
for _ in range(int(input())):
    num,deno = [int(x) for x in input().split()]

    print(sol(num,deno))


# In Cpp
'''
#include <iostream>
using namespace std;

signed main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long s0,e0;
        cin>>s0>>e0;
        for(int i=1;i<n;i++){
            long long s,e;
            cin>>s>>e;
            if(s>=s0 && e>=e0){
                cout<<-1<<endl;
                break;
            }
            if(i==n-1) cout<<s0<<endl;
        }
    }
    return 0;
}
'''
