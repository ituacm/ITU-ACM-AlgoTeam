// Author: Hacer Akıncı
// Question Link: https://leetcode.com/problems/ransom-note/ 

// What is unordered_map? https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/

// Time Complexity = O(n+m) Space Complexity = O(m) 
// n is the length of ransomNote 
// m is the length of magazine

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // every count[] start with zero even if it is not initialized
        // keeps the occurences of each letter in the magazine string 
        unordered_map<char, int> count;
        for(int i = 0; i < magazine.size(); i++){
            count[magazine[i]]++;
        }
        // if the letter in the ransomNote is not in magazine, it is equal to zero in count map
        // if the occurrence of a letter is less in the magazine, it will eventually be zero in the count map.
        for(int i = 0; i < ransomNote.size(); i++){
            if(count[ransomNote[i]] == 0){
                return false;
            }
            // decreasing count of the letter
            count[ransomNote[i]]--;
        }
        return true;
    }
};