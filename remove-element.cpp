// Author:Feyza Sarı
// Reviewers: Bilgenur Çelik, Denis Davidoglu
// Question Link: https://leetcode.com/problems/remove-element/
// O(n)

/* First we have to check our element is equal to val.
 If it is not nothing changes. But if they are equal we have to remove the
 element. When we remove an element our array decreases one. So if we swap the
 element - that equals val - and the last element of the array and decrease
 the size of the array we get the wanted array. */
class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        //i is current place, size is array size
        int i = 0;                 
        int size = nums.size() - 1; 

        // search the array while we are in the array
        while (i <= size) {
            // check if they are equal
            // swap the elements, decrease the size of the array(size--)
            if (nums[i] == val)
                swap(nums[i], nums[size--]);
            /* we didn't increase i because when we swap the elements, i'th element is changed with a new value (the last element of the array). So we should check i'th elemet again.*/
            else
            i++; // skip to the next element
        }

        return size + 1; // return the size of the array that wanted
    }
};
