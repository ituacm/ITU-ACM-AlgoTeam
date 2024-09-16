//Author: Rampia Perente
// Question Link: https://leetcode.com/problems/multiply-strings

/* 
Problem Statement: Given two non-negative integers 
num1 and num2 represented as strings, 
return the product of num1 and num2, 
also represented as a string.

Note: You must not use any built-in BigInteger 
library or convert the inputs to integer directly.
*/

class Solution {
public:
    string multiply(string num1, string num2) {

        /*Handle the edge case: if either number is zero, 
        it will lead the result to zero
        */
        if(num1 == "0" || num2 == "0")
        return "0";

        /*
        Initialize the vector that will hold the result, 
        the size of multiplication cannot exceed 
        the sum of sizes of two numbers
        */
        vector<int> result(num1.size() + num2.size(), 0);

        for(int i = num1.size() - 1; i >= 0; i--)
        for(int j = num2.size() - 1; j >= 0; j--)
        {
            /*
            Basic multiplication step: Since we are operating on strings, 
            we have to convert the string to integer. 
            '0' has an ASCII value of 48, '1' -> 49, ...., '9' -> 57, 
            so num[] - '0' will give the integer value 
            of each character, for example, 57 - 48 = 9
            */
            int multiply = (num1[i] - '0') * (num2[j] - '0');
            /*
            Add the carry and the multiplication result 
            at the current position of the result vector
            */
            int sum = multiply + result[i + j + 1];
            /*
            If the sum is greater than 9, take the rightmost 
            digit of it and store it in current position
            */
            result[i + j + 1] = sum % 10;
            /*
            Add the carry that occured by dividing 
            the sum by 10 to the next position in result 
            vector(we are going right to left)
            */
            result[i + j] += sum / 10;
        }
        
        string answer;
        
        //Skip leading zeros
        int i = 0;
        while(result[i] == 0)
        i++;

        /*
        Convert each digit of integer number to string
        and append it to the string answer
        */
        while(i < result.size())
        answer += to_string(result[i++]);

        return answer;
    }
};