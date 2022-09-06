//Author:Ömer Faruk ERDEM
//Question Link = https://leetcode.com/problems/group-anagrams/
class Solution {
public:

    /* Function to return anagram groups 
     * Given string vector as an input and function will return the anagrams according their group
     * So ,what do we mean by anagram group:
     * For example if there are words contains same letters but different order then they are anagram.
     * And  today we will group them according to their characters
     */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // First create a two dimensional result vector to store anagram groups
        vector<vector<string>> result; 

        /* Now the thing ı am doing here is very important because here ı create a map with pair .
         * First element of the pair contains string and second element of the pair contains vector of strings .
         *  That allows us to store the strings that has same characters but different order.
         */
        unordered_map< string , vector<string> >  mp;

        //Traversing the strs array to group the strings 
        for(int i=0;i<strs.size();i++){
            // Storing strs[i] string into a temporary string 
            // This is for sorting the string because when a group of anagrams sorted they become same string 
            // And thats how we identify which anagram group do a string belong 
            
            string temp=strs[i];
            
            sort(temp.begin(),temp.end());
            
            //pushing the string into vector according to sorted temp variable 
            //As ı mentioned in this step every string  will be pushed its group vector
            mp[temp].push_back(strs[i]);
        }


        // Now ı am traversing over the map and pushing that vector of strings to the two dimensional vector that ı have created before
        for(auto it: mp){
            result.push_back(it.second); 
        }
        
        return result;

    }

}; 
