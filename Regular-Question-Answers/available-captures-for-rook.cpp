// Author: Denis Davidoglu
// Question Link: https://leetcode.com/problems/available-captures-for-rook/

/* The following implementation firstly searches for pawns located either   * 
 * up, down, left or right of the rook. Afterwards, the found pawns'        *
 * diagonals are checked for having bishops. If there is no bishop on the   * 
 * diagonal, the pawn is counted.                                           */

class Solution {
public: 
    bool bishopAtDiagonal(int x, int y, vector<vector<char>>& board) {
        /* To find bishop that protects pawn at board[x][y], four loops are *
         * used for each direction, each starting at the pawn's position.   */
        
        // Increasing X and increasing Y diagonal
        for (int i = x; i < 8 && (y+i-x) < 8; i++) {
            // If there is a bishop on current tile, return true
            if (board[i][y+i-x] == 'b') return true;
                
            /* If current tile is not empty, no bishop further can reach    *
             * the pawn, so loop terminates                                 */
            if (board[i][y+i-x] != '.') break;
        }

        // Decreasing X and decreasing Y diagonal
        for (int i = x; i >= 0 && (y+i-x) >= 0; i--) {
            if (board[i][y+i-x] == 'b') return true;
            if (board[i][y+i-x] != '.') break;
        }

        // Increasing X and decreasing Y diagonal
        for (int i = x; i < 8 && (y-i+x) < 8; i++) {
            if (board[i][y-i+x] == 'b') return true;
            if (board[i][y-i+x] != '.') break;
        }

        // Decreasing X and increasing Y diagonal
        for (int i = x; i >= 0 && (y-i+x) >= 0; i--) {
            if (board[i][y-i+x] == 'b') return true;
            if (board[i][y-i+x] != '.') break;
        }
        return false;
    }

    int numRookCaptures(vector<vector<char>>& board) {
        int result = 0;
        int rookX, rookY;

        // Locating the rook
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (board[i][j] == 'R')
                    rookX = i, rookY = j;

        /* The following loops search for a pawn at every direction.        *
         * Separate loops are required since pieces should be seen from the *
         * rook's perspective.                                              */

        // Increasing X
        for (int i = rookX+1; i < 8; i++) {
            // If current tile has a pawn
            if (board[i][rookY] == 'p')
                // Add one if there is no bishop at diagonal
                result += !bishopAtDiagonal(i, rookY, board);
    
            /* If tile is not empty, rook cannot attack anything after it.  * 
             * Therefore, the loop must break.                              */
            if (board[i][rookY] != '.') break;
        }

        // Decreasing X
        for (int i = rookX-1; i >= 0; i--) {
            if (board[i][rookY] == 'p') 
                result += !bishopAtDiagonal(i, rookY, board);
            
            if (board[i][rookY] != '.') break;
        }

        // Increasing Y
        for (int j = rookY+1; j < 8; j++) {
            if (board[rookX][j] == 'p')
                result += !bishopAtDiagonal(rookX, j, board);
                
            if (board[rookX][j] != '.') break;
        }

        // Descreasing Y
        for (int j = rookY-1; j >= 0; j--) {
            if (board[rookX][j] == 'p')
                result += !bishopAtDiagonal(rookX, j, board);
        
            if (board[rookX][j] != '.') break;
        }
        
        return result;
    }
};
