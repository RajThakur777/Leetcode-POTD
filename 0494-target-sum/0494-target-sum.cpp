class Solution {
public:

    int helper(int idx , vector<int> &nums , int target , int sum){
        if(idx == nums.size()){
            return sum == target;
        }
        //plus
        int plus = helper(idx + 1 , nums , target , sum + nums[idx]);

        //minus
        int minus = helper(idx + 1 , nums , target , sum - nums[idx]);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return helper(0 , nums , target , 0);
    }
};