# MEDIUM DIFFICULTY

# Given an integer array nums and an integer k, 
# return the k most frequent elements. 
# You may return the answer in any order.

# my approach here wasn't super runtime efficient as
# traversing dictionaries is slow and a loop that is 0(n)
# But my approach was to create a dictionary of values in nums
# then loop 'k' amount of times retrieving the 'k' amount of 
# maxes, doing so by finding "the" max then deleting it so we can
# retrieve the next and so on.

from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        new_dict = {}
        res = list()

        for element in nums:
            if element in new_dict:
                new_dict[element] += 1
            else:
                new_dict[element] = 1
        
        for i in range(k):
            most_common = max(new_dict, key=new_dict.get)
            res.append(most_common)
            del new_dict[most_common]

        return res