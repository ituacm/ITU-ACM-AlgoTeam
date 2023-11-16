// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/reverse-linked-list-ii/

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // the three sublist: prev, middle, next
        // only middle sublist will be reversed
        // head and tail values of sublists are necessary to reverse
        // try to find these values

        // to traverse linked list
        ListNode* traverse = head;

        // tail of first sublist, which is non-reversed sublist
        ListNode* prevSubListTail = NULL;

        // find the correct value for prevSubListTail and traverse
        for (int i = 1; i < left; i++) {
            prevSubListTail = traverse;
            traverse = traverse->next;
        }

        // store the head of sublist
        ListNode* subLinkedListHead = traverse;

        // find the correct value for tail of sublist
        for (int i = left; i < right; i++) {
            traverse = traverse->next;
        }

        // store the head of next non-reversed sublist
        ListNode* nextSubListHead = traverse->next;

        // assign tail of sublist to NULL for reversing correctly
        traverse->next = NULL;

        // it will return head and tail of sublist
        pair<ListNode*, ListNode*> subListHeadAndTail = reverseSubLinkedList(subLinkedListHead);

        // join the three sublist

        // if left == 1, then the pointer will be NULL, it will cause an error
        // update the next value of tail of first sublist
        if (left != 1)
            prevSubListTail->next = subListHeadAndTail.first;

        // update the next value of tail of reversed sublist
        subListHeadAndTail.second->next = nextSubListHead;

        // if left == 1, then the head should be changed
        // otherwise return parameter head
        if (left != 1)
            return head;
        else
            return subListHeadAndTail.first;
    }

    // this function reverses a linked list with O(1) space complexity
    // return values are { head, tail } values in order
    pair<ListNode*, ListNode*> reverseSubLinkedList(ListNode* head) {
        ListNode *prev = NULL, *curr = head;

        // while a node exists
        while (curr) {
            // store the next pointer
            ListNode* temp = curr->next;

            // reverse the next pointer of the current pointer
            curr->next = prev;

            // update values for next iteration
            prev = curr;
            curr = temp;
        }

        // return head and tail values of subLinkedList
        return {prev, head};
    }
};