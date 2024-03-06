// Author: Kemal Tahir Bıcılıoğlu
// Question Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// Reviewer: 

// time complexity: O(n)
// space complexity: O(n)

/*  
    We keep two stacks. h stack is for the heights and p stacks is for the indeces and they are synchronous to each other. 
    For each height from h stack, say x, its corresponding index from p stack, say j,
    represents that we can create a rectangle with height of x starting from the index j up to current index i.
    So the current area with height of x can be found as x * (i - j).
    To implement it we should observe that, a trangle with height x from index j up to current index i
    can be created if all the next heights from j to i are greater than or equal to x. 
    Because of that observation, we are going to keep the h stack as monotonic increasing stack.
    Lets see how the stack elements will be updated step by step.

    heights = [2,1,5,6,2,3]
------------------------------------------------------------------------------------------------------------
    i = 0.
    
    h = [2]
    p = [0]
------------------------------------------------------------------------------------------------------------
    i = 1. 
    
    since 1 < 2, it will ruin the monotonic structure so 
    we need to calculate all the areas that can be created with the elements in the stack
    while popping the elements until it keeps the its monotonic increasing structure.

    area = 2 * (1-0) = 2
    h = [] 
    p = []

    !! Since the new element is smaller than the last top element of the stack,
    we can start a rectangle with height of 1 starting from the index 0, so we are not going to push 1 as new index to p stack, 
    we will save the previous height since it was greater than the newly pushed height.!!
    h = [1]
    p = [0] 
------------------------------------------------------------------------------------------------------------
    i = 2.
    
    h = [1, 5]
    p = [0, 2]
------------------------------------------------------------------------------------------------------------
    i = 3.
    
    h = [1, 5, 6]
    p = [0, 2, 3]
------------------------------------------------------------------------------------------------------------
    i = 4.
    
    area = 6 * (4-3) = 6
    h = [1, 5]      
    p = [0, 2]
    
    area = 5 * (4-2) = 10
    h = [1]
    p = [0]

    last popped element was greater than the newly pushed element, so use the index of the last popped element.

    h = [1, 2]
    p = [0, 2]
------------------------------------------------------------------------------------------------------------
    i = 5

    h = [1, 2, 3]
    p = [0, 2, 5]
------------------------------------------------------------------------------------------------------------
    we need to calculate the areas of the rectangles that can be created with the elements in the stacks.
    i = 6

    area = 3 * (6-5) = 3
    h = [1, 2]
    p = [0, 2]

    area = 2 * (6-2) = 8
    h = [1]
    p = [0]

    area = 1 * (6-0) = 6
------------------------------------------------------------------------------------------------------------
    answer = 10.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        stack<int> h;
        stack<int> p;
        
        int ans = 0;
        h.push(heights[0]); // initialize the stacks.
        p.push(0);

        for(int i = 1; i < size; i++){
            int curr_num = heights[i];
            int top_value = h.top();
            int top_index = p.top();
            
            if(curr_num > top_value){ // if curr_num > top_value it can be a height to be used with the previous ones.
                h.push(curr_num);     // and also it is a candidate for the next rectangles.
                p.push(i);
            }else{
                int prev_index = top_index; // to keep track the index of the lastly popped element.
                while(!h.empty() && curr_num <= top_value){
                    int area = top_value * (i - top_index);
                    ans = max(ans, area);
                    h.pop();
                    p.pop();
                    prev_index = top_index;
                    if(h.empty()) break; // not to get runtime error, if we try to reach top of the stack with size = 0, it will be error.
                    top_value = h.top();
                    top_index = p.top();
                }
                p.push(prev_index); 
                h.push(curr_num);
            }
        }
        int i = size;
        while(!h.empty()){ // when our stacks are not empty, there will be rectangles that are need to be checked.
            int top_value = h.top();
            int top_index = p.top();
            int area = top_value * (i - top_index);
            ans = max(ans, area);
            h.pop();
            p.pop();
        }

        return ans;
    }
};
