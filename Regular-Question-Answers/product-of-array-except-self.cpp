// Author: Bilgenur Çelik
// Question Link: https://leetcode.com/problems/product-of-array-except-self/

/*
 * For each element try to find the product of all elements except itself.
 * It can be achieved via keeping two arrays one postfix and one prefix.
 * Then keep the product for every ith element (prefix calculated before i) * (postfix calculated before i)
 * As an example:
 * nums:        1   2   3   4
 * prefix:  1   1   2   6   24
 * postfix:     24  24  12  4   1  (ex : for 3rd element 6*1)
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> prefix(sz+1, 1);
        vector<int> postfix(sz+1, 1);

        for (int i=0; i<sz; i++) {
            prefix[i+1] = nums[i]*prefix[i];
            postfix[sz-i-1] = postfix[sz-i] * nums[sz-i-1];
        }

        vector<int> products(sz);
        for (int i=0; i<sz; i++) {
            products[i] = prefix[i] * postfix[i+1];
        }

        return products;
    }
};

/*
 * It can be optimized memory-wise.
 * It would seem that instead of keeping two additional arrays
 * we can hold a nums value and with it fill the resulting array.
 * Because we don't use last element of prefix array and the first element of postfix array
 * nums:        1   2   3   4
 * prefix:  1   1   2   6   24
 * postfix:     24  24  12  4   1  (ex : for 3rd element 6*1)
 *
 * Thus use the num as a cursor with values shown below:
 * Multiply the two values in same indices.
 *              1   1   2   6
 *              24  12  4   1
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> products(sz);

        int num = 1;
        for (int i=0; i<sz; i++) {
            products[i] = num;
            num *= nums[i];
        }
        num = 1;
        for (int i=0; i<sz; i++) {
            products[sz-i-1] *= num;
            num *= nums[sz-i-1];
        }
        return products;
    }
};