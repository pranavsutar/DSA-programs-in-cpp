
#
# Complete the 'getExpressionSums' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING num as parameter.
#

def getExpressionSums(num):
    # Write your code here
    # Return the sum of all possible expressions that can be formed by inserting '+' or nothing between the digits of num
    # Output modulo 10^9 + 7

    return sol(num) % (10**9 + 7)

def sol(num):
    num = int(num)
    if num < 10:
        return num
    else:
        # Recursively find the sum of all possible expressions that can be formed by inserting '+' or nothing between the digits of num

        ret = sol2(num//10) + num%10 + sol(num//10)*num

        return ret
    
def sol2(num):
    s = str(num)
    n = len(s)
    if n == 1:
        return num

    ret = 0
    for i in range(1,n):
        e1 = int(s[:i]); e2 = int(s[i:])
        ret += sol(e1) + sol(e2)

    return ret

n = int(input())
print(getExpressionSums(n))
