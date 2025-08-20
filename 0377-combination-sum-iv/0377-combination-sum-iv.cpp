//Recursion:
class Solution {
public:
    vector<vector<int>> dp;

    int solve(int idx , vector<int> &nums , int target) {
        if(target == 0) return 1;

        if(idx >= nums.size() || target <= 0) return 0;

        if(dp[target][idx] != -1) {
            return dp[target][idx];
        }

        int pick = solve(0 , nums , target - nums[idx]);
        int not_pick = solve(idx+1 , nums , target);

        return dp[target][idx] = pick + not_pick;
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(1001 , vector<int>(201 , -1));
        
        return solve(0 , nums , target);
    }
};