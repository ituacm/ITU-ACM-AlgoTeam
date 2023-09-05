//Author: Ecem Özkul
//Question Link: https://leetcode.com/problems/count-and-say/
//Time Complexity: O(2^N)
#include <string>
using namespace std; 

class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        } //Special case of n=1
    string previous = countAndSay(n-1); //Recursive function calls itself for countAndSay(n-1)
    string result= ""; //Defining result
    int count=1; //Defining a count variable
    for (int i = 0; i < previous.length(); i++) {
        if (i + 1 < previous.length() && previous[i] == previous[i + 1]) {
            count++; //Counting same numbers in a row
        } else {
            result += to_string(count) + previous[i]; //Adding count and number as a string to result
            count = 1; //Resetting the count for new numbers
        }
    }

    return result;
       
    }
};