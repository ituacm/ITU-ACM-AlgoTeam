// Author: Murat Biberoglu
// Question Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

class Solution {
   public:
    int answer = 0;  // holds maximum difference
    int maxAncestorDiff(TreeNode *root) {
        solver(root, root->val, root->val);
        return answer;
    }

    // The idea is to holding maximum and minimum values of all ancestors
    // as getting deeper at tree and update answer at each node.
    // The reason why we are holding both of them is because we
    // will taking absolute value of difference.
    void solver(TreeNode *node, int max_anc, int min_anc) {
        if (!node)
            return;

        int val = node->val;

        // update the maximum difference
        answer = max(answer, abs(max_anc - val));
        answer = max(answer, abs(min_anc - val));

        // as going deeper at tree, send updated maximum and minimum ancestor values
        solver(node->left, max(max_anc, val), min(min_anc, val));
        solver(node->right, max(max_anc, val), min(min_anc, val));
    }
};
