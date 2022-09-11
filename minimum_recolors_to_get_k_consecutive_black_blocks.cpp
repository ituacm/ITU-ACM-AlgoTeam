// Author: Hacer Akıncı
// Reviewer: Ömer Faruk Erdem
// Reviewer: Fatih Baskın
// Question Link: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

/*
 To find minimum recolors to get K consecutive black blocks, 
 we should check every substring occurs K blocks for the number of white blocks in that substring.
 Minimum white block number is equals minimum operation to recolor.

 For the first substring, calculate the white block numbers and keep it. 
 For the rest of that, if next value equals 'W' increase white block numbers by one,
 if first value of previous substring equals 'W' decrease white block numbers by one,
 because it is not include new substring.
 
For example, blocks = "WBBWWBBWBW", k = 7

First substring:
         "WBBWWBBWBW"
          ^     ^
          |     | 
        i = 0   i = 6
whiteBlocks = 3;

Second substring:
         "WBBWWBBWBW"
          ^      ^
          |      |
        i = 0   i = 7
s[7] = 'W' whiteBlocks++;
s[0] = 'W' whiteBlocks--;

whiteBlocks = 3;

And it so on until the end of the string, 
minOperaion is the minimum of all whiteBlocks
*/

class Solution {
public:
    
    int minimumRecolors(string blocks, int k) {
        
        int whiteBlocks = 0, i;
        
        // We calculate white blocks number of the first substring of length k.
        for(i = 0; i < k; i++){
            if(blocks[i] == 'W') whiteBlocks++;
        }
        
        // We initalize minOperation with first value of whiteBlocks,
        int minOperation = whiteBlocks;
        
        // Check rest of the string for minimum value . 
        for(i = k; i < blocks.size(); i++){
            
            // If ith block, last eleman of new substring, is white, increase by one
            if(blocks[i] == 'W') whiteBlocks++;
            
            // We should check (i-k). block because it is no more in new substring,
            // if it is white we should decrease by one
            if(blocks[i-k] == 'W') whiteBlocks--;
            
            // If the white block number of new substring is smaller, assign it to minOperation   
            minOperation = min(whiteBlocks, minOperation);
            
            // Since it cannot be less than zero, return 0
            if(minOperation == 0) return 0;

        }
        
        return minOperation;
    }
};

// Time complexity: O(n) 
// Space complexity: O(1) 
