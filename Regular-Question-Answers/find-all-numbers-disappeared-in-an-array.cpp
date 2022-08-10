// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        // to check which elements are exist on list or not
        unordered_set<int> numbersFromOnetoN;
        
        // push numbers from 1 to N
        for (int i = 1; i <= nums.size(); i++)
            numbersFromOnetoN.insert(i);
        
        // erase the ones that is in the list
        for (int& num: nums)
            numbersFromOnetoN.erase(num);
        
        // push the results to the result vector
        return vector<int>(numbersFromOnetoN.begin(), numbersFromOnetoN.end());
    }
};