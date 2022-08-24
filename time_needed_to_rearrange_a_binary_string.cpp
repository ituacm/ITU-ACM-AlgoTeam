// Author: Hacer Akıncı
// Question Link: https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/
// Time compexity: O(n) 
// Space compexity: O(1) 

/*
    We count "zeros" to 1. If we have a 0001 string. 3 zeros means 3 seconds needed to make it 1000.
    Also, we need at least one more second for every '1', but not less than "zero" seconds.
    For example, if we have 000111, we need 5 seconds(two more seconds for two more "ones") to turn 111000.  
    
    Here is calculation for "0110100001" test case:
    
            | 0 | 1 | 1 | 0 | 1 | 0 | 0 | 0 | 0 | 1 |
    zeros     1   1   1   2   2   3   4   5   6   6
    seconds   0   1   2   2   3   3   3   3   3   6
                                                  ^
                                                  |
    For i == 9  we need 6 seconds, even though we need 3 seconds for i==8.   
    
    
*/

class Solution {
public:
    
    int secondsToRemoveOccurrences(string s) {
        
        int zeros = 0, seconds = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '0') zeros++;
            
            //If there is no zero before '1', we don't need to rearrange numbers
            else if(s[i] == '1' && zeros != 0){
                
                // If there is more zeros than we can replace in same time, assign to seconds the number of zeros
                seconds = max(seconds+1, zeros);
            }
            
        }
        
        return seconds;
    }
};
