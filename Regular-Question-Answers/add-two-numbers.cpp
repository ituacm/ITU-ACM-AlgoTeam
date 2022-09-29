// Author: Feyza Sarı
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/add-two-numbers/

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) { 
        
        int sum = 0, carry = 0; // sum is sum of digits, if sum is larger than 10 we have to add sum/10 top next digit
        ListNode *head = new ListNode(0); // creating the answer linked listed 
        ListNode *temp = head;
        
        while(list1 && list2)
        {
            sum = list1->val + list2->val + carry; // sum of digits
            carry = sum / 10; // new carry
            sum %= 10; // find the digit
            temp->next = new ListNode(sum); // add the number to the answer
            list1 = list1->next; // skip to the next number
            list2 = list2->next; // skip to the next number
            temp = temp->next; // skip to the next number
        }
        
        while(list1) // if list1 has more digit than list2 countinue to doing the same thing  
        {
            sum = list1->val + carry;
            carry = sum / 10;
            sum %= 10;
            temp->next = new ListNode(sum);
            list1 = list1->next;
            temp = temp->next;
        }
        
        while(list2) // if list2 has more digit than list1 countinue to doing the same thing
        {
            sum = list2->val + carry;
            carry = sum / 10;
            sum %= 10;
            temp->next = new ListNode(sum);
            list2 = list2->next;
            temp = temp->next;
        }
        
        if(carry)//if carry>0 add a new digit (9+1=10)
            temp->next = new ListNode(carry);
        
        return head->next;
    }
};
