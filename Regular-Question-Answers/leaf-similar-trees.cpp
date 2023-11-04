// Author: Kemal Tahir Bıcılıoğlu
// Question Link: https://leetcode.com/problems/leaf-similar-trees/
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
    In this question we need to reach the leaf node of the given trees,
    and validate if their leaf nodes have the same value in the same order.
    In order to accomplish that we first find the leaf nodes of the both trees,
    then put in an array, then checked the array and validate if they are
    leaf similar trees.

*/

// n,m = number of nodes in the given trees. k = number of leaf nodes.
// Time Complexity: O(max(n,m)) since we traverse whole trees.
// Space Complexity: O(k)

class Solution {
public:
    void create_leafs_array(TreeNode* root, vector<int> &leafs){  // O(n)
        if(root->left != nullptr){  // go left as far as we can to the left leaf node.
            create_leafs_array(root->left, leafs);
        }
        if(root->right != nullptr){  // go right when we cannot go further to the left.
            create_leafs_array(root->right, leafs);
        }
        // actually the order does not have to be left to right since we are creating leafs array with using the same create leafs array function
        if(root->left == nullptr && root->right == nullptr){
            leafs.push_back(root->val); // when you reached the leaf, meaning that left and right does not exist, push_back to the array.
        }
    }
    bool check_arrays(vector<int> &v1, vector<int> &v2){  // check the values. O(n)
        int size1 = v1.size();
        int size2 = v2.size();
        if(size1 != size2){
            return false;
        }
        for(int i = 0; i < size1; i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }
        return true;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1;
        vector<int> leafs2;

        create_leafs_array(root1, leafs1);
        create_leafs_array(root2, leafs2);

        bool ans = check_arrays(leafs1, leafs2);
        return ans;
    }
};