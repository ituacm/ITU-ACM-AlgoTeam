// Author: Emre Çelik
// Question Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Reviewer: Denis Davidoglu

//Time Complexity: O(n)

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int result = 0;
		
		    //Adding first k elements to result.
        for(int i=0;i<k;i++){
            result = result + cardPoints[i];
        } 
        //Using current integer as a checker.
        int current=result;
        for(int i=k-1;i>=0;i--) {
			      //We remove the last visited element and add the non-visited
            //element starting from the last
            current = current - cardPoints[i];
            current = current + cardPoints[cardPoints.size()-k+i];
			
            //Checking which is maximum value and give it as a result.
			      result = max(result, current);
        }
        
        return result;
    }
};
