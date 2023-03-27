def books(a, k):
    ans = sum(a)
    n = len(a)
    if n==k==1:
        return a[0]
    if k > n:
        return -1
    start = max(a);end = ans; mid = start + (end - start)//2
    while start <= end:
        mid = start + (end - start)//2
        c = 1; st = 0
        for e in a:
            st += e
            if st > mid:
                c +=1
                st=e
        if c <= k:
            ans = min(ans,mid)
            end = mid - 1
        else:
            start = mid + 1
    if ans == sum(a) and k >1:
        return -1
    return ans


# a = [4,12,34,67,96];k = 2
a = [ 97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94, 57, 1, 53, 8, 44, 68, 90, 24 ]; k = 26
# a = [ 79, 83, 70, 40, 23, 50, 71, 29, 18, 46, 99, 30 ]; k = 1 
# a = [int(x) for x in input().split()]
# k = int(input())
print(books(a,k),len(a))