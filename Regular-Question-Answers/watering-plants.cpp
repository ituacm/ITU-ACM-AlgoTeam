// Author: Serhat Sarı
// Question Link: https://leetcode.com/problems/sort-the-students-by-their-kth-score/

/*
Here we hold a current_capacity variable to know the amount of water left inside bucket 
and the variable steps. Start the loop from -1 because we start at the river. We check
if our current capacity is bigger than the plant we will water next, if it is bigger
then we simply increase our step by one and decrease the water inside the bucket by the
same amount of water needed for the plant.

If our current capacity is not enough for the next plant, we go back to the index -1
from the index we are right now, (i+1) steps. Then we go back to the plant we were, another
(i+1 steps), after that we move to the plant we will water, which is 1 more step.
Then our current capacity is capacity ( full bucket ) - amount of water needed for the next plant.

Time Complexity : O(n)


*/

class Solution {
public:

    int current_capacity;
    int steps = 0;

    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        current_capacity = capacity;
        for(int i = -1; i<n-1;i++){
            if(current_capacity < plants[i+1]){
                steps += (i+1)*2 +1;
                current_capacity = capacity - plants[i+1];
            }
            else{
                steps++;
                current_capacity -= plants[i+1];
            }
        }
        return steps;
    }
};