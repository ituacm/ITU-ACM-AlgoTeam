// Author: Hacer Akıncı
// Question Link: https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/
// Reviewers: Ömer Faruk Erdem, Fatih Baskın, Denis Davidoglu

/*
    We count "zeros" to '1'. If we have a 0001 string. 3 zeros means 3 seconds needed to make it 1000.
    Also, we need at least one more second for every '1', but not less than "zero" seconds. 
    For example, if we have 000111, we need 5 seconds(two more seconds for two more "ones") to turn 111000.  
    
    Here is calculation for "0110100001" test case:

            | 0 | 1 | 1 | 0 | 1 | 0 | 0 | 0 | 0 | 1 |
    zeros     1   1   1   2   2   3   4   5   6   6
    seconds   0   1   2   2   3   3   3   3   3   6
                              ^                   
                              |                    
    For i = 4  we need 3 seconds, even though there are two zero before 4th index.
    Because we need an extra second for '1' in 2nd index as it was mentioned and this affects the rest of the string. 
    
            | 0 | 1 | 1 | 0 | 1 | 0 | 0 | 0 | 0 | 1 |
    zeros     1   1   1   2   2   3   4   5   6   6
    seconds   0   1   2   2   3   3   3   3   3   6
                                                  ^
                                                  |
    For i = 9  we need 6 seconds, even though we need 3 seconds for i = 8.
    Because '1' should swap with every zero before itself and every swap operation needs 1 second. 
      
*/

class Solution {
public:
    
    int secondsToRemoveOccurrences(string s) {
        
        int zeros = 0, seconds = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') zeros++;
            
            //If there is no zero before '1', we don't need to rearrange numbers
            else if (s[i] == '1' && zeros != 0) {                 
                // If ith value equals 1 and there are zeros before 1, 
                // assign seconds to maximum of seconds + 1 and zeros
                seconds = max(seconds+1, zeros);
            }
        }
        
        return seconds;
    }
};

// Time compexity: O(n) 
// Space compexity: O(1) 

