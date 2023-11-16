// Author: Murat Biberoğlu
// Question Link: https://leetcode.com/problems/integer-to-english-words
// Reviewer: Denis Davidoglu

class Solution {
   public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        this->init();  // initialize constants

        // holds the corresponding numbers for digits
        // 10^9, 10^6, 10^3, 10^0 (starting from 10^9)
        vector<int> triples;
        int divisor = 1e9;
        for (int i = 0; i < 4; i++) {
            int triple = num / divisor;
            triples.push_back(triple);
            num %= divisor;
            divisor /= 1e3;
        }

        string answer = "";
        // for each triple
        for (int i = 0; i < 4; i++) {
            // if triple is 0 then there is nothing to read
            if (!triples[i]) continue;

            // if there is some words before current triple add space
            if (answer.size()) answer += " ";

            answer += read3decimals(triples[i]);

            // if current triple has unit add space
            if (units[i].size()) answer += " ";
            answer += units[i];
        }
        return answer;
    }

   private:
    unordered_map<int, string> constants;
    vector<string> units;

    string read2decimals(int num) {
        if (num <= 20) return this->constants[num];
        int tens = num / 10;
        int ones = num % 10;

        string ans = "";
        ans += constants[tens * 10];
        if (ones > 0) {
            ans += " ";
            ans += this->constants[ones];
        }
        return ans;
    }

    string read3decimals(int num) {
        if (num < 100) {
            return read2decimals(num % 100);
        } else {
            int hundreds = num / 100;

            string ans = "";
            ans += this->constants[hundreds];
            ans += " Hundred";
            string r = read2decimals(num % 100);
            if (r.size()) {
                ans += " ";
                ans += r;
            }
            return ans;
        }
    }

    void init() {
        this->units = {"Billion", "Million", "Thousand", ""};

        this->constants[0] = "";
        this->constants[1] = "One";
        this->constants[2] = "Two";
        this->constants[3] = "Three";
        this->constants[4] = "Four";
        this->constants[5] = "Five";
        this->constants[6] = "Six";
        this->constants[7] = "Seven";
        this->constants[8] = "Eight";
        this->constants[9] = "Nine";
        this->constants[10] = "Ten";
        this->constants[11] = "Eleven";
        this->constants[12] = "Twelve";
        this->constants[13] = "Thirteen";
        this->constants[14] = "Fourteen";
        this->constants[15] = "Fifteen";
        this->constants[16] = "Sixteen";
        this->constants[17] = "Seventeen";
        this->constants[18] = "Eighteen";
        this->constants[19] = "Nineteen";
        this->constants[20] = "Twenty";
        this->constants[30] = "Thirty";
        this->constants[40] = "Forty";
        this->constants[50] = "Fifty";
        this->constants[60] = "Sixty";
        this->constants[70] = "Seventy";
        this->constants[80] = "Eighty";
        this->constants[90] = "Ninety";
    }
};
