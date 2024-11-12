
# Given an integer x, 
# return true if x is a palindrome, 
# and false otherwise.

# My Solution beats 70.53% of submissions in runtime
# My Solution beats 92.34% of submissions in memory

# Simple solution as I turn the int into a string. 
# Then use a nice python shortcut to reverse a string
# And finally check if they are equal once reversed

class Solution:
    def isPalindrome(self, x: int) -> bool:
        y = str(x)

        n = y[::-1] # way to reverse string in py

        if y == n:
            return True

        return False