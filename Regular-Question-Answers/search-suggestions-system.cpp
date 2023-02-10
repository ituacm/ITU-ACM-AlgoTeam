// Author: Murat Biberoğlu
// Question: https://leetcode.com/problems/search-suggestions-system/
// Reviewer: Denis Davidoglu

class Solution {
public:
    // regular node class for trie
    class Node {
    public:
        // note that children are kept in ordered map because
        // we want first 3 words in lexicographical order
        map<char, Node*> children;
        bool isEnd = false;
    };
    
    // the idea is going to a deeper trie node at each character typed and looking for words from current node
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // initialize root for the trie data structure
        Node* root = new Node();

        // insert every word to trie
        for (auto s: products) insert(root, s);

        vector<vector<string>> result;

        // holds first 3 suggestions for each step
        vector<string> suggest;

        // starting node for looking words
        // at each step of writing a character, we will go to the related trie node,
        // instead of starting root again, this will reduce time complexity
        Node* curnode = root;   
        string prefix = ""; 

        int n = searchWord.size();
        for (int i = 0; i < n; i++) {
            suggest.clear();
            prefix += searchWord[i];

            if (curnode) // prevent segmentation fault
                curnode = curnode->children[searchWord[i]]; // go to the next trie node
            getFirst3Word(curnode, suggest, prefix);
            result.push_back(suggest);
        }
        return result;
    }

    // regular trie insertion function
    void insert(Node* root, string s) {
        int n = s.size();
        Node* traverse = root;
        for (int i = 0; i < n; i++) {
            if (traverse->children.find(s[i]) != traverse->children.end())
                traverse = traverse->children[s[i]];
            else {
                traverse->children[s[i]] = new Node();
                traverse = traverse->children[s[i]];
            }
        }
        traverse->isEnd = true;
    }

    // looks for every word in the trie starting from given node recursively
    void getFirst3Word(Node* node, vector<string> &suggest, string s) {
        // if node is null return
        if (!node) return;

        // if it finds 3 words stops for searching
        if (suggest.size() == 3) return;

        if (node->isEnd)            // if current node is end of a word
            suggest.push_back(s);   // push to the suggest vector

        // for each child of node, continue to search for words
        for (auto p: node->children)
            getFirst3Word(p.second, suggest, s + p.first);
    }
};
