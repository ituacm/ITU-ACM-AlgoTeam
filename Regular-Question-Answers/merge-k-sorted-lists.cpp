// Author: Anıl Dervişoğlu
// Question Link: https://leetcode.com/problems/merge-k-sorted-lists/

// If there were to be 2 distinct lists, we could have used two pointers method to sort it easily.
// However, since there are k lists, we need to find the order of smallest elements in all of them in the least possible time complexity.
// This can be done using a multiset or similar data structure in O(n * logn) complexity where n is the total number of elements in all lists.
// The idea is similar to merge sort, where we merge two lists in sorted order.

// Comparing to one other method, we could have looked through first elements of each linked list and select the smallest one at each time,
// This would result in O(n * k) where n is again the total number of elements in all lists and k is the number of all linked lists.
// Again note that the solution complexities depend on the constraints but in this question the complexity of the following code is better.

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // We can use multi set to store the elements in sorted order
        multiset<int> s;

        // First, we insert all elements to the set
        for (auto list : lists) {
            while (list) {
                s.insert(list->val);
                list = list->next;
            }
        }

        // Then, we create a new list
        ListNode* head = new ListNode();
        ListNode* cur = head;

        // Finally, we insert all elements to the new list from our set
        for (auto val : s) {
            cur->next = new ListNode(val);
            cur = cur->next;
        }

        // We return the next of head, since head is a dummy node
        return head->next;
    }
};
