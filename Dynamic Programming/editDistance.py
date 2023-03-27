import enchant

dp = [[-1 for __ in range(100)] for _ in range(100)]

def edit(a,b,n,m):
    if a==b:
        dp[n][m] = 0
        return 0
    if n<=0 or m<=0 :
        dp[n][m] = max(n,m)
        return max(n,m)
    # if a[n-1] == b[m-1]:
    #     return edit(a,b,n-1,m-1)
    # else:
    #     return min(1+edit(a,b,n-1,m),1+edit(a,b,n,m-1))
    if dp[n][m]==-1:
        dp[n][m] = min(1+edit(a,b,n-1,m),1+edit(a,b,n,m-1),edit(a,b,n-1,m-1) + int(a[n-1]!=b[m-1]))
    return dp[n][m]

for _ in range(int(input())):
    # global dp
    dp = [[-1 for wuwy in range(100)] for _ in range(100)]
    s = input()
    t = input()
    n = len(s);m = len(t)
    k= enchant.utils.levenshtein(s, t)
    print()    
    print(k==edit(s,t,n,m),k)


'''
5
dhvfjvdhvmdshc
rertyuiyyhtgrfg
gsfdvgddvgdvgdvgh
sfgsfdgsgsddgsdd
dewjbedsbfjfdsb
esbjffdbfhdsbf
djfsbgjvdmbjvdj
dfsjkbkfjgjdmdjf
wrerwretwrerwretw
werwttetyrywetetetw

'''

'''
5
wtwetr
euwgge
juewgd
jsddhv
etetete
tetette
erereeer
rrererer
wewetyty
ereryrry
'''
