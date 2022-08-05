// Author: Denis Davidoglu
// Question Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        /*The first condition suggests that we should focus 
        only on different pairs of rows. The second condition 
        suggests that we should pick these pairs such that they 
        are adjacent or are divided by an empty row. It is more 
        convinient to store the input in an array where each 
        element is the number of devices on a specific row.*/
        vector<int> convertedData;
        int result = 0;
        for (auto s:bank) {
            int deviceCount = 0;
            for (auto c:s)
                deviceCount += (c == '1');
            
            //We include only non-empty rows for more simplicity
            if (deviceCount > 0)
                convertedData.push_back(deviceCount);
        }
        
        /*Here we calculate the number of matches between devices 
        in every adjacent rows, which is a product.*/
        for (int i = 1; i < convertedData.size(); i++)
            result += convertedData[i-1]*convertedData[i];

        return result;
    }
};