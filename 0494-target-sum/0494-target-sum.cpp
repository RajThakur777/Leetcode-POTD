// //Recursion:
// class Solution {
// public:

//     int solve(int idx , vector<int> &nums , int target , int sum) {
//         if(idx >= nums.size()) {
//             return (sum == target);
//         }

//         int plus = solve(idx+1 , nums , target , sum + nums[idx]);

//         int minus = solve(idx+1 , nums , target , sum - nums[idx]);

//         return (plus + minus);
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         return solve(0 , nums , target , 0);
//     }
// };




//Recursion+Memoization:
class Solution {
public:
    int S;
    int solve(int idx , vector<int> &nums , int target , int sum , vector<vector<int>> &dp) {
        if(idx >= nums.size()) {
            return (sum == target);
        }

        if(dp[idx][sum+S] != -1) return dp[idx][sum+S];

        int plus = solve(idx+1 , nums , target , sum + nums[idx] , dp);

        int minus = solve(idx+1 , nums , target , sum - nums[idx] , dp);

        return dp[idx][sum+S] = (plus + minus);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        S = 0;
        for(int i=0; i<n; i++) {
            S += nums[i];
        }

        vector<vector<int>> dp(n+1 , vector<int>(2*S+1 , -1));

        return solve(0 , nums , target , 0 , dp);
    }
};