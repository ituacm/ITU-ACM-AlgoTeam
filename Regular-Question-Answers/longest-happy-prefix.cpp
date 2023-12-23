/*
Author: Hüseyin Burak Gürdal
Question Link: https://leetcode.com/problems/longest-happy-prefix/description/

Time Complexity: O(n)
Space Complexity: O(n)
*/

// Note: this problem can also be solved using string hashing (also known as rabinkarp algorithm or rolling hash) but prefix function is easier to implement


// Solution:
// let pi be the prefix function of s
// pi[i] is the length of the longest proper prefix of s[0..i] which is also a suffix of s[0..i]
// you can learn more about it here: https://cp-algorithms.com/string/prefix-function.html

// this problem asks us to find the longest prefix of s which is also a suffix of s other than s itself
// this is the same as finding the longest proper prefix of s which is also a suffix of s
// so our answer is s[0..pi[n-1]-1] because pi[n-1] is the length of the longest proper prefix of s which is also a suffix of s 

// prefix function calculation in O(n)
vector<int> prefix_function(string s)
{
    int n  = s.size();
    vector<int> pi(n);
    for(int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

class Solution {
public:
    string longestPrefix(string s) 
    {
        int k = prefix_function(s).back(); // length of the longest proper prefix of s which is also a suffix of s
        return s.substr(0, k); // answer is s[0..k-1]
    }
};
