// Author: Ömer Faruk Erdem
// Reviewer: 
// Question Link: https://leetcode.com/problems/remove-letter-to-equalize-frequency/

// Time Complexity: O(n^2)
// Space Complexity: O(n)

/*
    * In this question there so many edge cases so it is very annoying to deal with all of them.
    * Thats why brute force solution is best for this question
    * Here the algorithm:
    * Create a map and calculate every letter's frequencies
    * Iterate through the map and at every iteration decrease a letter's frequency by one
    * then check if all of the letter's frequency is equal or not. If all of the frequencies are equal return true 
*/

class Solution {
public:
    // Function for checking if all the elements in the map has same value 
    bool allEqual(map<char,int> mp){
        map<char,int>::iterator itr;
        
        // Ignore the letters that has frequency 0.
    
        // Pick a cpmparing element from the map then consider others according to that element
        // Comparing element that belongs the map and it must be nonzero.

        int compare=0;

        // Assign first nonzero value in the map to compare variable
        for(itr = mp.begin() ; itr != mp.end() ; itr++){
            if( itr->second != 0 ) {
                compare=itr->second;
                break;
            }
        }

        // Now iterate through map and compare the letters' frequencies with compare variable.
        // If they are different then return false 
        for(itr=mp.begin();itr!=mp.end();itr++){
            if(itr->second==0) continue;

            if(itr->second != compare) return false;
        }
        return true;
    } 

    bool equalFrequency(string word) {
        // Create a map to store the frequencies of the letters.
        map<char,int> mp;
        
        // Store the frequencies
        for(int i=0;i<word.size();i++){
            mp[ word[i] ]++;
        }

        // Iterate through the map 
        map<char,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            // Decrease the letter's frequency by one
            it->second--;
            
            // Check if all of the frequencies are equal on the map
            if(allEqual(mp)) return true;
            
            // Increment the frequency that we have decreased if all of the frequencies 
            // are not equal after decreasing that letter's frequency 
            it->second++;
        }

        // Return false if it is not possible to remove one letter so that the frequency of all letters is equal
        return false;
    }
};

