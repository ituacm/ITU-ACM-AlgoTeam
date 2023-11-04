// Author: Kemal Tahir Bıcılıoğlu
// Question Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// Reviewer: 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*  
    What we do here basically is going through the binary tree with a recursive function (util),  
    and checking if the encountered node is the largest node on the path we have been used until arriving there.
    So to do that we need root, and largest value. If the nood is "good" node which is defined in the question as
    the being the largest value on the path we used until arriving there, we need to count it so we use also count.
    It should be passed not as a pointer integer instead of as an integer because if it was defined as integer, we would
    lose the counts when returning from the leaf nodes. 

*/

// n = number of nodes in the tree.
// Time Complexity: O(n), we traverse whole tree.
// Space Complexity: O(h), space complexity here is proportional to the stack calls, stack calls is proportional to the depth of the tree
// meaning that the maximum level of the leaf node.
 
class Solution {
public:
    void util(TreeNode *root, int *count, int largest_value){
        int v = root->val;
        if(v >= largest_value){
            largest_value = v;
            (*count)++; // be careful here. do not write *count++, incrementing operator has a higher precedence then the dereferencing so use parentheses.
        }
        if(root->right != nullptr){
            util(root->right, count, largest_value);
        }
        if(root->left != nullptr){
            util(root->left, count, largest_value);
        }
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        util(root, &count, INT_MIN); // INT_MIN to make the initial comparison valid for the root.
        return count;
    }
};