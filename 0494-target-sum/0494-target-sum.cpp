//Recursion:
class Solution {
public:

    int solve(int idx , vector<int> &nums , int target , int sum) {
        if(idx >= nums.size()) {
            return (sum == target);
        }

        int plus = solve(idx+1 , nums , target , sum + nums[idx]);

        int minus = solve(idx+1 , nums , target , sum - nums[idx]);

        return (plus + minus);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0 , nums , target , 0);
    }
};