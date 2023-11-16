// Author: Bilgenur Çelik
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

/*
It appears that there are 2 repetitive states:

         buy
->s0  --------->  s1
    ^\_________/
        sell

in s0 we can either stay or buy stock and arrive s1. (it is also the starting state!)
in s1 we can either stay or or sell the bought stock and arrive s0.

We can either pay the fee while selling or buying the stock. Let's say we pay while buying.

There can't be any left unsold stock so the ending state should be s0 (return the last element of s0)

// Let's define s0 and s1: (consider how to reach them)
First of all they are vectors having 2 possible operations each step.
s0: 1. stay in s0 (don't buy)
    2. sell stock (selling will contribute positively)
s0[i] = max(s0[i-1], s1[i-1] + prices[i])

s1: 1. stay in s1 (don't sell)
    2. buy stock (buying will contribute negatively (also consider fee))
s1[i] = max(s1[i-1], s0[i-1] - prices[i] - fee);


// base cases:
We don't have any (bought or sold) stock yet.
s0[0] = 0;
Just remember the diagram s0 is the starting state. Reaching s1 is only allowed by buying stock. (and paying the fee)
s1[0] = -(the price of first stock) - fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // find the number of prices:
        int size = prices.size();

        // define 2 states:
        vector<int> s0(size, 0);
        vector<int> s1(size, 0);

        // base cases:
        s0[0] = 0;
        s1[0] = -prices[0] - fee;

        // use the found definitions:
        for(int i=1; i<size; i++){
            s0[i] = max(s0[i-1], s1[i-1] + prices[i]);
            s1[i] = max(s1[i-1], s0[i-1] - prices[i] - fee);
        }

        // s0 is the final state
        //return the last element of s0
        return s0[size-1];
    }
};


* But you should think we are already using the last element in both of the vectors, rest of them are not needed.
* This causes unnecessary memory allocation. We can use a variable instead of vector.
* This yields to most effective solution:
* (But to me, it was easy to comprehend the effective solution by the help of above solution.)
*/

class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();

        int returnState = 0;
        int holdState = -prices[0] - fee;

        for (int i = 1; i < size; i++) {
            returnState = max(returnState, holdState + prices[i]);
            holdState = max(holdState, returnState - prices[i] - fee);
        }

        return returnState;
    }
};

// time comp. -> O(n)
// space comp. -> O(1)
