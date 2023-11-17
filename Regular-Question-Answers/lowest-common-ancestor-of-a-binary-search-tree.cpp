// Author: Rojen Arda Şeşen
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// Two nodes are in different subtrees if their common parent's
// value lies between the values of given nodes.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* currentNode = root;
        while (currentNode != NULL) {
            // If the value of the current node is greater than both of the given nodes, the nodes lie in the left subtree.
            if (p->val < currentNode->val && q->val < currentNode->val)
                currentNode = currentNode->left;

            // If the value of the current node is smaller than both of the given nodes, the nodes lie in the right subtree.
            else if (p->val > currentNode->val && q->val > currentNode->val)
                currentNode = currentNode->right;

            // If the value of the current node is between or equal to the given nodes, it is the lowest common ancestor.
            else
                break;
        }
        return currentNode;
    }
};
