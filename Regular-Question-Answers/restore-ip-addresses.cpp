// Author: Rojen Arda Şeşen
// Reviewer: 
// Question Link: https://leetcode.com/problems/restore-ip-addresses/

// We're required to split the given string into 4 valid sections. 
// A section is valid when it's not greater than 255 and does not have
// a leading 0 except it's 0 (0 is valid, 01 or 012 is not).

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        return splitIP(s, 4);
    }

    vector<string> splitIP(string& s, int nSplits) {
        // Possible combinations of s split into nSplits IP sections
        vector<string> possibles;

        // If s is the last section of the IP address
        if (nSplits == 1) {
            // Return an empty list if s does not fit requirements
            //   -> s can't be greater then 255
            //   -> s can't have a leading 0 if s is not equal to 0.
            if (stol(s) > 255 || (s.length() > 1 && s[0] == '0')) 
                return {};
            // If s fits the requirements, simply return s
            // No splits are required since n equals 1.
            return {s};
        }

        // A section can have maximum 3 digits and minimum 1 digit.
        // Given that s will be split into nSplits sections, if all
        // sections except the first one gets a single digit, first
        // digit can have at most (s.length() - (n - 1)) digits, capped
        // by 3.
        int maxLen = min(3, static_cast<int> (s.length()) - (nSplits - 1));

        // Looping through the nubmer of digits the first section can have.
        for (int digits = 1; digits < maxLen + 1; digits++) {
            
            // Creating a substring from s.
            string firstSection(s.begin(), s.begin() + digits);
            // The rest of s.
            string remaining(s.begin() + digits, s.end());

            // Break if the section is invalid -> greater than 255
            if (stoi(firstSection) > 255)
                break;

            // Recursively calling splitIP funciton on the lower part
            // of s, splitting it into nSplits - 1 parts. After the
            // function returns a list of possible lower sections,
            // iteration over the items and mergeing each with the
            // upper section.
            for (auto& subsection: splitIP(remaining, nSplits - 1))
                possibles.push_back(firstSection + '.' + subsection);

            // Break if the section starts with 0 but is not equal to 0.
            if (firstSection.length() > 1 && firstSection[0] == '0')
                break;
        }
        return possibles;
    }

};