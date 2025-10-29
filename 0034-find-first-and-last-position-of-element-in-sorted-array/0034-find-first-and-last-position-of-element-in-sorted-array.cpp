class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int it1 = lower_bound(nums.begin() , nums.end() , target) - nums.begin();

        if(it1 == n || nums[it1] != target) {
            return {-1 , -1};
        }

        int it2 = upper_bound(nums.begin() , nums.end() , target) - nums.begin();

        return {it1 , it2 - 1};
    }
};