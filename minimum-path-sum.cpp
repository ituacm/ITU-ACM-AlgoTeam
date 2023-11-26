	// Ali Davut Eskiocak
	
	//https://leetcode.com/problems/minimum-path-sum/
	
	/*we will create a 2 D array and we will store most efficient cost to reach each position
	we will use dynamic memory approach 
		Time complexity 0(n*m)
		Space complexity o(1)
	*/
	class Solution {
	public:

    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
		
		//first loop will travel all rows and second loop for columns
        
		for(int i=0; i < n; i++) {
            for(int j = 0; j<grid[0].size(); j++) {
    		
				//These two conditions for edge positions 
	            if( i == 0 && j > 0) grid[i][j] += grid[i][j-1];
                if( j == 0 && i > 0) grid[i][j] += grid[i-1][j];
                
                // we will find lowest-cost position from neighbours and we will sum with the value we reached
                //finally we will update it
                if ( i>0 && j>0) grid[i][j] += min(grid[i][j-1], grid[i-1][j]); 
            }
        }


        return grid[n-1][grid[0].size()-1];
    }
};
