class Solution(object):
    def numWays(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        if k == 0 or n == 0 or (k == 1 and n > 2): 
            return 0
        if n < 3:
            return k ** n
        dp_same = k
        dp_diff = k * (k - 1)
        for i in range(3, n+1):
            dp_same, dp_diff = dp_diff, (dp_same + dp_diff) * (k - 1)
        return dp_same + dp_diff