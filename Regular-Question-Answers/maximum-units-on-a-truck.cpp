// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/maximum-units-on-a-truck/

bool compare(vector<int>& arr1, vector<int>& arr2) {
    return arr1[1] > arr2[1];
}

class Solution {
   public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // sort according to the second element
        sort(boxTypes.begin(), boxTypes.end(), compare);

        int result = 0;

        // until there is enough truck space and index is between bounds
        for (int i = 0; i < boxTypes.size() && truckSize > 0; i++) {
            // whether we can get all trucks or we can get the remaining space
            result += (boxTypes[i][0] <= truckSize ? boxTypes[i][0] : truckSize) * boxTypes[i][1];
            truckSize -= boxTypes[i][0] <= truckSize ? boxTypes[i][0] : truckSize;
        }

        return result;
    }
};
