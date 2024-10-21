class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        
        for first in range(len(nums)): 
            for second in range(first + 1, len(nums)):
                if nums[first] + nums[second] == target:
                    return [first, second]
        return None