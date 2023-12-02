// Author: Denis Davidoglu
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/happy-number/

class Solution {
public:
    int mutate(int n) {
        int result = 0;
        while (n > 0) {
            result += (n % 10) * (n % 10);
            n /= 10;
        }
        return result;
    }

    bool isHappy(int n) {
        /*We store all previous found numbers in a set and at each step
        we check whether we had already met the number. If we had, it means
        we found a cycle and we return false. If we find 1 we return true.
        The loop continues untill one of two happens.*/
        set<int> numbers;
        while (true) {
            numbers.insert(n);
            n = mutate(n);
            if (n == 1) return true;
            if (numbers.find(n) != numbers.end())
                return false;
        }
    }
};
