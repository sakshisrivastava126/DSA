class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        freq = {}
        for i in range(len(nums)):    
            if nums[i] in freq:
                return True
            freq[nums[i]] = 1
        return False