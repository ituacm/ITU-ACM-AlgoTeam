// Author: Nurettin Alper Kuzu
// Question link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/*
    Question wants us to "flatten" a binary tree to a linked list.
    2 properties of "flattened" binary trees, i.e. a linked list:
    1-) each nodes left child should be non-existent, i.e. nullptr
    2-) each nodes right child must be the next node in a preorder traversal.

    To remind what preorder traversal is:

            1
           / \
          2   5
         / \   \
        3   4   6

    nodes we visit by using preorder traversal: 1-> 2-> 3-> 4-> 5-> 6

    Brute-force solution that comes to mind is to traverse the tree and write each element to a vector.
    Then, we would go through each element in the vector and modify each nodes left and right child.
    Time complexity would be O(n), because we would be going through each element, and the space complexity would be 0(n)
    too because we would keep an extra vector.

    Reducing the time complexity is impossible unfortunately, because we have to go throught each node in the binary tree.
    However, reducing the space complexity is very much possible. We can work on the binary tree without initializing any
    vectors.

    Important thing to notice to implement this method is as follows:
    In a binary tree whose nodes is initialized from 1 to n, root nodes left subtrees rightmost node would be equal to 
    root nodes right childs value - 1

    Keeping that in mind, we can use a technique like adding roots right child to the previously mentioned rightmost nodes
    right child. Than, finding out that there is no subtree to the right of the root node, we would put the left subtree of
    the root node to its right. After that, we would redo the steps above with the root nodes new right child.

    To visualize the algorithm for the binary tree above, after execution for the root, the binary tree would be:
        
        1
         \
          2
         / \
        3   4
             \
              5
               \
                6
    
    Then, we would use the same method for the root valued "2", thus, we would end up with a flattened binary tree, a linked list.

    Finally, Time Complexity: O(n), Space Complexity: O(1)
*/

// Definiton for the binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution
{
public:
    // Notice how the function does not have return value. That's because we have to modify the original binary tree.
    void flatten(TreeNode *root)
    {
        TreeNode *currentRoot = root; // Points to the node that the algorithm above would be executed
    
        while(currentRoot != nullptr) // While its not the end of the list
        {
            if(currentRoot->left != nullptr) // If there is a left subtree
            {
                TreeNode *rightmostNodeOfLeftSubtree = currentRoot->left;
                while(rightmostNodeOfLeftSubtree->right != nullptr)
                    rightmostNodeOfLeftSubtree = rightmostNodeOfLeftSubtree->right;
                // Above 3 lines find the rightmost node of the left subtree of the current root

                rightmostNodeOfLeftSubtree->right = currentRoot->right; // Append roots right subtree to said node.
                currentRoot->right = currentRoot->left; // Carry left subtree to right subtre.
                currentRoot->left = nullptr; // Empty the left subtree of the current root.
            }

            currentRoot = currentRoot->right; // Move to the next node to execute the algorithm.
        }
    }
};