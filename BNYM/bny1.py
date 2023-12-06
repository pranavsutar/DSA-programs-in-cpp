
# def countAnalogousArrays(cd, lowerBound, upperBound):
#     # Write your code here

#     # consecutiveDifference is a list of integers

#     x = 0
#     mx = mn = cd[0]
#     for e in cd:
#         x += e
#         mx = max(mx, x)
#         mn = min(mn, x)

#     if mx - mn >= upperBound - lowerBound:
#         return 0
#     else:
#         return upperBound - lowerBound - (mx - mn)+1 

'''Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


'''
class Solution:
	# @param A : string
	# @param B : string
	# @return an integer
	def minDistance(self, a,b):
        
		n = len(a)
		m = len(b)
		dp = [[0 for i in range(m+1)] for j in range(n+1)]
		for i in range(n+1):
			for j in range(m+1):
				if i == 0:
					dp[i][j] = j
				elif j == 0:
					dp[i][j] = i
				elif a[i-1] == b[j-1]:
					dp[i][j] = dp[i-1][j-1]
				else:
					dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
		return dp[n][m]
     
def minDist_rec(a,b):
        if len(a) == 0:
            return len(b)
        if len(b) == 0:
            return len(a)
        if a[0] == b[0]:
            return minDist_rec(a[1:],b[1:])
        else:
            c1 = 1 + minDist_rec(a[1:],b)
            c2 = 1 + minDist_rec(a,b[1:])
            c3 = 1 + minDist_rec(a[1:],b[1:])
            return min(c1,c2,c3)
        
print(minDist_rec("sunday","saturday"))