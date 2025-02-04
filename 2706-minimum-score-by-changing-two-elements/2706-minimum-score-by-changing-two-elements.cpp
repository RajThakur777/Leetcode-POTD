class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        //case-1:
        int ans1 = nums.back() - nums[2];

        //case-2:
        int ans2 = nums[n-3] - nums[0];

        //case-3:
        int ans3 = nums[n-2] - nums[1];

        return min(min(ans1 , ans2) , ans3);
    }
};