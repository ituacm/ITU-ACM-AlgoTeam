// Author: Hacer Akıncı
// Question Link: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
// Time compexity: O(n) 
// Space compexity: O(1) 

class Solution {
public:
    
    int minimumRecolors(string blocks, int k) {
        
        int whiteBlocks = 0, i;
        
        // We calculate white blocks number of the first substring of length k.
        for(i = 0; i < k; i++){
            if(blocks[i] == 'W') whiteBlocks++;
        }
        
        // We initalize minOperation with first value of whiteBlocks. Then check rest of the string for minimum value . 
        int minOperation = whiteBlocks;
        
        while(i < blocks.size()){
            
            // If next block is white, increase by one
            if(blocks[i] == 'W') whiteBlocks++;
            
            // We should check (i-k). block because it is no more in substring, if it is white we should decrease by one
            if(blocks[i-k] == 'W') whiteBlocks--;
            
            // If the white block number of new substring is smaller, assign it to minOperation   
            minOperation = min(whiteBlocks, minOperation);
            
            // Since it cannot be less than zero, return 0
            if(minOperation == 0) return 0;
            
            i++;
        }
        
        return minOperation;
    }
};