// Author: Emre ÇELİK
// Question Link: https://leetcode.com/problems/repeated-string-match/
// Reviewers:

// Time Complexity : O(n*m)
// Space Complexity : O(1)

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count; //We are declaring our answer attribute.
        if(b.empty()){
            //Checking for special case and return answer.
            return 1;
        } 
        for(int i = 0, j = 0; j < b.size() && i < a.size(); i++, j = 0){
            //Catching a string in b string with while loop.
            while(i < a.size() && a[i] != b[j]){
                 i++;
            }
            int k = i; //Assign our i value to k for protect i value.
            count = 1; //Reassignin in every loop if there is separation.
            while(a[k++] == b[j++]){//Check a and b string are equal in loop.
                if(j == b.size()){
                    //If we reached last element of b string then return answer.
                    return count;
                } 
                if(k == a.size()){
                    //If They are equal and a string is done make k is 0 and decrease count by 1.
                    k = 0; 
                    count++;
                }
            }
        }
        //If we cant reach last element of b string with equality, return -1.
        return -1;
    }
};