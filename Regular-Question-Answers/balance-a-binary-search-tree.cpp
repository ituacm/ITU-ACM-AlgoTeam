// Author: Novruz Amirov
// Question Link: https://leetcode.com/problems/balance-a-binary-search-tree/
// Reviewers: Emre Çelik, Denis Davidoglu

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
    Problem Definition:
        We are given a Binary Search Tree, which may or may
        not be balanced, and we need to make it balanced.
        Firstly, we will put all nodes to an array in sorted
        way. How to do that? Because we know it is Binary
        Search Tree, if we make Inorder Traverse throughout
        the Tree we will get nodes in sorted way. So we will
        add to an array while traversing. Secondly, using binary
        search technique, we will create a balanced binary search
        tree from a sorted array. We have 2 pointer, left and
        right, which will points to 1st and last element of the
        array. Then we will find the mid element between these 2.
        It will become our root of the tree. By recursively calling
        the function we will send new parameters for left and right
        until we add all elements of array.
*/

class Solution {
   public:
    // vector for storing the elements of tree
    vector<TreeNode*> sorted_numbers;

    // Inorder traverse for adding the elements
    // to the vector in sorted way, so we will
    // not spend additional time for sorting.
    void inorder(TreeNode* root) {
        // if root is NULL then stop.
        if (!root) return;

        // Inorder Traverse: Left, Root, Right.
        if (root->left) inorder(root->left);
        sorted_numbers.push_back(root);
        if (root->right) inorder(root->right);

        // The Time Complexity of Inorder Traverse: O(N).
    }

    // to create the Balanced Tree from sorted vector.
    TreeNode* balancedRoot(int left, int right) {
        // stop condition for binary search:
        if (left > right) return NULL;

        /*
            Example:
                Let's say we have a sorted vector v.
                v = [1, 2, 5, 8, 11]
                the left pointer will point to the 1st
                element which is 1, and right pointer will
                point to the last element which is 11.
                For balanced BST, our root must be 5. Because
                the balanced tree must have the depth difference
                for all subtrees at most one. So every time we
                divide the vector by 2 (left and right), and each
                time we take the mid, which is half of addition of
                left and right, for creating the tree.
        */

        int mid = (left + right) / 2;
        TreeNode* root = sorted_numbers[mid];  // the root of the Balanced Tree
        root->left = balancedRoot(left, mid - 1);
        root->right = balancedRoot(mid + 1, right);

        return root;  // return the root of the balanced tree.
        // The time Complexity of this function: O(log N).
    }

    TreeNode* balanceBST(TreeNode* root) {
        // by traversing the tree inorderly
        // we will get the sorted vector.
        inorder(root);

        // for constructing the balanced tree, we use
        // binary search, and initially left is 0 and
        // right is the last element of the sorted vector.
        TreeNode* result = balancedRoot(0, sorted_numbers.size() - 1);

        return result;
        // The time Complexity of this program is:
        // O(N) + O(log N) = O(N).
        // The space complexity of this program is:
        // O(N).
    }
};
