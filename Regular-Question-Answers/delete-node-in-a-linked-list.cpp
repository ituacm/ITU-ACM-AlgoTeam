// Author: İrem Taze
// Question Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
// Time Complexity: O(1) constant time, does not depend on the size of the linked list
/**
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    void deleteNode(ListNode* node) {
        // Check if the node and the next node are not null pointer
        if (node && node->next) {
            // Copy the value from the next node to the current node
            ListNode* temp = node->next;
            node->val = temp->val;

            // Update the next pointer to skip the next node
            node->next = temp->next;

            // Delete the next node to free memory
            delete temp;
        }
    }
};
