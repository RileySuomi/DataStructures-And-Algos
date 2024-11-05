
# Beats 51.63% in runtime

# Given an integer array nums, 
# return true if any value appears at least twice in the array, 
# and return false if every element is distinct.

# My solution was simple where I used a created a dictionary 
# that insert an int from nums if never seen before, but if seen
# return true, else would return false after iterating thru nums

from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        count_dic = {}

        for element in nums:
            if element in count_dic:
                return True
            else:
                count_dic[element] = 1
        
        return False