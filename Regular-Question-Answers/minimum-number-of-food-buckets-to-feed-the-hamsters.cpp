// Author: Emre Çelik
// Reviewer: 
// Question Link: https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/

/*
 * The goal of this algorithm is to determine the minimum number of buckets required
 * to place hamsters in a line according to the given rules.
 *
 * The algorithm iterates through each character in the 'hamsters' string,
 * representing the arrangement of hamsters and empty spaces.
 *
 * Time complexity:O(n)
 * Space complexity:O(1)
 */

class Solution {
public:
    // Function to calculate the minimum number of buckets required for feed hamsters.
    int minimumBuckets(string hamsters) {
        // Counter to store the minimum number of buckets.
        int answer = 0; 
        // Number of characters in the 'hamsters' string.
        int n = hamsters.size(); 

        // Iterate through each character in 'hamsters'.
        for(int i = 0; i < n; i++){
            // Check if the current character is a hamster ('H').
            if(hamsters[i] == 'H'){
                // If a hamster is followed by an empty space, increment the bucket count.
                if(i + 1 < n && hamsters[i + 1] == '.'){
                    answer = answer + 1;
                    //If 2 hamsters can have 1 bucket we change its value.
                    if(i + 2 < n && hamsters[i + 2] == 'H'){
                        hamsters[i + 2] = 'D';
                    }
                }
                // If a hamster is preceded by an empty space, increment the bucket count.
                else if(i - 1 >= 0 && hamsters[i - 1] == '.'){
                    answer = answer + 1;
                }
                // If a hamster is not surrounded by empty spaces, return -1 (invalid arrangement).
                else{
                    return -1;
                }
            }
        }

        // Return the minimum number of buckets.
        return answer; 
    }
};
