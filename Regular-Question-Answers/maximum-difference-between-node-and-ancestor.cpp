// Author: Murat Biberoğlu
// Question Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
// Reviewer: Denis Davidoglu

class Solution {
public:
    int answer = 0;  // holds maximum difference
    int maxAncestorDiff(TreeNode *root) {
        solver(root, root->val, root->val);
        return answer;
    }

    // The idea is to hold maximum and minimum values of all ancestors
    // as we get deeper in tree and update the answer at each node.
    // The reason why we are holding both of them is because we
    // will be taking absolute value of difference.
    void solver(TreeNode *node, int max_anc, int min_anc) {
        if (!node) return;

        int val = node->val;

        // update the maximum difference
        answer = max(answer, abs(max_anc - val));
        answer = max(answer, abs(min_anc - val));

        // as we go deeper in tree, send updated maximum and minimum ancestor values
        solver(node->left, max(max_anc, val), min(min_anc, val));
        solver(node->right, max(max_anc, val), min(min_anc, val));
    }
};
