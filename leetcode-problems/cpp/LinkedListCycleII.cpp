

/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). 
It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


#include <unordered_set>

 struct ListNode {
     int val;   
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
  };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if (head == nullptr){
            return nullptr;
        }

        std::unordered_set<ListNode*> mySet;

        mySet.insert(head);


        ListNode* curr = head;
        while (curr->next) { 
            curr = curr->next; 
            
            if (mySet.count(curr)) {
                return curr;
            }
            mySet.insert(curr);
        };

        return nullptr;

    }
};