// Author : Ömer Faruk ERDEM
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution {
public:
    int numDecodings(string s) {
        // create a vector to store the results of the subproblems
        vector<int> dp(s.size(),-1);
        // call the recursive function to solve the problem
        return rec(s,0,dp);
    }
    int rec( string s, int pos, vector<int> &dp ){
        // if we reached the end of the string then it is not possible to decode the string no more
        // return 1 to indicate that it is possible to decode the string
        if(pos == s.size() ) return 1;

        // if the current digit is 0 then it is not possible to decode the string
        // since we dont have any code starts with 0
        if( s[pos]=='0' ) return 0;

        // if we have reached the end of the string then it is possible to decode the string
        if( pos == (s.size()-1 ) ) return 1;
        
        // if we have already calculated the result for this subproblem then return it
        if( dp[pos] != -1 ) return dp[pos];

        // taking one digit is possible for every digit if it is not 0
        // but since we have already checked the 0 case we can ignore it
        int res = rec(s,pos+1,dp);

        // taking two digits is possible if the first digit is 1 or 2 and the second digit is less than 7
        if( s[pos]=='1' || (s[pos]=='2' && s[pos+1]<'7') ) res += rec( s , pos+2 , dp);
        
        // store the result for this subproblem
        dp[pos] = res ;
        // return the result
        return res;
    }
};