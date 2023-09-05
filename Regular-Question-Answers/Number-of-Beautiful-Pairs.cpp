// Author: Kemal Tahir Bıcılıoğlu
// Question Link: https://leetcode.com/problems/number-of-beautiful-pairs/

/*
    At first view, we can simply create two nested for loops and iterate over the nums array. 
    Finding first digit of the i'th index, the last digit of the j'th index and finding gcd of them is a valid solution and 
    passes all the test cases. However this is not the efficient solution for this question since it has O(n^2) time complexity. 
    If the constraints were bigger, it would not pass all the test cases. 
    Instead, we can use the fact that there can be 9 possible first or last digit of the numbers in the nums array from 1 to 9. 
    We iterate over the nums array and compare last digit of the nums[i] with all possible first digits. 
    If gcd of them is 1, we add the number of first digit that numbers in the nums array have.
    We ensure the limitation of 0 <= i < j since we calculate first digits after checking the gcds. 
    So that we compare nums[i]'s last digit with first digits of the numbers up to i'th index.  

*/
// n = size of the nums array, m = biggest number in the nums array.
// Time complexity = O(n * (10 + log10(m))) = O(10 * n + log10(m) * n) = O(log10(m) * n). 
// Space complexity = O(1);


class Solution {
public:
    // calculate gcd
    int myGcd(int x, int y){
        if(y == 0){
            return x;
        }
        return myGcd(y, x % y);
    }

    // find the first digit of the given number.
    // we could have used this code instead of this function:
    /*
        while(number >= 10){
            number /= 10;
        }
        return number;
        O(log10(n))
    */
    int getFirstDigit(int number){
        string numberString = to_string(number); // convert string with O(log10(n));
        char firstChar = numberString[0];
        int firstDigit = firstChar - '0'; // (firstChar's ASCII value) - (0's ASCII value) gives the digit's integer value.

        return firstDigit;
    }

    int countBeautifulPairs(vector<int>& nums) {
        int size = nums.size(); // O(1)
        vector<int> countFirstDigits(10); 
        // keep track of how many numbers with first digit at the index which is the same with the digit. 
        //countFirstDigits[1] = total number of numbers whose first digit is 1.

        int result = 0;
        for(int i = 0; i < size; i++){
            for(int tempFirstDigit = 1; tempFirstDigit < 10; tempFirstDigit++){  // try all possible first digits.
                if(myGcd(tempFirstDigit, nums[i] % 10) == 1){  // if satisfy the condition, add to result.
                    result += countFirstDigits[tempFirstDigit];
                }
            }

            int firstDigit = getFirstDigit(nums[i]); // O(log10(n)) n = nums[i].
            countFirstDigits[firstDigit]++; // we have a number whose first digit is firstDigit variable. So increment. 
        }

        return result;
    }
};
