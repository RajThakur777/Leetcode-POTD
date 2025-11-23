class Solution {
public:
    int dp[40001][4];

    int solve(int idx , vector<int> &nums , int sum) {
        if(idx == nums.size()) {
            return (sum % 3 == 0 ? 0 : INT_MIN);
        }

        if(dp[idx][sum] != -1) return dp[idx][sum];

        int take = nums[idx] + solve(idx+1 , nums , ((sum + nums[idx]) % 3));
        int not_take = solve(idx+1 , nums , sum);

        return dp[idx][sum] = max(take , not_take);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , nums , 0);
    }
};