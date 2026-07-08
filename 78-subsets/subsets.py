class Solution(object):
    def solve(self, nums, i, temp):
        if i == len(nums):
            self.ans.append(temp[:])
            return
        
        temp.append(nums[i])
        self.solve(nums, i+1, temp)
        temp.pop()

        self.solve(nums, i+1, temp)
        

    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.ans = []
        temp = []
        self.solve(nums, 0, temp)
        return self.ans