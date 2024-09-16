// Author : Yavuz Selim Kara
// Question Link : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description

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
   Problem:
       In given linked list, add gcd of sequential nodes in between them
       example: [6, 8] gcd of 6,8 = 2
           new list: [6, 2, 8]


   Solution:

   gcd function: (recursive)
       First we make a gcd function where take two values a and b
       and returns greatst common divisor of a, b
       We use euclidian approach to calculate gcd
       end condition = one of them become zero Other component will be result
           if a == 0 result will be b (equals a+b)

   insertGreatestCommonDivisors function:
       We keep two nodes left and right
       left equals first component of the list
       right equals second component of the list
       we caculate gcd of left and right = val
       create new node(add) with the result of val
       then connect new node(add) between left and right
       add(new node) -> next should be right
       and add(new node)'s before should be left
       so left -> next should be add(new node)
       we added in between left and right

       then we slide our left and right pointers to another ones
       left, add,  right, node,  node
       node, node, left,  right, node   (we slide left to 2 next) (right to 1 next)

       head remains same

       so, return head as result



       example:
            head = [18, 6, 10, 3], left->val = 18, right->val = 6, gcd(18, 6) = val = 6, new node add -> val = 6
                18, 6(add), 6
            head = [18, 6, 6, 10, 3], left->val = 6, right->val = 10 gcd(6, 10) = val = 2 , new node add -> val = 2
                6, 2(add), 10
            head = [18, 6, 6, 2, 10, 3], left->val = 10, right->val = 3 gcd(10, 3) = val = 1 , new node add -> val = 1
                10, 1(add), 3
            head = [18, 6, 6, 2, 10, 1, 3], left->val = 3 right becomes nullptr so it exits from while loop

            result will be head


*/


class Solution
{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *left = head;        // initalization
        ListNode *right = head->next; // initialization

        // if list length equals 1 -> right becomes null so skips while condition ( no edge case )

        while (left != nullptr && right != nullptr)
        { // if left or right is null finish

            int val = gcd(left->val, right->val); // calculate gcd of left node's and right node's values
            ListNode *add = new ListNode(val);    // new node to be added between left and right

            add->next = right; // new node's next will be right ( add, right )
            left->next = add;  // left will point new node ( left, add, right )

            left = left->next->next; // left, add, right(new left), node(new right), ...  (we move to next pair) so left moves 2 node
            right = right->next;     // right moves 2 node
            // added node will not be considered in gcd adding
        }
        return head; // new list's head remains same
    }

    int gcd(int a, int b)
    { // great common divisor function
        if (a == 0 || b == 0)
            return (a + b);   // end condition - if one of them equals zero return non zero component (equals a+b)
        return gcd(b, a % b); // euclidian approach, gcd(bigger, smaller)    (   0 <= (a % b) < b   )
        // subtract smaller one from bigger one as much as you can Then call the function again
    }
};
