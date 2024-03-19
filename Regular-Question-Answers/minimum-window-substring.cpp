// Author: Fatih Baskın
// Reviewer:
// Question link: https://leetcode.com/problems/minimum-window-substring/

// Time Complexity: O(n) size of string max(s, t)
// Space Complexity: O(n) number of unique letters in t

/*
 * The logic behind this solution is using a map to save the unique letters and their counts in t
 * Then by using sliding windows, finding the smallest window possible that matches string t
 *
 * First, we expand the window until it matches t,
 * Then we narrow it down until it doesn't match t,
 * While narrowing down, we save the narrowest matching window that matches t.
 *
 * In the end, narrowest window will be the answer, or an empty string if the narrowest window
 * size didn't update during our iteration.
 */

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // If the t's letter count is greater than s, then there is no substring in s such that
        // covers all the letters in t.
        if (t.size() > s.size())
            return "";

        // First, iterate trough t, to build its map.
        unordered_map<char, int> t_map;
        for (char c : t)
            t_map[c]++;

        // Get the number of unique letters
        int num_unique_letters = t_map.size();

        int minimum_window_length = INT_MAX;
        int minimum_window_start_idx = 0;

        int window_start_idx = 0;
        int window_end_idx = 0;

        // We need to have a sliding window, we will adjust its size dynamically.
        for (window_end_idx = 0; window_end_idx < s.size(); window_end_idx++)
        {
            // Get the current letter.
            char current_letter = s[window_end_idx];

            // Consume the current letter from t_map, if we consumed all the letters of current_letter type, decrement counter.
            // Note that we check whether it exists in the map first.
            if (t_map.find(current_letter) != t_map.end())
            {
                // Consume the current letter
                t_map[current_letter]--;

                // Also, if we hit zero, we reduce the num_unique_letters by one
                // since we consumed all the letters in current letter type
                if (t_map[current_letter] == 0)
                    num_unique_letters--;
            }

            // The above part will expand the window, if we consume all the unite letters in t_map, we need to shrink the window.
            while (num_unique_letters == 0)
            {
                // Get the current window length
                int current_window_length = window_end_idx - window_start_idx + 1;

                // If the current is the new minimum window, update minimum window.
                if (current_window_length < minimum_window_length)
                {
                    minimum_window_start_idx = window_start_idx;
                    minimum_window_length = current_window_length;
                }

                // Shift the starting letter to the right, but before doing so, we need to add current letter into the t_map
                // if it belongs to t_string.
                char starting_letter = s[window_start_idx];

                // Add the starting letter to t_map if it belongs to t
                if (t_map.find(starting_letter) != t_map.end())
                {
                    t_map[starting_letter]++;

                    // If we hit more than zero, by adding this letter to map, then we need to update unique letter count again.
                    // Note that we might not hit it too, it is possible that we have "aaaaabc" and we are looking for "abc"
                    if (t_map[starting_letter] > 0)
                        num_unique_letters++;
                }

                // Shift the starting index to the right.
                window_start_idx++;
            }
        }

        // After all those sliding window operations, if minimum_window_length didn't update (still INT_MAX) then we return empty string
        if (minimum_window_length == INT_MAX)
            return "";

        // Otherwise, we return the substring staring from minimum_window_start_idx and with length minimum_window_length
        return s.substr(minimum_window_start_idx, minimum_window_length);
    }
};
