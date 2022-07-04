
import sys
import math as mm
from collections import defaultdict

input = sys.stdin.readline

mx = 100001
s1 = [0 for _ in range(mx)]
s1[1] = 1

for j in range(2,mx):
    s1[j]=j
for j in range(4,mx,2):
    s1[j]=2
for i in range(3,mm.ceil(mx**0.5)):
    if s1[i] == i:
        for j in range(i**2,mx,i):
            if s1[j] == j :
                s1[j] = i


def gpf(x):
    r = defaultdict(lambda:0) 
    while(x!= 1):
        r[s1[x]]+=1
        x = x// s1[x]
        return r

def help():
    n,q =  [int(x) for x in input().split()]
    for i in range(q):
        u,v = [int(x) for x in input().split()]
        u = gpf(u)
        v = gpf(v)
        x = set(list(u.keys()) + list(v.keys()))  

        for i in x:
            y = min(u[i],v[i])
            u[i] -= y
            v[i] -= y
        
        a = 0
        for i in x:
            a += i*(u[i] + v[i]) 
        print(a) 



for _ in range(int(input())):
    help()
