class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        
        unordered_map<int, int> counts;
        for (int val : nums) {
            counts[val]++;
        }

        set<int> candidates;
        for (int val : nums) {
            candidates.insert(val);
            candidates.insert(val - k);
            candidates.insert(val + k);
        }

        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        int max_ans = 0;

        for (int x : candidates) {
            int orig_freq = counts.count(x) ? counts[x] : 0;

            auto it_low = lower_bound(sorted_nums.begin(), sorted_nums.end(), x - k);
            auto it_high = upper_bound(sorted_nums.begin(), sorted_nums.end(), x + k);
            
            int total_in_range = distance(it_low, it_high);

            int changeable = total_in_range - orig_freq;

            int current_freq = orig_freq + min(changeable, numOperations);
            
            max_ans = max(max_ans, current_freq);
        }

        return max_ans;
    }
};