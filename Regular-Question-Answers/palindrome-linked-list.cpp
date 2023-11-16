// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/palindrome-linked-list/

class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        // find the middle of the linked list using slow-fast pointers
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second part of linked list
        ListNode* second_head = slow;
        ListNode* prev = NULL;
        while (second_head) {
            ListNode* temp = second_head->next;
            second_head->next = prev;
            prev = second_head;
            second_head = temp;
        }
        second_head = prev;

        // check whether all numbers are equal or not in linked lists
        ListNode* tra = head;
        ListNode* tra2 = second_head;
        while (tra && tra2) {
            if (tra->val != tra2->val)
                return false;

            tra = tra->next;
            tra2 = tra2->next;
        }

        return true;
    }
};