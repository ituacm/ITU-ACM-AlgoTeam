// Author: Caner Aslan
// Question Link : https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/description/

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        // get the number of turns 
        int turns = player1.size();
        
        // initialize each player's score with the number of first pin they hit
        int p1Score = player1[0]; 
        int p2Score = player2[0];

        for (int i = 1; i < turns; i++) {
            // check for the second turn
            if (i == 1) {
                // if the player1 hits ten pins at the first run, multiply the current number of pins by 2 and add it to the score
                if (player1[i - 1] == 10)
                    p1Score += 2 * player1[i];
                // if not so, add pins directly to the score
                else
                    p1Score += player1[i];

                // if the player2 hits ten pins at the first run, multiply the current number of pins by 2 and add it to the score
                if (player2[i - 1] == 10)
                    p2Score += 2 * player2[i];
                // if not so, add pins directly to the score
                else
                    p2Score += player2[i];
            } 
            // check for the next turns
            else {
                // if the player1 hits 10 pins in any previous two turns, multiply the current number of pins by 2 and add it to the score
                if (player1[i - 1] == 10 || player1[i - 2] == 10)
                    p1Score += 2 * player1[i];
                // if not so, add pins directly to the score
                else
                    p1Score += player1[i];

                // if the player2 hits 10 pins in any previous two turns, multiply the current number of pins by 2 and add it to the score
                if (player2[i - 1] == 10 || player2[i - 2] == 10)
                    p2Score += 2 * player2[i];
                // if not so, add pins directly to the score
                else
                    p2Score += player2[i];
            }
        }

        // player1 wins
        if (p1Score > p2Score)
            return 1;
        // player2 wins
        else if (p2Score > p1Score)
            return 2;
        // draw
        else
            return 0;
    }
};