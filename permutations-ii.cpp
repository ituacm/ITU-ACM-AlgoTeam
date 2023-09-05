// link: https://leetcode.com/problems/permutations-ii/description/
class Solution {
public:
    // Bu işlev, verilen bir tam sayı vektöründe benzersiz permütasyonları hesaplar.
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        generateUniquePermutations(0, nums, result);
        return result;
    }

private:
    void generateUniquePermutations(int index, vector<int>& nums, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(nums);  // Mevcut permütasyon sonuç vektörüne eklenir.
            return;
        }

        map<int, bool> used;  // Daha önce kullanılan elemanları izlemek için bir harita oluşturulur.
        for (int i = index; i < nums.size(); ++i) {
            if (used[nums[i]]) {
                continue;  // Aynı elemanı bir daha kullanmaktan kaçınılır.
            }

            used[nums[i]] = true;  // Bu eleman kullanıldı olarak işaretlenir.
            swap(nums[index], nums[i]);  // Elemanlar yer değiştirerek permütasyon oluşturulur.
            generateUniquePermutations(index + 1, nums, result);  // Diğer elemanlar rekürsif olarak işlenir. O(N!) komplekitisi
            swap(nums[index], nums[i]);  // Elemanlar yerlerine geri alınır.
        }
    }
};
