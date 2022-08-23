// Author: Fatih Baskın
// Reviewer:
// Question Link: https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/

/**
 *  These type of questions can be solved using heap (priority queue).
 *
 *  First, pick the biggest two.
 *  Then decrement both by one and store them back.
 *  Continue until biggest element is 0.
 *
 *  Note that some elements can be negative at the end but it does not matter.
 *  Because we are trying to diminish all containers.
 *  If two containers are diminished to zero but a container still has some elements in it
 *  we can continue to decrement two containers because we are decementing single containers by one.
 *
 *  Explaination above reminds heap data structure.
 *  Heap data structure keeps data in ordered manner, when you modify the heap, ie. adding an element,
 *  order maintains itself.
 *
 *  You can either push/pop elements or access to top element.
 *
 *  Time complexity: O(n * log3), n refers to summation of all sizes.
 */
class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        // Adding all elements to heap
        priority_queue<int> heap;
        for (int x : amount)
        {
            heap.push(x);
        }
        // While top element is not 0 do the operation told above and increment the counter.
        int counter = 0;
        while (heap.top() != 0)
        {
            // Pick most two containers
            int a = heap.top();
            heap.pop();
            int b = heap.top();
            heap.pop();
            // Decrement top two containers
            a -= 1;
            b -= 1;
            // Push them back to heap
            heap.push(a);
            heap.push(b);
            // Increment counter
            counter += 1;
        }
        return counter;
    }
};
