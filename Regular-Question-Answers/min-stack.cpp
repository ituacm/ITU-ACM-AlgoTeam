// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/min-stack/

class MinStack
{
public:
    // the first value of stack is the value of number,
    // the second value of stack is the value of minimum number in whole stack
    stack<pair<int, int>> st; // val, min
    MinStack(){}

    void push(int val) {

        // if stack is empty the minimum value will be new-added-value
        if (st.empty()){
            st.push({val, val});
        }
        // if not, minimum value can be either new-added-value or the minimum of stack
        else {
            pair<int, int> top = st.top();
            st.push({val, min(val, top.second)});
        }

    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first; // return the value of current element
    }

    int getMin() {
        return st.top().second; // return the value of minimum number in the stack
    }
};