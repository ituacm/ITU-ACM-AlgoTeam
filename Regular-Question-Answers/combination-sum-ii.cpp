// Author: Fatih Baskın
// Reviewer: Fatih Mehmet Köş & Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/combination-sum-ii/

class Solution 
{    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        /**
         * This solution is achieved by recursion.
         * Logic behind this solution is to create combinations recursively.
         * Then checking whether the target is met.
         *
         * To backtrack easily, sorting the list first is preferred.
         * This way, if we pass the target, we guarantee that next elements will pass too.
         *
         * Complexity is O(2^n) but since target is guaranteed to be a small number so in reality,
         * algorithm will work much more faster. (There are 2^n possible combinations.)
         */
        
        // Sorting the array O(n logn)
        sort(candidates.begin(), candidates.end());
        
        // Vector to save number combinations
        vector<vector<int>> results;
        
        // previousNumbers vector, this vector will be initially empty.
        // This vector will be used for containing previous elements.
        vector<int> previousNumbers;
        
        // Unordered map preventDuplicateCombinations saves the status of current integers,
        // We will use this map so we won't use the same number twice in the recursion.
        unordered_map<int, bool> preventDuplicateCombinations; // false: unused, true: used
        
        // Calling the recursive function for combination generation.
        recursive(candidates, target, 0, previousNumbers, preventDuplicateCombinations, results);    
        
        return results;
    }
    void recursive(vector<int>& candidates, int target, int currentIndex, vector<int>& previousNumbers, unordered_map<int, bool> preventDuplicateCombinations, vector<vector<int>>& results)
    {
        // If we reach the target, push the combination into results and break the recursion.
        if(target == 0)
        {
            results.push_back(previousNumbers);
            return;
        }
        // For every number after the current number, we will call the recursion.
        for(int i = currentIndex; i < candidates.size(); i++)
        {
            // Will call recursive function if unused, otherwise skip.
            // Unused part will be explained in detail down below [1].
            if(!preventDuplicateCombinations[candidates[i]])
            {
                // If our current number (candidates [i]) is passing the target, break the recursion.
                if(candidates[i] > target) break;
                
                // If recursion didn't break yet, then push current number to previousNumbers
                previousNumbers.push_back(candidates[i]);
                
                // Then call the recursive function with next index and reduce the target by current number
                // By doing this, in every step we are reducing the target by each element in previousNumbers.
                recursive(candidates, target - candidates[i], i+1, previousNumbers, preventDuplicateCombinations, results);   
                
                // After doing the recursion, popping back the used numbers will clear the previous numbers 
                // from used numbers because we are done with those and we have pushed the combination.
                // Additional explaination will be made down below [2].
                previousNumbers.pop_back();
                // Marking the current number as used.
                preventDuplicateCombinations[candidates[i]] = true;
            }
        }       
    }
    /**
     * [1] Marking the numbers at the end of the recursion:
     * 
     * Ex:  We are targeting 8
     *      Our candidates are 1 1 2 2 3 4 5 6 
     *                         ^ Our code starts to generate combinations from here.
     *
     *      In the first itteration of recursion code will generate
     *      1 1 2 4, then 1 1 6 then 1 2 2 3 ...
     *
     *      After we are done with building our combinations with 1, we mark 1 as used.
     *      When we jump to next item: 1 1 2 2 3 4 5 6
     *                                   ^ We will skip this 1 because it is marked.
     *
     *      This small backtracking works for every recursive function call, every marking is unique.
     *      This is why we are calling preventDuplicateCombinations into our function by value (copying into function).
     *      Otherwise we would generate combinations such as 1 2 2 3 second time.
     *
     *
     * [2] Popping the last element from previousNumbers:
     *
     * From the example above:
     *      - We are done with 1 1 2 4,
     *      - Popping 4, last recursive call added 4.
     *      - There is no alternative to 4, returning,
     *      - Popping 2, also marked 2 as used.
     *      - In the end we tried 5 and 6,
     *      - 1 1 6 is a valid combination.
     *      - Popping 6, then popping both 1s, then our previous numbers vector is empty.
     *      - 1 is marked as used, jumping to 2.
     */                                     
};