'''You are given two strings A and B, both of length N and containing only the characters a, b, and c.

In one move, you can modify string 
A as follows:

Choose three indices 
i,j,k where 1≤i<j<k≤N) such that 
A_i = a, A_j = b, and A_k = c.
That is, choose some subsequence of 
A that is abc.
Then, swap the values of A_i and A_k
That is, turn the subsequence abc into cba.
For example, if A = cacbacb, in one move it can be converted into cccbaab by operating on the underlined subsequence abc.

You can perform this move as many times as you like (possibly, zero).
Is it possible to make A equal to B?'''

def sol(s,t):
    if s==t:
        return True
    a2c = []; c2a = []; bi  = []
    
    for cs,ct in zip(s,t):
        if (cs == 'b') ^ (ct == 'b'):
            return False
    
    ns = ''
    nt = ''
    for cs,ct in zip(s,t):
        if cs == ct == 'a' or cs == ct == 'c':
            continue
        else:
            ns += cs 
            nt += ct
    s = ns; t = nt 
    n = len(s)
            

    for i in range(n):
        if s[i] == 'a' and t[i] == 'c' :
            a2c.append(i)
        elif s[i] == 'c' and t[i] == 'a':
            c2a.append(i)
        elif s[i] == 'b' and t[i] == 'b':
            bi.append(i)

    if len(a2c) != len(c2a):
        return False
    
    # Check if for highest a2c and lowest c2a, a2c < c2a there is a b in between, then reurn true
    for i in bi:
        if a2c[-1]  < i < c2a[0]:
            return True
    return False
            
for _ in range(int(input())):
    n = int(input())
    s = input()
    t = input()
        
    if sol(s,t):
        print('Yes')
    else:
        print('No')
