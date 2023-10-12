// Author: Anıl Dervişoğlu
// Question Link: https://leetcode.com/problems/car-pooling/
// Reviewers: Fatih Baskın

/*
    Problem Description: The problem asks to determine if a car with a given seat
    capacity can complete all provided trips without exceeding its capacity.
    Each trip specifies the number of passengers, pick-up, and drop-off locations.
    The algorithm utilizes an array to keep track of the passenger count changes
    at each trip and checks if the capacity is ever exceeded.
    The time complexity of this solution is O(n), where n is the maximum distance the car can travel.
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // The vector array showing how many passengers has been picked up or dropped off on the each trip
        // Initialized in size 1001 per given limits in the question
        vector<int> passengerCount(1001);

        // For each trip, the number of passengers taken and dropped are implemented in the array
        for (auto &trip : trips)
        {
            passengerCount[trip[1]] += trip[0]; // picking up passengers
            passengerCount[trip[2]] -= trip[0]; // dropping off passengers
        }

        // The array will be converted to show remaining passenger on each trip
        // If passenger count surpasses the capacity at any location the trip cannot be done, returning false
        int currentCount = 0;
        for (auto &location : passengerCount)
        {
            currentCount += location; // number of remaining passengers in the given location
            location = currentCount;
            if (location > capacity)
                return false;
        }
        // Else, the trip can be done, returning true
        return true;
    }
};