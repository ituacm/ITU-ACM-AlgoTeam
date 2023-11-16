// Author: Bilgenur Çelik
// Question Link: https://leetcode.com/problems/fruit-into-baskets/
// Reviewer: Hacer Akıncı

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
* firstFruit: -1 // not seen yet
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
* // thus currentPick was always increasing in this period, maximum 12
*
* firstFruit: 0
* secondFruit: 2
* current pick will be initialized to secFruitCount+1 // +1 because of the new one
* secFruitCount as before starts with 1
* secFruitCount: maximum 3
*
* maxPick is the greatest of all currentPick values.
* in our case, currentPick's {12, 5} maxPick 12.
*/

class Solution {
   public:
    int totalFruit(vector<int>& fruitTrees) {
        // first fruit will be a tail to secondFruit
        int firstFruit = -1, secondFruit = -1;
        // secFruitCount will be the current pick if a third value comes along
        int secFruitCount = 0;
        // maximum of all currentPick values
        int maxPick = 0;
        // last secondFruit (and if there is, firstFruit) tree count
        int currentPick = 0;

        for (int fruit : fruitTrees) {
            // if the fruit is one of the wanted two fruits then increase currentPick
            if (fruit == firstFruit || fruit == secondFruit)
                currentPick++;
            // if not, currentPick is secFruitCount and the newest fruit
            else
                currentPick = secFruitCount + 1;

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

            // compare currentPick to maxPick and update if necessary
            maxPick = max(maxPick, currentPick);
        }

        return maxPick;
    }
};

// Time comp.-> O(n)
// Space comp.-> O(1)
