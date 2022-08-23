// Author: Ceren Yaşar
// Question Link: https://leetcode.com/problems/symmetric-tree/

// Time Complexity: O(N)
// Memory Complexity: O(N)

// This solution uses breadth first search since we start comparisons from the closest child.

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

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        // This queue keeps pairs of tree nodes that are supposed to have equal values
        queue<pair<TreeNode*, TreeNode*>> nextToCheck;
        
        // If the root node stands alone, it is symmetric
        if (!root->left && !root->right)
            return true;
        // If the root node has only one child, it is antisymmetric
        else if (!root->left || !root->right)
            return false;
        
        // First pair that is supposed to have equal values is direct children of the root
        nextToCheck.push({root->left,root->right});
        
        TreeNode *a, *b;

        while (!nextToCheck.empty()) {

            a = nextToCheck.front().first;
            b = nextToCheck.front().second;
            nextToCheck.pop();
            
            // If a and b have equal values, we can look for next nodes to check which would be
            // direct children of a's and b's.
            if (a->val == b->val) {
                // Symmetry axis is placed at the center, so one nodes left child should mirror other's right, vice versa.
                // If one of the children mentioned above do not exist, the tree is antisymmetric.
                if (a->left && b->right)
                    nextToCheck.push({a->left,b->right});

                else if ( (a->left && !b->right) || (!a->left && b->right) )
                    return false;

                if (a->right && b->left)
                    nextToCheck.push({a->right,b->left});

                else if ( (a->right && !b->left) || (!a->right && b->left) )
                    return false;
            }
            // If a and b have different values
            else
                return false;
        }
        // If there occurs no exceptions, the tree is symmetric.
        return true;
    }
};
