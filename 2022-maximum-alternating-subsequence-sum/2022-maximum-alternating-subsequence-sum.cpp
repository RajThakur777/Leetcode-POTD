// //Recursion:
// class Solution {
// public:

//     long long solve(int idx , vector<int> &nums , bool flag) {
//         if(idx >= nums.size()) return 0;

//         long long pick = (flag ? nums[idx] + solve(idx+1 , nums , !flag) : -nums[idx] + solve(idx+1 , nums , !flag));

//         long long not_pick = solve(idx+1 , nums , flag);

//         return max(pick , not_pick);
//     }

//     long long maxAlternatingSum(vector<int>& nums) {
//         int n = nums.size();

//         return solve(0 , nums , true);
//     }
// };







// //Recursion + Memoization:
// class Solution {
// public:

//     long long solve(int idx , vector<int> &nums , bool flag , vector<vector<long long>> &dp) {
//         if(idx >= nums.size()) return 0;

//         if(dp[idx][flag] != -1) return dp[idx][flag];

//         long long pick = (flag ? nums[idx] + solve(idx+1 , nums , !flag , dp) : -nums[idx] + solve(idx+1 , nums , !flag , dp));

//         long long not_pick = solve(idx+1 , nums , flag , dp);

//         return dp[idx][flag] = max(pick , not_pick);
//     }

//     long long maxAlternatingSum(vector<int>& nums) {
//         int n = nums.size();

//         vector<vector<long long>> dp(n+1 , vector<long long>(2 , -1));

//         return solve(0 , nums , true , dp);
//     }
// };







//BottomUp -> Tabulation:
class Solution {
public: 
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long long>> dp(n+1 , vector<long long>(2));

        for(int i=1; i<=n; i++) {
            dp[i][0] = max(dp[i-1][1] - nums[i-1] , dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] + nums[i-1] , dp[i-1][1]);
        }
        return max(dp[n][0] , dp[n][1]);
    }
};