import random as rr
def binc(a):
    n = len(a)
    b= n//2; k = 0;
    while b>=1:
        while (k+b<n) and (not a[k+b]):
            k += b
        b = b//2
    return k+1
def numOfRotations(a):
    n = len(a)
    b= n//2; k = 0;
    while b>=1:
        while (k+b<n) and (a[0] < a[k+b]):
            k += b
        b = b//2
    # return k+1
    return n - (k+1) 
def main():
    a1 = [False for _ in range(rr.randint(0,30)) ]
    a2 = [True for _ in range(rr.randint(1,30)) ]
    a = a1+a2
    b = binc(a)
    if len(a1)==b:
        return
    print(len(a1)==b,len(a1),b)
# for __ in range(30):
#     main()

a = [_ for _ in range(20)]
a = a[6:] + a[:6]
print(numOfRotations(a))
