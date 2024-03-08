def bin(a,n,key)->bool:
    k = 0; b = n//2
    while b>=1:
        while (k+b<n) and (a[k+b]<=key) :
            k += b
        b = b//2
    # return k
    return a[k] == key
def binSeaInd(a,n,key)->int:
    start = 0; end = n-1; mid = start + (end - start)//2
    while start <= end:
        mid = start + (end - start)//2
        m = a[mid]
        if m==key:
            return mid
        elif m>key:
            end = mid-1
        else:
            start = mid + 1
    return -1

def firstOcc(a,n,key)->int:
    start = 0; end = n-1; mid = start + (end - start)//2; firstOccInd = -1
    while start <= end:
        mid = start + (end - start)//2
        m = a[mid]
        if m==key:
            firstOccInd = mid
            end = mid - 1
        elif m>key:
            end = mid-1
        else:
            start = mid + 1
    return firstOccInd
def lastOcc(a,n,key)->int:
    start = 0; end = n-1; mid = start + (end - start)//2; lastOccInd = -1 ;
    while start <= end:
        mid = start + (end - start)//2
        m = a[mid]
        if m==key:
            lastOccInd = mid
            start = mid + 1
        elif m>key:
            end = mid-1
        else:
            start = mid + 1
    return lastOccInd

def upperBound(a,start,n,key)->int:
    end = n-1; mid = start + (end - start)//2; upperBoundInd = -1
    while start <= end:
        mid = start + (end - start)//2
        m = a[mid]
        if m>key:
            end = mid-1
        else:
            upperBoundInd = mid
            start = mid + 1
    return upperBoundInd

def lowerBound(a,start,n,key)->int:
    end = n-1; mid = start + (end - start)//2; lowerBoundInd = -1
    while start <= end:
        mid = start + (end - start)//2
        m = a[mid]
        if m>key:
            lowerBoundInd = mid
            end = mid-1
        else:
            start = mid + 1
    return lowerBoundInd

def Count(a,n,key)->int:
    return lastOcc(a,n,key) - firstOcc(a,n,key) + 1

N = 30
a = [3*_+1 for _ in range(N)]
a = [((3*_+1)//9)*4 for _ in range(N)]
# print(a)
# for k in range(4, 4 + 20 + 1):
#     # print(k,'->',bin(a,N,k))
#     # print(k,'->',binSeaInd(a,N,k))
#     # print(k,'->',firstOcc(a,N,k))
#     print(k,'->',lastOcc(a,N,k))
#     # print(k,'->',a[bin(a,N,k)])
key = 40
print( 'key = ', key, a)
upperBoundInd = upperBound(a,0,len(a),key)
lowerBoundInd = lowerBound(a,0,len(a),key)

print('upperBoundInd = ',upperBoundInd, 'a[upperBoundInd] = ',a[upperBoundInd])
print('lowerBoundInd = ',lowerBoundInd, 'a[lowerBoundInd] = ',a[lowerBoundInd])
