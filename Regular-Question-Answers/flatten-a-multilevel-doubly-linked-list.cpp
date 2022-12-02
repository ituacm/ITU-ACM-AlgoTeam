// Author: Denis Davidoglu
// Question Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

/* The function flatten() is slightly modified by adding parameter "parrent", *
 * which allows to proper relinking. By default it is set to NULL, so that    *
 * it is still callable from main() without any changes.                      */

class Solution {
public:
    Node* flatten(Node* head, Node* parrent = NULL) {
        // Condition for exiting the recursion
        if (head == NULL) return NULL;
        
        Node *tail, *current;
    
        /* Loop where flatten() is called recursively on each node.           *
         * Tail is also searched here. By the time it is set every other      *
         * node would be processed by flatten(), ensuring that it is valid.   */
        current = head;
        while (current != NULL) {
            if (current->next == NULL) tail = current;
            flatten(current->child, current);
            current = current->next;
        }

        /* This block relinks the data structure to make it flat. It works    *
         * only on successive calls of flatten(), that is when there is a     *
         * "parrent".                                                         */
        if (parrent != NULL) {
            // If is required to avoid runtime error
            if (parrent->next != NULL) {
                parrent->next->prev = tail;
                tail->next = parrent->next;   
            }
            head->prev = parrent;
            parrent->next = head;
            parrent->child = NULL;
        }
        
        return head;
    }
};
