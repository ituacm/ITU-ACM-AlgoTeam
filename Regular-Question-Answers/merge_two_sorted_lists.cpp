// Novruz Amirov
// Question Link: https://leetcode.com/problems/merge-two-sorted-lists/

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
    Problem Description:
        We have 2 linked lists. Both of
        them are sorted. We need to merge 
        these 2 sorted linked list in a 1
        sorted linked list.
        
    Solution method:
        We will have 2 ListNode s to point
        to both lists. In each iteration we 
        will check which value is smaller, and
        we will add the smaller one to our result
        list and increment the pointer of the list
        that contains smaller element.
        After we have done with one list, we will
        add all elements of the other list to our
        result list.
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* counterFirst = list1; // to store pointer to list1
        ListNode* counterSecond = list2; // to store pointer to list2
        ListNode* head = NULL; // the head of the result list
        ListNode* last = NULL; // the last element of result list
        
        // the values of each list will be compared
        // if there are elements on both lists.
        while (counterFirst && counterSecond){
            
            // to find which value is smaller, so we will use that list.
            if (counterFirst->val < counterSecond->val){
                
                // if it is the first element, it will be head.
                if (head == NULL){
                    head = counterFirst;
                    last = head;
                }
                else{
                    last->next = counterFirst;
                    last = last->next;
                }
                
                counterFirst = counterFirst->next; // to increment pointer.
            }
            
            // if value of counterFirst is not smaller, then take another one.
            else{
                
                // again check if it is the first element or not.
                if(head == NULL){
                    head = counterSecond;
                    last = head;
                }
                else{
                    last->next = counterSecond;
                    last = last->next;
                }
                
                counterSecond = counterSecond->next; // to increment pointer.
            }
        }
        
        // when program comes here, it means we have 
        // checked all elements of list1 or lis2.
        while (counterFirst){ // to check if list1 has elements.
            if (head == NULL){
                head = counterFirst;
                last = head;
            }
            else{
                last->next = counterFirst;
                last = last->next;
            }

            counterFirst = counterFirst->next; // to increment pointer.
        }
        
        while (counterSecond){ // to check if list2 has elements.
            if (head == NULL){
                head = counterSecond;
                last = head;
            }
            else{
                last->next = counterSecond;
                last = last->next;
            }
            
            counterSecond = counterSecond->next; // to increment pointer.
        }
        
        return head; 
        /*
            The time complexity of this program is O(l1 + l2)
            l1 -> the length of the list1
            l2 -> the length of the list2
            
            The space complexity is also same. O(l1 + l2)
        */
    }
};
