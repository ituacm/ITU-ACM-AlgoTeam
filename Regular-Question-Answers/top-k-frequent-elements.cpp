// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/top-k-frequent-elements/

/**
 * As written in the question, we should need to solve this much better than O(n*logn)
 * We can decrement this complexity to O(n*logk), how? With using heap.
 * We will always have k elements in the heap and we will do n push/pop operation.
 */

// We first create a class which contains the value and frequency of Numbers
class Number {
public:
    int val;
    int frequency;

    // Constructor to use in Main
    Number(int val, int frequency) {
        this->val = val;
        this->frequency = frequency;
    }

    // Operator Overloading
    // In this case we overload less than operator because the heap uses it.
    // Instead of less than sign (<) we use greater than sign (>) in the logical part.
    // Because we will create Min Heap.
    bool operator<(const Number& other) const {
        return this->frequency > other.frequency;
    }
};

class Solution {
public:
    /**
     * We will create a heap that contains most frequent K elements.
     * First, count the frequencies using unordered map
     * Then, push proper elements to heap to store most K numbers in Heap
     * Finally, store resulted numbers in a vector and return it
     */

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Min Heap for most frequent K number
        priority_queue<Number> mostKFrequentNumbers;

        // Unordered map is used for counting the frequency of numbers at start
        unordered_map<int, int> countFrequenciesOfNumbers;
        for (int& num : nums) {
            countFrequenciesOfNumbers[num]++;
        }

        // Initially Min Heap is empty, we need to push some elements directly to fill heap
        // After that we will push numbers if their frequency is greater than the number that is in the heap with least frequency
        // This element will be top element, because we create a min heap according to the frequencies
        int count = 0;
        for (auto itr = countFrequenciesOfNumbers.begin(); itr != countFrequenciesOfNumbers.end(); itr++) {
            // Push k numbers
            if (count < k) {
                mostKFrequentNumbers.push(Number(itr->first, itr->second));
                count++;
            }
            // If frequency of the number is larger than min element in heap, push it to heap
            else if (itr->second > mostKFrequentNumbers.top().frequency) {
                mostKFrequentNumbers.pop();
                mostKFrequentNumbers.push(Number(itr->first, itr->second));
            }
        }

        // Store result numbers in a vector
        vector<int> result;
        while (!mostKFrequentNumbers.empty()) {
            result.push_back(mostKFrequentNumbers.top().val);
            mostKFrequentNumbers.pop();
        }

        return result;
    }
};
