
# Given an integer array nums, 
# return the third distinct maximum number in this array. 
# If the third maximum does not exist, 
# return the maximum number.

# In this problem my approach was to create a dictionary of
# values in nums then based on that if dictionary didnt have 3
# values then return the max else it would append the top 3 in
# a list then return the one in the third position, returning
# the third max

from typing import List

class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        count_dict = {}
        res = list()

        for x in nums:
            if x in count_dict:
                count_dict[x] += 1
            else:
                count_dict[x] = 1
        

        if len(count_dict) < 3:
            distinct_max = max(count_dict)
            return distinct_max
        else:
            for i in range(3):
                distinct_max = max(count_dict)
                res.append(distinct_max)
                del count_dict[distinct_max]
        
        return res[2]