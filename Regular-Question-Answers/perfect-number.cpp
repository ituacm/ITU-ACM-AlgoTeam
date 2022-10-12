// Author: Murat Biberoğlu
// Question Link: https://leetcode.com/problems/perfect-number/

class Solution {
   public:
    /**
     * We can check all the numbers until given number x and if it divides x then we will add it to sum.
     * But this algorithm runs in O(n). And it is not enough for given constraints. Can we do better?
     *
     * The idea is checking dividers until the squareroot of given number.
     * Assume that p divides number x, then let q = x / p will also divide x.
     * One of them is greater one and other one is smaller.
     * That means if we go over of squareroot of x we will repeat ourselves.
     * Instead of traversing all the numbers until given number we can traverse until squareroot of x.
     * If we detect once an integer p divides x, then we know q = x / p divides also.
     * Then we add p and q to the sum. This algorithm runs in O(sqrt(n))
     */
    bool checkPerfectNumber(int num) {
        // 1 is not a perfect number
        if (num == 1)
            return false;
        int sum = 1;  // 1 divides every integer
        for (int i = 2; i * i <= num; i++) {
            // if i divides given number
            if (num % i == 0) {
                // if i is not squareroot of number, add both of divisors
                if (i != (num / i))
                    sum += i + (num / i);
                // if i is squareroot of number, then add just i
                // in case 9, you can not add 3 twice
                else
                    sum += i;
            }
        }
        return sum == num;
    }
};