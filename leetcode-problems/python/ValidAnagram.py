# Beats 50.15% of answers in runtime
# Beats 95.70% of answers in memory

# Given two strings s and t, return true if t is an 
# anagram of s, and false otherwise.

# My approach was rather simple and to make two dictionaries 
# of each given string then have first break case if they werent 
# same length bcuz then cant be an anagram. But then other check case
# was to see if the dictionaries were equal, if they were
# that means they are identical, so anagrams is true : else false

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict1 = {}
        dict2 = {}

        if len(s) != len(t):
            return False

        for letter in s:
            if letter in dict1:
                dict1[letter] += 1
            else:
                dict1[letter] = 1

        for letter in t:
            if letter in dict2:
                dict2[letter] += 1
            else:
                dict2[letter] = 1

        if dict1 != dict2:
            return False
        else:
            return True
