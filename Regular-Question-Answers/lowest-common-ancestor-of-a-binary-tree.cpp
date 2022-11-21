// Author: Ömer Faruk Erdem
// Reviewer: 

// Time Complexity O(n)
// Space Complexity O(n)

/*
    * The algorithm here is:
    * Find parent node of the every node.
    * Then traverse from node p to root. (Here we can traverse from q to root, it doesn't matter as you will see).
    * Create a unordered map and assign true to every node's value while traversing from p to root 
    * Then traverse from q to root.
    * While traversing if the current nodes unordered map value is 1 return it
    * The main idea here is we have assigned every node's value to 1 
    * from q to root at unordered map .That will help us to identify them.
    * While traversing from p to root first we encounter one of them we will return that node 
    * Since it is the lowest common ancestor of these two (p and q) nodes.
*/
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // map for storing the parent nodes of the nodes
        unordered_map<TreeNode*,TreeNode*> parent; 
        // Assigning null to parent of root since it has no parent
        parent[root]=NULL;

        // Traverse the tree with depth first manner
        stack<TreeNode*> dfs;
        map<TreeNode*,bool> visited;
        dfs.push(root);
        visited[root]=true;
        while(!dfs.empty()){
            TreeNode* currentNode=dfs.top();
            dfs.pop();
                if(currentNode!=NULL){
                    // If the current node's left or right is not null
                    // then store that left and right nodes parent as current node

                    // Checking if the node has left or right since we dont want to assign a null pointer's parent as our current node.
                    if(currentNode->left!=NULL){
                        dfs.push(currentNode->left);
                        visited[currentNode->left]=true;
                        // Assign currentNode's left's parent as currentNode
                        parent[currentNode->left]=currentNode;
                    } 
                    if(currentNode->right!=NULL){
                        dfs.push(currentNode->right);
                        visited[currentNode->right]=true;
                        // Assign currentNode's right's parent as currentNode
                        parent[currentNode->right]=currentNode;
                    } 
                }
        }
        
        
        // We have completed the DFS and got the parents of every node
        // Create a map and assign true to every node that is traversed from q to root.
        unordered_map<TreeNode*,bool> mp;
        TreeNode* traverse=p;
        while(traverse){
            mp[traverse]=true;
            // Assign node to its parent node for traversing from node to root
            traverse=parent[traverse];
        }

        // Traverse from q to root
        traverse=q;
        while(traverse){
            // If the current node is traversed before while traversing from p to root return that node
            if(mp[traverse]) return traverse;
            traverse=parent[traverse];
        }

        return root;
    }
};