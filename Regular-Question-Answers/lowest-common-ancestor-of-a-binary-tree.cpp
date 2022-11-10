// Author: Rojen Arda Şeşen
// Reviewers: Bilge Çelik, Ahmet Furkan Kavraz, Murat Biberoğlu
// Question Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// We will first use preorder traversal to locate the given nodes.
// While traversing, we will store the path to nodes using a vector.
// Each time we visit a node, we will push it to the vector.
// We will pop the node from the vector when returning from it.
// We will save the vector when we encounter one of the nodes we are searching for.
// At the end of this process, we will have 2 seperate vectors containing paths to 
// both of the nodes.
// Then we will compare the 2 vectors containing paths to locate the LCA.

// Time Complexity -> O(n) where n is the number of nodes in the tree.
// Space Complexity -> O(k) where k is the depth of the tree, k <= n.

class Solution {
public:
    vector<TreeNode*> pathToP, pathToQ;
    bool foundP = false, foundQ = false;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        TreeNode* LCA = root;	// Lowest Common Ancestor
        traverse(root, path, p, q);

        for (int i = 0; i < min(pathToP.size(), pathToQ.size()); i++) {
            // We loop while the paths are identical and break when we find a disjunction.
            if (pathToP[i] != pathToQ[i])
                break;
            LCA = pathToP[i];
        }

        return LCA;
    }

    void traverse(TreeNode* root, vector<TreeNode*>& path, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return;
        // If both the nodes are found, we don't need to traverse further.
        if (foundP && foundQ)	
            return;

        // Adding the current node to the path.
        path.push_back(root);

        // Copying path if we found one of the nodes.
        if (foundP == false && root == p) {
            pathToP = path;	
            foundP = true;
        }
        if (foundQ == false && root == q) {
            pathToQ = path;
            foundQ = true;
        }

        traverse(root->left, path, p, q);
        traverse(root->right, path, p, q);

        // Removing the current node from the path.
        path.pop_back();
    }
};
