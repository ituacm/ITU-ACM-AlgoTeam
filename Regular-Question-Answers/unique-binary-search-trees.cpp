// Author: Feyza Sarı
// Question Link: https://leetcode.com/problems/unique-binary-search-trees/
// Reviewer: Denis Davidoglu

class Solution {

/* If a number i in 1-n range will be the root of tree, numbers that are less than i have to form another binary search tree 
in the left side of the root. And the numbers larger than the root also form the right subtree.
When we multiply the numbers of left subtrees and right subtrees, we can find the number of binary search trees with the root i.
We can do this operation for all possible root (all the element in array), and find the answer.
But in this operation we calculate some of the trees over and over again. To prevent this we can use dynamic programing.
We should use a vector for storing the number of possible trees that consist i element.
*/
public:
    int numTrees(int n) {
        // create the vector for memoization
        // trees[i] = number of bst that consist 1-i elements
        vector<int> trees(n + 1, 0);

        // if number of nodes are 0 or 1 we can create just 1 tree
        trees[0] = 1;
        trees[1] = 1;

        // find all the element of the vector 1-n
        for (int i = 2; i <= n; i++)
            // the total number of binary search trees is equal to the sum of the number of binary search trees 
            // to be formed with all possible roots. 
            for (int j = 0; j < i; j++)
                // number of trees is equal to product of number of right subtree and number of left subtree
                trees[i] += trees[j] * trees[i - j - 1];
                
        //return the nth element of vector
        return trees[n];
    }
};
