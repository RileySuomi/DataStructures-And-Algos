
# Given an array nums of size n, return the majority element.
# The majority element is the element that appears more than ⌊n / 2⌋ times. 
# You may assume that the majority element always exists in the array.

# Beats 62.67% of submissions based on runtime

# Solution here is pretty readable and simple as I create a dictionary
# that inserts new Int or adds 1 to the key (count of occurence in this case)
# then after done, returns the max (majority element)

from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count_dic = {}

        for element in nums:
            if element in count_dic:
                count_dic[element] += 1
            else:
                count_dic[element] = 1
        
        majority = max(count_dic, key=count_dic.get)

        return majority