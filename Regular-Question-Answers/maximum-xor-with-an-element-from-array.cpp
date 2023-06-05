// Author: Murat Biberoglu
// Question Link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

// we are going to use Trie data structure to solve this question
// we will push numbers' binary representations in order to be able to perform xor operations easily
// with Trie we can find maximum xor of given number with numbers in the Trie in constant time

// TrieNode will hold 2 pointer, one points for bit 0 other one points bit 1
class TrieNode {
   public:
    TrieNode* c0 = nullptr;
    TrieNode* c1 = nullptr;
};

class Trie {
   public:
    Trie() {
        root = new TrieNode();
    }

    void push(int num) {
        TrieNode* t = root;

        // convert given number to binary and push to trie
        // note that nodes are pushed from MSB to LSB
        for (int i = 31; i >= 0; i--) {
            if (num & (1 << i)) {
                if (!t->c1) t->c1 = new TrieNode();
                t = t->c1;
            } else {
                if (!t->c0) t->c0 = new TrieNode();
                t = t->c0;
            }
        }
    }

    // returns maximum possible xor of given number and a number in the trie
    int getMaxXor(int num) {
        // if trie is empty return -1
        if (!root->c0 && !root->c1) return -1;

        int result = 0;

        // convert given number to binary and select next node to get maximum xor
        // if current bit is 1 then go to bit 0 if there is else go to bit 1
        // if current bit is 0 then go to bit 1 if there is else go to bit 0
        // note that bits compared from MSB to LSB
        TrieNode* t = root;
        for (int i = 31; i >= 0; i--) {
            if (num & (1 << i)) {   // if current bit is 1
                if (t->c0) {        // and if there is a corresponding bit 0
                    t = t->c0;      // then go to that bit
                    result += (1 << i);     // and increment result by 2^i
                } else {
                    t = t->c1;      // if there is no bit 0 go to bit 1
                }
            } else {                // if current bit is 0
                if (t->c1) {        // and if there is a corresponding bit 1
                    t = t->c1;      // then go to that bit
                    result += (1 << i);     // and increment result by 2^i
                } else {
                    t = t->c0;      // if there is no bit 1 go to bit 0
                }
            }
        }
        return result;
    }

   private:
    TrieNode* root;
};

// compare vectors with their 1st index
struct custom_sort {
    inline bool operator()(const vector<int>& v1, const vector<int>& v2) {
        return (v1[1] < v2[1]);
    }
};

class Solution {
   public:
    // we are going to use offline query method in order to solve this question easly
    // the main idea of offline query is manipulating the order of queries to answer queries easly

    // to perform queries efficiently we are going to sort queries ascendingly with respect to constraint m
    // before each query we will insert numbers which are smaller than the given constraint m in the query
    // after inserting we are sure that every number at the trie
    // then we can search for maximum xor without worried about m
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie = Trie(); // create trie

        sort(nums.begin(), nums.end());     // sort ascendingly

        // push indexes for offline query method
        for (int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);

        // sort vectors ascendingly with respect to their 1st index (constraint m)
        sort(queries.begin(), queries.end(), custom_sort());

        vector<vector<int>> res;    // inner vector holds result with query index
        int lastPushed = -1;
        for (int i = 0; i < (int) queries.size(); i++) {
            // find maximum numbers index that smaller or equal to current constraint m
            int pushUntil = upper_bound(nums.begin(), nums.end(), queries[i][1]) - nums.begin();

            // push numbers that are not pushed yet and smaller than current constraint m
            for (int j = lastPushed + 1; j < pushUntil; j++)
                trie.push(nums[j]);

            lastPushed = pushUntil - 1;     // update lastPushed

            // push answer of the query and index of the query to the res vector
            int maxXOR = trie.getMaxXor(queries[i][0]);
            res.push_back({maxXOR, queries[i][2]});
        }

        // sort the res vector with respect to their 1st index (there are query indexes at 1st indexes)
        sort(res.begin(), res.end(), custom_sort());

        // push query results to the answer array
        vector<int> ans;
        for (int i = 0; i < (int) res.size(); i++)
            ans.push_back(res[i][0]);
        return ans;
    }
};
