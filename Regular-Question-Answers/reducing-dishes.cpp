// Author : Ömer Faruk Erdem
// Question Link="https://leetcode.com/problems/reducing-dishes/"

// Time Complexity : O(nlogn)
// Space Complexity : O(n)

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size() ;
        // Sort the vector in descending order.
        // The reason for that is from greedy aproach obivously.
        sort(satisfaction.begin() , satisfaction.end() , greater<int>() ) ;

        // if a dish that gives most satisfaction is still gives satisfaction less than zero then return 0
        if(satisfaction[0] <= 0 ) return 0;

        // create a prefix-sum array of the sorted array
        vector<int> prefix = satisfaction;
        for(int i=1 ; i<n ;i++ ){
            prefix[i] += prefix[i-1];
        }
        /*
            Lets have a look at the crucial part of the solution
            array :
            {a0 a1 a2 a3 a4 a5}

            corresponging prefix sum array :
            {(a0) , (a0+a1) , (a0+a1+a2), (a0+a1+a2+a3), (a0+a1+a2+a3+a4) }

            As the time passes if we add an element the previous elements will be added also
            Just like the like-time coefficient logic.
        */
        int maxSum = 0 ;
        int currentSum = 0 ;
        for(int i=0 ; i<n ;i++ ){
            currentSum += prefix[i] ;
            maxSum = max(maxSum,currentSum);
        }
        return maxSum;
    }
};

