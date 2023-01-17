// Author: Denis Davidoglu
// Question Link: https://leetcode.com/problems/sort-the-people/

/* My method uses a map to associate heights with the initial       *
 * order. After the heights are sorted in desceding order, people's *
 * names are selected in the proper order, by consulting the        *
 * unsortedPattern map fed by the sorted heights array. In this way,* 
 * there is no need to combine the two vectors into one structure.  */

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, int> unsortedPattern;
        vector<string> result;
        for (int i = 0; i < heights.size(); i++)
            unsortedPattern[heights[i]] = i;
        sort(heights.begin(), heights.end(), greater<int>());
        for (int i = 0; i < heights.size(); i++)
            result.push_back(names[unsortedPattern[heights[i]]]);
        return result;
    }
};