// Author: Ali Emre Kaya
// Reviewer: Ali Kemal Coşkun

// Time Complexity = O(n)
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/remove-linked-list-elements/

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

/*
Two consecutive node will hold and when the one in the front will find the 'val',
    previous one will connect next of the front one,
    this operation will continue until the end of the list and
    all 'val' values will be deleted.
*/
class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        // prepare two node, these will follow each other
        ListNode* prev = nullptr;
        // use copy of head node to not lose head
        ListNode* curr = head;

        // controlling entire list
        while (curr != nullptr) {
            if (val == curr->val) {
                // use copy of curr to not lose curr
                ListNode* temp = curr->next;
                if (prev != nullptr) {
                    // omit the node which in the 'curr'
                    prev->next = temp;
                } else {
                    // if the value is in the head of the list,
                    // make the head the next of the head,
                    // for to ignoring this value.
                    head = temp;
                }
                curr = temp;
            } else {
                // if curr's value is not 'val',
                // both pointers should mark the next values
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};