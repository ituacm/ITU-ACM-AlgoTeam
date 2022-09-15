// Author: Rojen Arda Şeşen
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/validate-binary-search-tree/


// Inorder traversal of a binary search tree is a sorted sequence. 
// We will travese the tree in-order, and check if the result is sorted.
// Time Complexity -> O(n) where n is the number of nodes in the tree.
// Space Complexity -> O(1)

class Solution {
public:
    
    bool BSTFlag = true;   // A flag which turns to false when the tree loses BST property.
    long previousNode = LONG_MIN;  // An integer to hold the value in the previous node when traversing the tree.
    
    bool isValidBST(TreeNode* root) {
        
        // At each step we compare the node's value with the previous node.
        // If the value is not bigger than the previous one, the tree is not a bst.
        if (root == NULL) // Return if we reached a NULL node.
            return true;
        
        // Traverse the left child of the tree.
        if (root->left != NULL)
            BSTFlag = isValidBST(root->left);
        else
            true;
        
        // Returns false if we encounter a value that breaks the sorted sequence or a duplicate value.
        if (previousNode >= root->val) 
            return false; 
        else 
            previousNode = root->val; // Update previousNode

        // Traverse the right child of the tree 
        if (root->right != NULL)
            return BSTFlag && isValidBST(root->right); 
        else
            return BSTFlag;
    }
};