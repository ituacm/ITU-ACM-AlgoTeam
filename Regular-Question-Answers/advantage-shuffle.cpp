// Author : Ali Eren Çiftçi
// Question Link : https://leetcode.com/problems/advantage-shuffle/

/*
    Problem Statement:
        You are given two integer arrays nums1 and nums2 both of the same length.
        The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
        Return any permutation of nums1 that maximizes its advantage with respect to nums2.

    Solution:
    The main thing we need to avoid is having every element in nums1 be greater than the corresponding element in nums2.
    Therefore, for each element 𝑥 in nums2, we need to find the smallest element in nums1 that is greater than
    𝑥 and assign it to the position of 𝑥

    To do this as effectively as possible, we should start with the smallest elements in nums2.

    We should store the elements from nums1 that cannot be assigned to nums2 (because they are too small) in a vector called remaining.
    Then, we assign these remaining elements to the positions in nums2 where we couldn't find a suitable larger element.

    ex:
        nums1 = [2,7,11,15], nums2 = [3,10,4,11]
        n2:          n1:
        3,  0       2,  0  In the first step, since the element in n1 is not larger than the element in n2, we assign it to the remaining vector
        4,  2       7,  1  in the second step, since 7 > 3, make nums1[0] = 7 (index of 3 is 0)
        10, 1       11, 2  since 11 > 4 in the third step, nums[2] = 11
        11, 3       15, 3  since 15 > 10 in the fourth step, nums[1] = 15

        We've finished every element in the n1 heap, now it's time to place the rest.
        n2 had {11,3} and remaining had {2,0} so nums1[3] = 2; In the end, the following situation occurred.
        nums1 = [7,15,11,2]
        nums2 = [3,10,4,11]

    TC => O(NlogN)
    SC => O(N)
*/
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> n1, n2;

        for(int i = 0; i < nums1.size(); ++i) //Let's sort the values from smallest to largest, keeping the indexes
        {
            n1.push({nums1[i],i});
            n2.push({nums2[i],i});
        }

        vector<pair<int,int>> kalan;

        while(!n2.empty()) // until we find the corresponding element for every element in n2
        {
            if(n1.empty()){ // If the elements in n1 are finished, look at the remaining vector
                nums1[n2.top().second] = kalan.back().first;
                n2.pop();
                kalan.pop_back();
            }
            else{
                if(n1.top().first > n2.top().first){ // If we've found the corresponding element of n2's smallest element.
                    nums1[n2.top().second] = n1.top().first;
                    n2.pop();
                    n1.pop();
                } else { // If the smallest element of n1 does not satisfy the requirement, keep it and move on to the next one
                    kalan.push_back(n1.top());
                    n1.pop();
                }
            }
        }
        return nums1;
    }
};
