#include <bits/stdc++.h>

using namespace std;
/* 
# cook your dish here
import math
# def check(n):
#     return math.floor(math.log2(n)) + 1

# def fact(n):
#     if(n==0):
#         return 1
#     p = 1
#     for i in range(1,n+1):
#         p = p*i
#     return p

# def C(n,r):
#     if(n<r):
#         return 0
#     return fact(n)/(fact(n-r)*fact(r))

def printb(a,b):
    if a<=10000 and b<=10000:
        print(u(a),u(b))
    else:
        print(-1,-1)


def fff(add, sub):
    return (add+sub)/2
def sss(add, sub):
    return (add-sub)/2

def u(p):
    return math.floor(p)
    
def isint(x):
    return x == math.floor(x)

def valid(ff,ss,add,sub,mul,div):
    if (not isint(ff)) or (not isint(ss)):
        return False
    if mul == ff*ss and div == u(ff/ss) and add == ff+ss and sub == ff-ss:
        return True
    else:
        return False

t = int(input())
for  _ in range(t):
    a = input()
    a = list(a.split())
    # print(a)
    for i,nn in enumerate(a):
        a[i] = int(nn)
    # print(a)
    a.sort()
    # b= a[3]
    # s = a[0]
    # p = 10001
    # aa = 10001
    # #b->biggest
    # #s->smallest
    # #p->smallest positive
    # #aa->smallest smallest non negative
    
    # hasneg = False # contains negative number
    # coz = False #contains zero
    # for i,n in enumerate(a):
    #     if n<0:
    #         hasneg =    True
    #     else:
    #         aa= min(aa,n)
    #         if n==0:
    #             coz = True
    #         else:
    #             p = min(p,n)

    
    
    # Case 2
    add = a[2]
    mul = a[3]
    sub = a[0]
    div = a[1]
    ff = fff(add,sub)
    ss = sss(add,sub)
    if valid(ff,ss,add,sub ,mul,div):
        printb(ff,ss)
        continue
    
    # Case 3
    add = a[3]
    mul = a[2]
    sub = a[1]
    div = a[0]
    ff = fff(add,sub)
    ss = sss(add,sub)
    if valid(ff,ss,add,sub ,mul,div):
        printb(ff,ss)
        continue
    
    # Case 4
    add = a[3]
    mul = a[2]
    sub = a[0]
    div = a[1]
    ff = fff(add,sub)
    ss = sss(add,sub)
    if valid(ff,ss,add,sub ,mul,div):
        printb(ff,ss)
        continue
    # print(a)
    print(-1,-1)
    continue

# 9
# 2 1 0 1
# 43 1 1 462
# 102 101 -100 0
# 7 12 1 1 
# 100 99 98 99
# 15 56 -1 0
# 9 18 -3 0
# 12 36 0 1
# 30 200 10 2
    
 
*/
void printb(float a, float b){
    if(a<10001 && b<10001){
        cout<<int(a)<<" "<<int(b)<<endl;
    }
    else{
        cout<<-1<<" "<<-1<<endl;
    }
}

float fff(float add, float sub){
    return (add+sub)/2;
}
float sss(float add, float sub){
    return (add-sub)/2;
}

int u(float p){
    return int(p);
}
int u(int p){
    return p;
}

bool isint(float a){
    return (a == int(a)) ;
}

bool valid(float ff, float ss , int add, int sub, int mul, int div){
    if(!isint(ff) || !isint(ss)) return false;
    return (mul == ff*ss && div ==int(ff/ss) && add == ff+ss && sub == ff-ss);
}

int main ()
{
    int t ;float add,sub, mul, div, ff, ss; cin>>t;
    float a[4];
    while(t--){
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        sort(a,a+4);
        // Case 1
        add = a[2];
        mul = a[3];
        sub = a[1];
        div = a[0];
        ff = fff(add,sub);
        ss = sss(add,sub);
        if (valid(ff,ss,add,sub ,mul,div)){
            printb(ff,ss);
            continue;
        }
        // Case 2
        add = a[2];
        mul = a[3];
        sub = a[0];
        div = a[1];
        ff = fff(add,sub);
        ss = sss(add,sub);
        if (valid(ff,ss,add,sub ,mul,div)){
            printb(ff,ss);
            continue;
        }
        // Case 3
        add = a[3];
        mul = a[2];
        sub = a[1];
        div = a[0];
        ff = fff(add,sub);
        ss = sss(add,sub);
        if (valid(ff,ss,add,sub ,mul,div)){
            printb(ff,ss);
            continue;
        }
        // Case 4
        add = a[3];
        mul = a[2];
        sub = a[0];
        div = a[1];
        ff = fff(add,sub);
        ss = sss(add,sub);
        if (valid(ff,ss,add,sub ,mul,div)){
            printb(ff,ss);
            continue;
        }
        printb(-1,-1);
        continue;
            
    }
    
    return 0;
}
 
