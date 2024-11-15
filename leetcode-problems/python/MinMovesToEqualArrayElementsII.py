
# MEDIUM PROBLEM

# Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
# In one move, you can increment or decrement an element of the array by 1.
# Test cases are designed so that the answer will fit in a 32-bit integer.

# My Solution beats 100% of runtimes and 85.4% of Space complexities

from typing import List

class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        
        nums.sort() # sort list
        total = len(nums)
        middle = total // 2 # find middle element
        res = 0

        if total % 2 == 0: #middle for even amount of elements
            middle = nums[middle-1]
        else: # middle for odd amount of elements
            middle = nums[middle]

        # the middle element is important since its gonna be the closest to all other nums in list
        # as we want to find mininum amount of moves
        # so we want to go thru list and find difference between all elements that arent that middle
        # then return that total of difference as our result

        for x in nums:
            if x != middle:
                res += abs(x - middle) 
        
        return res