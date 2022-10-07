// Author: Denis Davidoglu
// Question Link: https://leetcode.com/problems/merge-intervals/
// Reviewer: Bilgenur Çelik

// O(n)-time and O(1)-space solution

// We can define a null interval as [-1, -1] because we encounter 
// only positive values. It will be used to mark deleted intervals.
#define invalid vector<int>(2, -1) 

class Solution {
public:
    // The function below takes two intervals and returns their 
    // union or an invalid interval if the two do not intersect.
    // Note that it works only if a < b.
    vector<int> mergeTwo(vector<int>&a, vector<int>&b) {
        if (a[1] >= b[1]) return a;
        if (a[1] >= b[0]) return {a[0], b[1]};
        return invalid;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // We sort the input so that the mergable intervals 
        // become adjacent. 
        sort(intervals.begin(), intervals.end());
        
        // pointer variable will indicate the index of interval 
        // we are currently working with, the interval that "eats" 
        // the other ones. It remains fixed until there are no more
        // intervals to be merged with.
        int pointer = 0;
        vector<int> guess;
        
        // pointer and i must be always different because we choose 
        // two different intervals. Therefore, the loop starts at 1.
        for (int i = 1; i < intervals.size(); i++) {
            guess = mergeTwo(intervals[pointer], intervals[i]);

            // If there is a possibility to merge, we assign the 
            // resulting bigger interval to the fixed position and 
            // delete the other interval by marking it as invalid.
            // If we cannot merge, we update the fixed position to
            // be at the nearest valid interval, which is i. 
            if (guess != invalid) {
                intervals[pointer] = guess;
                intervals[i] = invalid;
            } else pointer = i;
        }
        
        // Instead of declaring a results array we can use the space 
        // more efficiently by filling in the blanks, created by
        // deleting redundant intervals. Here pointer represents
        // the next available position.
        pointer = 0;
        for (int i = 0; i < intervals.size(); i++) {
            intervals[pointer] = intervals[i];
            // pointer will go on if we filled a valid interval,
            // otherwise it will wait until it gets a valid interval.
            if (intervals[i] != invalid) pointer++;
        }
        intervals.resize(pointer);
        return intervals;
    }
};
