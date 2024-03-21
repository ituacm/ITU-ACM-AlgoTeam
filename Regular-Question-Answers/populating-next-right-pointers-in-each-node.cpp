// Author: Bilgenur Çelik
// Problem Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

/*
* Node definition
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*
* Next pointer is the pointer to the next node of the same level.
*
* Since we'll update the 'next' pointers of the nodes, we can use bfs to traverse the tree.
* Thus we'll use a queue to store the nodes of the current layer.
* Whenever we pop from the queue, it will have the right child first, then the left child.
* The temp pointer will be used to keep track of that linearity of the nodes, ending with the right most node's next pointer being NULL.
* We'll update the next pointer of the current node to the temp node.
* (The question guarantees that the tree is a perfect binary tree, so we can check the leaf condition by checking only one child.)
*/

class Solution {
public:
    Node* connect(Node* root) {
        // if the tree is empty, return NULL
        if (root == NULL) return root;

        // bfs queue to store the nodes of the current layer and traverse the tree
        queue<Node*> bfs_queue;
        // add the first layer, which is the root
        bfs_queue.push(root);

        while (!bfs_queue.empty()) {
            // next pointer holder temporary pointer
            Node* temp = NULL;
            // size of the current layer
            int size_layer = bfs_queue.size();
            // in the layer, update the next pointers of the nodes
            for (int i = 0; i < size_layer; i++) {
                Node* front = bfs_queue.front();
                bfs_queue.pop();

                // add the children of the nodes to the queue, if they exist
                if (front->right != NULL) {
                    bfs_queue.push(front->right);
                    bfs_queue.push(front->left);
                }
                // update the next pointer of the current node and then update the temp pointer
                front->next = temp;
                temp = front;
            }
        }
        return root;
    }
};
