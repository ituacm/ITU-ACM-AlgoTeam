// Author: Toygun Görmüş
// Question Link: https://leetcode.com/problems/slowest-key/
// Reviewers: Hacer Akıncı, Denis Davidoglu

/* We need to traverse the releaseTimes array and calculate the pressing time for every key.
Then we need to evaluate the largest of these times and get the larger one lexicographically if there is an equality.
*/

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        /* We start by initializing the variables. "time" keeps track of the pressing time of the current key,
         "max_time" keeps track of the maximum value and "max_key" stores the key of that value.
         */
        int time;
        int max_time = releaseTimes[0];
        char max_key = keysPressed[0];

        for (int i = 1; i < releaseTimes.size(); i++) {
            time = releaseTimes[i] - releaseTimes[i - 1];
            // If the time is larger then the maximum value, we update the maximum value and the key it represents.
            if (time > max_time) {
                max_time = time;
                max_key = keysPressed[i];
            }
            // If the time is equal to the maximum value we get the lexicographically greater one using max function.
            else if (time == max_time) {
                max_key = max(max_key, keysPressed[i]);
            }
        }
        return max_key;
    }
};
