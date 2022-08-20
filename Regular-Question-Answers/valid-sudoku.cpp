// Author: Hacer Akıncı
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/valid-sudoku/
// Time compexity: O(1) 
// Space compexity: O(1) 

class Solution {
public:
  
    bool isValidSudoku(vector<vector<char>>& board) {

        //In sudoku there is nine 3 x 3 square in the grid and their index 0,1,2...8
        vector<vector<int>> countNumbersPerSquare(10); 
       
        for(int i = 0; i < 9; i++){

            vector<int> countNumbersPerRow(10,0); 
            vector<int> countNumbersPerColumn(10,0);
            
            for(int j = 0; j < 9; j++){

                //check for row
                if(board[i][j] != '.'){

                    // board is char vector, turn into int value 
                    int numInRow = board[i][j] - '0'; 

                    // below equation give the square index of num's current location
                    // i and j are in range[0-8] and i/3 intiger divison so results could be 0,1,2 and same for j/3 
                    // if num's row is 5 and column is 2 then (5/3)=1 and 2/3=0 (1*3)+0=3,
                    // num's square index in grid is 3
                    int squareIndex = (i / 3) * 3 + (j / 3); 
                    
                    // we push the index of square, then we will check if there are same index more than one 
                    countNumbersPerSquare[numInRow].push_back(squareIndex);
                    
                    // increase by one and check if there is more than one in the row 
                    countNumbersPerRow[numInRow]++;
                    if(countNumbersPerRow[numInRow] > 1) 
                        return false; 
                }
                
                //check for column
                if(board[j][i] != '.'){

                    // board is char vector, turn into int value 
                    int numInColumn = board[j][i] - '0'; 
                     
                    //increase by one and check if there is more than one in the column 
                    countNumbersPerColumn[numInColumn]++;
                    if(countNumbersPerColumn[numInColumn] > 1) 
                        return false;  
                }
            }
        }
        
        
      //check the nums if they are repetition in a square  
      for(int i = 1; i < 10; i++){

           //in a sorted array same values has consecutive index
            sort(countNumbersPerSquare[i].begin(), countNumbersPerSquare[i].end());       
          
            for(int j = 1; j < countNumbersPerSquare[i].size(); j++){           
                if(countNumbersPerSquare[i][j] == countNumbersPerSquare[i][j-1]) 
                    return false;                
            }  
        }
        
        //if there is no repetition in rows, columns and squares, then return true it is a valid sudoku
        return true;
    }
};