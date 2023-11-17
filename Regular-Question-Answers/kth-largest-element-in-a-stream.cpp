// Author: Serhat Sarı
// Question Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Reviewer: Denis Davidoglu

/*
We will solve this question with a min heap priority queue.
We will push the numbers in the vector nums to the priority queue one by one until
the size of the priority queue reaches the k value.
After this, we will keep adding numbers to the priority queue but after adding one,
we will pop the lowest value which is top of the priority queue from the pq.
At the end we will have k numbers in the priority queue with the top of the priority queue being the kth largest value.

When the add function is called, we will push the value to the priority queue and we will check the size of the priority queue.
If size is bigger than the k value, we will pop the number from the top.
Then return the number from the top of the priority queue, which is the kth largest value.

Time Complexity : O(n*log(n)) Because of building the priority queue.

*/

class KthLargest {
public:
    int k_largest;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        k_largest = k;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k_largest)
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k_largest)
            pq.pop();
        return pq.top();
    }
};
