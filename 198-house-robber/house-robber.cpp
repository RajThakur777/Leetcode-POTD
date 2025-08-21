// //Recursion:
// class Solution {
// public:
//     int solve(int idx , vector<int> &nums) {
//         if(idx >= nums.size()) {
//             return 0;
//         }

//         int pick = nums[idx] + solve(idx+2 , nums);
//         int not_pick = solve(idx+1 , nums);

//         return max(pick , not_pick);
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         return solve(0 , nums);
//     }
// };




//Recursion + Memoization:
class Solution {
public:
    int solve(int idx , vector<int> &nums , vector<int> &dp) {
        if(idx >= nums.size()) {
            return 0;
        }

        if(dp[idx] != -1) return dp[idx];

        int pick = nums[idx] + solve(idx+2 , nums , dp);
        int not_pick = solve(idx+1 , nums , dp);

        return dp[idx] = max(pick , not_pick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n+1 , -1);

        return solve(0 , nums , dp);
    }
};