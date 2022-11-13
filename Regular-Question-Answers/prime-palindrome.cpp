// Author: Murat Biberoğlu
// Question Link: https://leetcode.com/problems/prime-palindrome/
// Reviewers: Fatih Baskın, Feyza Sarı, Denis Davidoglu

class Solution {
   public:
    /**
     * Theorem: All palindrome numbers that have even number of digits divisible by 11.
     * https://en.wikipedia.org/wiki/Divisibility_rule#11
     *
     * If given number is less than or equal to 2, the answer is 2
     * We will try every number and we will start n if n is odd,
     * otherwise we will start n + 1 because primes are odd except 2.
     */
    int primePalindrome(int n) {
        if (n <= 2) return 2;
        int p = n % 2 ? n : n + 1;
        while (true) {
            // if p is prime and palindrome return true
            if (isPrime(p) && isPalindrome(p))
                return p;
            p += 2;  // even numbers are not prime

            // pass numbers that have even number of digits except 11
            if (1e1 + 1 < p && p < 1e2)
                p = 1e2 + 1;
            if (1e3 < p && p < 1e4)
                p = 1e4 + 1;
            if (1e5 < p && p < 1e6)
                p = 1e6 + 1;
            if (1e7 < p && p < 1e8)
                p = 1e8 + 1;
        }
    }

    // Returns true if given integer is prime, else returns false
    // O(sqrt(num))
    bool isPrime(int num) {
        if (num <= 1 || num % 2 == 0) return false;
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0) return false;
        return true;
    }

    // Returns true if given integer is palidrome, else returns false
    // O(log10(num)) ~= O(1)
    bool isPalindrome(int num) {
        string s = to_string(num);
        int n = s.length();
        for (int i = 0; i < n / 2; i++)
            if (s[i] != s[n - 1 - i]) return false;
        return true;
    }
};
