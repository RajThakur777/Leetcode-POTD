class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        if (n % k != 0) {
            return false;
        }

        for (int num : nums) {
            freq[num]++;
        }
        int group = n / k;

        for (auto it : freq) {
            if (it.second > group) {
                return false;
            }
        }
        return true;
    }
};