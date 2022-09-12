// Author:Feyza Sarı
// Question Link: https://leetcode.com/problems/remove-element/
// O(n)

/* First we have to check our element is equal to val.
 If it is not nothiing change. But if they are equal we have to remove the
 element. When we remove an element our array decrease one. So if we swap the
 element - that equals to val - and the last element of array and decrease the
 size of array we get the wanted array. */
class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int i = 0;                  // current place
        int size = nums.size() - 1; // array size

        // search the array while we ar in the array
        while (i <= size) {
            // check if they are equal
            // swap the elements, decrease the size of array(size--)
            if (nums[i] == val)
                swap(nums[i], nums[size--]);
            else
            i++; // skip to the next element
        }

        return size + 1; // return the size of array that wanted
    }
};
