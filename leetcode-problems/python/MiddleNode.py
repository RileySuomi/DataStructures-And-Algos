
# This problem uses a ** linked list **
# Need to find middle node through linked list
# There is the basic approach of iterating all the way with a count, then going back to iterate for middle
# But this is an approach with a fast and slow pointer, where fast goes every 2 while slow is 1,
# That way dont need to loop twice

# BEATS 100% OF RUNTIMES.
# AS WELL AS IN THE TOP 2.4% OF SUBMISSIONS.


class Solution:
    def middleNode(self, head):
        fast = slow = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        return slow