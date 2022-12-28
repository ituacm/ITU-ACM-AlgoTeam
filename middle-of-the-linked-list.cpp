// Question: https://leetcode.com/problems/middle-of-the-linked-list/description/
// Author: Murat Biberoğlu

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // the idea is holding two pointer to nodes which are slow and fast
    // slow moves 1 node each step and fast moves 2 node at each step until fast is not null
    // we will move slow first and then move fast because 
    // we want return the second middle node if there are two middle nodes 
    ListNode* middleNode(ListNode* head) {
        // if list is empty return null
        if(!head) return nullptr;

        // if list consists of one node return head
        else if(!head->next) return head;

        // initialize pointers
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast) {
            slow = slow->next;
            fast = fast->next;

            // prevent segmentation fault
            if(fast) fast = fast->next;
        }
        return slow;
    }
};
