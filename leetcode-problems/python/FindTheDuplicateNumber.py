
# Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
# There is only one repeated number in nums, return this repeated number.

# my solution probably isnt what they wanted but I instantly thought about using a dictionary for ease
# my solution runtime beats 84.65% of solutions

from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        new_dict = {}

        for element in nums:
            if element in new_dict:
                new_dict[element] += 1
                return element
            else:
                new_dict[element] = 1
        
        