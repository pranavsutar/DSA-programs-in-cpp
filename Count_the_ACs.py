
s1 = input()
s2 = input()

def sub(s1,s2):
    if len(s1) < len(s2):
        s1, s2 = s2, s1
    ans = ''
    if len(s1) == 0:
        ans = '0'
        return ans
    if len(s2) == 0:
        ans = s1
        return ans
    x = int(s1[-1]); y = int(s2[-1])
    if x >= y:
        ans = sub(s1[:-1],s2[:-1]) + str(x-y)
    else:
        ans = sub(s1[:-1],s2[:-1]) + str(x+10-y)
        ans = sub(ans[:-1], '1') + ans[-1]
    return ans

ans = sub(s1,s2)
print(ans)
'''
Testcases

123456789
123456789
0

123456789
123456788
1

987654321
123456789
864197532

'''


    
        