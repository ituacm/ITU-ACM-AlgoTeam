// Author : Ömer Faruk ERDEM
// Time Complexity : O(nlogn)
// Space Complexity : O(1)

class Solution {
public:
    // compare function to sort the boxTypes vector
    bool comp(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // sort the boxTypes vector according to the number of units in the box
        sort(boxTypes.begin(),boxTypes.end(),comp);
        // create a variable to store the result
        int sum = 0;

        // iterate over the boxTypes vector 
        for(int i=0 ; i<boxTypes.size() ; i++){
            //  truckSize is 0 then we can not load any more boxes
            if(!truckSize) break;
            
            // if the number of boxes in the current box is less than or equal to the truckSize
            // then we can load all the boxes of the current type
            if(boxTypes[i][0] <= truckSize){
                sum += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            // if the number of boxes in the current box is greater than the truckSize
            // then we can load only the truckSize number of boxes
            else{
                sum += truckSize * boxTypes[i][1];

                // make trucksize 0 to indicate that we can not load any more boxes
                truckSize = 0;
            }
        }

        // return the total number of units that we can load
        return sum;
    }

};

