class Solution(object):
    def solve(self,n):
        if n == 0:
            return 0
        if n == 1:
            return 1
        return self.solve(n-1)+ self.solve(n-2)
    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = self.solve(n)
        return ans
        