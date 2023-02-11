// Author: Emre Çelik
// Reviewer: 
// Question Link: https://leetcode.com/problems/add-digits/


class Solution {
public:
    int addDigits(int num) {
        // Initialize our num to our answer attribute
        int answer = num;
        // While our answer is bigger than 9, do the our process.
        while(answer>9){
            answer = (answer%10) + (answer/10);
        }
        // Returning our answer 
        return answer;
    }
};
