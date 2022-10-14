// Author: Emre Çelik
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int N){

        // initialize values and their romen numerals
        int value[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romen[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string romanAnswer = "";
        int i = 0;
        while (N > 0){
            // checking equalities that can be romen number
            while (N >= value[i]){

                // adding romen number to aour answer
                romanAnswer = romanAnswer + romen[i];

                // decreasing our number since it is bigger than check value.
                N = N - value[i];
            }
            i++;
        }
        return romanAnswer;
    }
};
