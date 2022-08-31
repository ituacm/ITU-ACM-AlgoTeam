// Author: Feyza Sarı
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
string longestCommonPrefix(vector<string>& stringArray){
    
        int n = stringArray.size();

        // if ever there occurs an empty string just directly return ""
        for (int i =0; i < n; i++){
            if (stringArray[i] == "") 
                return stringArray[i];
        }
        
        // sorting the array
        sort(stringArray.begin(), stringArray.end());
        
        // now, after sorting alpabetically we only need to compare 
        // the first and last strings and return the answer
        string answerWord = ""; 
        string firstWord = stringArray[0]; 
        string secondWord = stringArray[n-1]; 
        
        for (int i = 0; i < firstWord.size(); i++){

            //if letter i exists in both strings add it to answer string.
            if (firstWord[i] == secondWord[i]) 
                answerWord += firstWord[i]; 
            else break;
        }
        
        return answerWord;
    }
};

