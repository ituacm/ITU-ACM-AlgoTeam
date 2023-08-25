// Author: Caner Aslan
// Question Link: https://leetcode.com/problems/the-kth-factor-of-n/description/?envType=study-plan-v2&envId=amazon-spring-23-high-frequency

class Solution {
public:
    int kthFactor(int n, int k) {
        // create a vector to store the factors of n.
        vector<int> factors;

        // since we obtain the complement (i.e. greater) divisors by using the small divisors, we do not need to iterate over the n.
        // So, iterating over sqrt(n) is what we need. 
        for (int divisor = 1; divisor * divisor <= n; divisor++) {
            if (n % divisor != 0)
                continue;
            
            // divisor is a factor of n so add it to factors vector.
            factors.push_back(divisor);

            // complementaryFactor is the complementary factor.
            int complementaryFactor = n / i;

            // check if they are not the same. If you do not so, cases like 16 = 4 * 4 will cause a problem.
            if (complementaryFactor != i)
                factors.push_back(complementaryFactor);
        }

        // sort the vector in ascending order.
        sort(factors.begin(), factors.end());
        
        // return -1 if n has less than k factors.
        if (factors.size() < k)
            return -1;

        // return the kth factor. since vectors are 0-indexed, we need to return (k-1)th element.
        return factors[k - 1];
    }
};
