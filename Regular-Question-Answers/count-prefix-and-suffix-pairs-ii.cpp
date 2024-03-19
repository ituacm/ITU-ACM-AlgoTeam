// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/

/*
    Solution: O(sum of word lengths)

    This is a straightforward solution that uses hashing to map a string of any length to an integer.
    Hashing is pretty useful when it comes to optimizing resource usage.
    The main idea of hashing is the following:
        If the hashes of two strings are equal, then the strings are equal.
    Of course, because of the method used to generate hashes, there is a slight probability that
    two different strings' hashes are equal.
    This may be considered a downside of hashing, though, the probability can be dramatically decreased by
    using multiple hashes generated with different parameters (e.g., base, mod...) to identify a string.
    A common exemplary method is using "double hashing", that is, using two hash values instead of one.
    However, I was lucky with my base (345) and mod (1e9 + 7) choices that using one hash was enough :D

    The hash formula I used for a string s is as follows (B = 345, M = 1e9 + 7):
        HASH = (s[0] + 345 * s[1] + 345^2 * s[2] + ... + 345^(n-1) * s[n-1]) % M

    From left to right (for prefixes), it can be calculated by storing 345's current power in a variable:
        CURRENT_HASH = PREV_HASH + s[i] * power
    However, for suffixes, the calculation order should be reversed: from right to left. In order to calculate this way,
   the following formula is neat: CURRENT_HASH = s[i] + 345 * CURRENT_HASH

    So, what I did is:
        Calculate the hashes of the prefix and suffix simultaneously.
        Check if the current prefix and suffix are equal.
        If so, check if encountered a string equal to the prefix before, in the `words` list.
        If so, increase the answer by the number of those strings.
*/
class Solution {
  public:
    // It's pretty convenient to write `ll` instead of `long long`, right?
    using ll = long long;

    // The base and mod values for generating hashes.
    const int HASH_BASE = 345;
    const int mod = 1e9 + 7;

    ll countPrefixSuffixPairs(vector<string> &words) {
        // hash_cnt[hash] = # of words whose hash is equal to `hash` so far.
        // I preferred unordered_map over map since it's faster in general (O(1) vs. O(logn)).
        unordered_map<ll, int> hash_cnt;

        // The answer itself.
        ll ans = 0;

        for (auto &word : words) {
            int n = word.size();

            // The prefix hash, suffix hash, and 345's current power for prefix hash.
            ll pre_hash = 0, suf_hash = 0, pre_pw = 1;

            // The prefix and suffix hash calculations are done as explained above.
            for (int i = 0; i < n; i++) {
                (pre_hash += pre_pw * word[i] % mod) %= mod;
                (pre_pw *= HASH_BASE) %= mod;
                suf_hash = (HASH_BASE * suf_hash % mod + word[n - 1 - i]) % mod;

                // Without hash_cnt.count() check, the runtime increases considerably.
                // It's because unordered_map's random access operator [] creates the key with an initial value of 0 if
                // the key didn't exist. If you think, this is unnecessary.
                if (pre_hash == suf_hash && hash_cnt.count(pre_hash))
                    ans += hash_cnt[pre_hash];
            }

            // Notice that the prefix (or suffix) hash will be the hash of the whole word at the end.
            // Count the word once it's processed, for future words.
            hash_cnt[pre_hash]++;
        }

        return ans;
    }
};