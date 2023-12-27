 // Author: Kemal Tahir Bıcılıoğlu
 // Reviewer: 
 // Question Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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

 // Time Complexity: O(n)
 // Space Complexity: O(1)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head; // for current node.
        ListNode* temp2 = head; // for next node to compare with the curr node.

        while(temp != nullptr){ // do not access nullptr's value.
            if(temp->next != nullptr){ // if curr does not have next, no need to proceed the temp2
                temp2 = temp->next; // now we have curr and curr's next
                if(temp2->val == temp->val){ // check if they are equal, if yes
                    temp->next = temp2->next; // 1->1->3 should be 1->3 
                    delete temp2; // first connect 1 and 3 then delete second 1 in order not to lose connection of 3, if we deleted temp2 first, we would have lose the connection of 3. 
                    continue; 
//  continue because if we have a duplicate, there can be a case like 1->1->1->..., if we have proceeded, we would have been on the second node of the nodes: 1->1.... Because of that, we won't be able to delete 1->1 duplicate since we are on the second one. So we should not proceed if we have a duplicate, we need to keep the curr until its next is not a duplicate.
                }
            }
            temp = temp->next;  // proceed the nodes
            temp2 = temp;
        }
        return head;
    }
};