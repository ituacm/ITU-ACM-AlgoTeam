// Author: Denis Davidoglu
// Question Link: https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // Each character gets an associated order number, recorded in map
        map<char, int> orderMap;
        for (int i = 0; i < order.length(); i++)
            orderMap[order[i]] = i;
        
        /* '\0' is a special character that will be used as marker of the   *
         * end of a string, in a C-like fashion. Its associated value in    * 
         * map is the smallest, since we want the elements shorter to come  *
         * first.                                                           */                                            
        orderMap['\0'] = -1;
        for (auto &w:words) w.push_back('\0');
        
        // Loop to compare adjacent pairs of words
        for (int i = 0; i < words.size()-1; i++) {
            /* Since adjacent words can start with same characters, index   *
             * where they are different must be found. Depth is incremented *
             * as long as characters are same AND neither of the words run  *
             * out of characters to compare.                                */
            int depth = 0;
            while (words[i][depth] == words[i+1][depth] && 
                   words[i][depth] != '\0' && 
                   words[i+1][depth] != '\0') {
                depth++;
            }

            // If lexicographic order is not satisfied, false is returned.
            if (orderMap[words[i][depth]] > orderMap[words[i+1][depth]])
                return false;
        }
        
        return true;
    }
};
