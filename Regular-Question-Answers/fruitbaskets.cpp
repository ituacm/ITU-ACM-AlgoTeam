// Author: Bilgenur Çelik
// Question Link: https://leetcode.com/problems/fruit-into-baskets/

/*
* We'll collect at most two different types of fruits continuously in an array, starting with any desired index.
* Basically, it asks to find the longest length of the subarray containing at most two elements.
*
* Main focus is the second, last visited type of, fruit, if there is a new fruit we let the first fruit be the second fruit and
* the new fruit be the new one. Keep track of the maximum of all current picks.
*
* [1,1,1,0,0,1,1,1,1,1,0,0,2,2,2]
* if we take above example

* first pass through 1s
* firstFruit: -1 //not seen yet
* secondFruit: 1
* secFruitCount: maximum 3
*
* firstFruit: 1
* secondFruit: 0
* secFruitCount: maximum 2
*
* firstFruit: 0
* secondFruit: 1
* secFruitCount: maximum 5

* firstFruit: 1
* secondFruit: 0
* secFruitCount: maximum 2
* // here firstFruit and secondFruit exchanged positions but they were still either 1 or 0
* // thus current_pick was always increasing in this period, maximum 12
*
* firstFruit: 0
* secondFruit: 2
* current pick will be initialized to secFruitCount+1 // +1 because of the new one
* secFruitCount as before starts with 1
* secFruitCount: maximum 3
*
* max_pick is the greatest of all current_pick values.
* in our case, current_pick's {12, 5} max_pick 12.
*/

class Solution {
public:
    int totalFruit(vector<int>& fruitTrees) {

        // first fruit will be a tail to secondFruit
        int firstFruit = -1, secondFruit = -1;
        // secFruitCount will be the current pick if a third value comes along
        int secFruitCount = 0;
        // maximum of all current_pick values.
        int max_pick = 0;
        // last secondFruit (and if there is, firstFruit) tree count
        int current_pick = 0;


        for (int fruit : fruitTrees) {
            // if the fruit is one of the wanted two fruits then increase current_pick
            if (fruit == firstFruit || fruit == secondFruit)
                current_pick++;
            // if not, current_pick is secFruitCount and the newest fruit
            else
                current_pick = secFruitCount + 1;

            // if this fruit was also equal to second one increase secFruitCount
            if (fruit == secondFruit)
                secFruitCount++;

            // if not
            else {
                // secFruitCount should count the newest fruit from now on
                secFruitCount = 1;

                // first fruit was the tail, now it gets the second's value, and second gets to be the newest one
                firstFruit = secondFruit;
                secondFruit = fruit;
            }

            // compare current_pick to max_pick and update if necessary
            max_pick = max(max_pick, current_pick);
        }

        return max_pick;
    }
};

// Time comp.-> O(n)
// Space comp.-> O(1)

