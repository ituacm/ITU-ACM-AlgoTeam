// Author: Anıl Dervişoğlu
// Question Link: https://leetcode.com/problems/teemo-attacking/

/*
    Problem Statement:
    Given a list of attack times and poison duration, calculate the total time the target is poisoned.
    Consecutive attacks refresh the poison duration without stacking.
*/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int totalPoisonedTime = 0;  // Holds the total time Ashe is poisoned.

        // Loop through the attack times starting from the second attack.
        for (int i = 1; i < timeSeries.size(); i++) {
            // If the current attack happens before the previous poison effect ends, add the difference.
            if (timeSeries[i] - timeSeries[i - 1] < duration)
                totalPoisonedTime += timeSeries[i] - timeSeries[i - 1];
            else  // Otherwise, add the full duration of the poison as the time difference in between the attacks are much longer than given duration.
                totalPoisonedTime += duration;
        }

        // Add the duration for the last attack, which always poisons for the full duration.
        totalPoisonedTime += duration;
        return totalPoisonedTime;
    }
};
