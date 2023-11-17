// Author: Denis Davidoglu
// Question Link: https://leetcode.com/problems/array-of-doubled-pairs/

/* My implementation consists of several stages:
 *  1. Sorting and getting rid of dublicates
 *  2. Grouping the numbers which are doubles of each other (ex.: {3, 6, 12}, {-28, -14})
 *  3. Checking within the groups for the possibility of creating a doubled pair array
 */

class Solution {
public:
    vector<pair<int, int>> newArr;

    bool canReorderDoubled(vector<int>& arr) {
        // Stage 1
        sort(arr.begin(), arr.end());

        /* Here newArr is formed by copying the contents of arr. It is  *
         * of type pair<int,int>, where the first denotes the value     *
         * taken from original array, and the second denotes the number *
         * of occurrences.                                              */
        int current = arr[0], count = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != current) {
                newArr.push_back(make_pair(current, count));
                current = arr[i];
                count = 1;
            } else
                count++;
        }
        newArr.push_back(make_pair(current, count));

        // Stage 2 & 3
        for (int i = 0; i < newArr.size(); i++) {
            /* Zero is a special case, because when multiplied by 2, the*
             * result is still zero. If there exists an even number of  *
             * zeros such that they are grouped in pairs, there are no  *
             * problems. Otherwise the result is false.                 */
            if (newArr[i].first == 0)
                if (newArr[i].second % 2)
                    return false;
                else
                    continue;

            /* Checking whether the number of occurrences is equal to   *
             * zero. Naturally there should not be any, but later in the*
             * code the occurrences are erased as a result of matching. *
             * Can be also though as "if not visited".                  */
            if (newArr[i].second != 0) {
                // Stage 2
                /* In matchingBox vector doubles (or halves) of current *
                 * element are collected. To optimize space, only the   *
                 * pointers to them are kept.*/
                vector<pair<int, int>*> matchingBox;
                pair<int, int>* doublesPointer = &(newArr[i]);
                while (doublesPointer != NULL) {
                    matchingBox.push_back(doublesPointer);
                    doublesPointer = findDoubleOf(matchingBox.back()->first);
                }

                // Stage 3
                /* Within the group collected, adjacent pairs that can  *
                 * be paired are erased. If what is left is not zero,   *
                 * this means it is impossible to pair them, so the     *
                 * answer is false.                                     */
                for (int j = 0; j < matchingBox.size() - 1; j++) {
                    int minCount = min(matchingBox[j]->second, matchingBox[j + 1]->second);
                    matchingBox[j]->second -= minCount;
                    matchingBox[j + 1]->second -= minCount;
                    if (matchingBox[j]->second != 0) return false;
                }
                if (matchingBox.back()->second != 0) return false;
            }
        }

        /* If the input survives all the checks until here, the result  *
         * is true.                                                     */
        return true;
    }

    // The double (or half) is found using a simple binary search.
    pair<int, int>* findDoubleOf(int n) {
        int left = 0, right = newArr.size() - 1, mid;

        /* The target is double for positive numbers and half for       *
         * negative numbers. The negative number must be evenly         *
         * divisible by 2. */
        if (n > 0) {
            n *= 2;
        } else {
            if (n % 2) return NULL;
            n /= 2;
        }

        while (left < right) {
            mid = (left + right) / 2;
            if (newArr[mid].first > n) right = mid - 1;
            if (newArr[mid].first < n) left = mid + 1;
            if (newArr[mid].first == n) return &(newArr[mid]);
        }
        if (newArr[left].first == n) return &(newArr[left]);
        return NULL;
    }
};
