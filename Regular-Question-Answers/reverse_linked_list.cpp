// Author: Hacer Akıncı
// Question Link: https://leetcode.com/problems/reverse-linked-list/description/

/*
    To reverse a linked list, we can start from head and keep going until to the end, and reverse the direction of nodes.
    For this, we need to keep three important nodes; Prev, Curr, Next. For example, we have a linked list like the following.

    1 -> 2 -> 3 -> 4 -> 5 -> NULL
    
    In first step, current node is 1, next node of current node is 2 and previous node is NULL
    because 1 is head and there is no previous node of head.

    Every step, we change the next node of current node to prev node. So, we reverse the direction, and we get;

    NULL <- 1  2 -> 3 -> 4 -> 5 -> NULL 

    If we don't keep the next node of current node (in this step, 2) we cannot get the next node after the reverse operation
    because we lose the connection between current and next node (1 and 2).  

    Now for the next step, we should update variables.

    Prev = Curr (NULL to 1)
    Curr = Next (1 to 2)
    Next = Next of next (2 to 3)

    We keep going until the end of the linked list.
*/

class Solution {
public:
    ListNode* reverse(ListNode* prev, ListNode* curr, ListNode* next){
        // if next node is NULL, that means curr is equal to tail
        if (next == NULL) {
            curr->next = prev;

            // tail is the head of the reversed linked list
            return curr;
        }

        curr->next = prev;

        // call reverse function for updated variables
        return reverse(curr, next, next->next);
    }
    
    ListNode* reverseList(ListNode* head) {
        // if the linked list is empty, then there is no node to reverse
        if (head == NULL) {
            return NULL;
        }

        // for the head, previous node is NULL
        ListNode* prev = NULL;

        // this function reverses all nodes starting from head to tail  
        return reverse(prev, head, head->next);
    }
};