// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

class Solution {
public:  

    /**
    * The algorithm focuses to create a binary search tree using binary search :)
    * Every time find a mid value and create a node for that value 
    * Make a recursive call for left and right child.
    */
    
    // Using left and right pointers instead of subarrays decrements the space complexity
    TreeNode* connectNodes( vector<int>& arr, int left, int right ){

        // There can not be any case like that
        // Return null for that reason
        if ( left > right )
            return NULL;
        
        // Find a mid value and create a node for this
        int mid = (left + right) / 2 ;
        TreeNode* createdNode = new TreeNode(arr[mid]);
        
        // Recursive call for creating and assigning the childs of corresponding node 
        createdNode->left = connectNodes( arr, left, mid-1 );
        createdNode->right = connectNodes( arr, mid+1, right );
        
        return createdNode;
    }
    
    // Main solver function
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return connectNodes( nums, 0, nums.size() - 1 );
    }
};
