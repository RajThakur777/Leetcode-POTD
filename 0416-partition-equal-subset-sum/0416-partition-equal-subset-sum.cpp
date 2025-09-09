// //Recursion:
// class Solution {
// public: 
//     int n;

//     bool solve(int idx , vector<int>& nums , int s) {
//         if(s == 0) return true;

//         if(idx >= n) return false;

//         if(s < 0) return false;

//         bool pick = solve(idx+1 , nums , s-nums[idx]);
//         bool not_pick = solve(idx+1 , nums , s);

//         return pick || not_pick;
//     }

//     bool canPartition(vector<int>& nums) {
//         n = nums.size();

//         int sum = 0;
//         for(int i=0; i<n; i++) {
//             sum += nums[i];
//         }

//         if(sum % 2 != 0) return false;

//         return solve(0 , nums , (sum) / 2);
//     }
// };




//Recursion+Memoization:
class Solution {
public: 
    int n;

    bool solve(int idx , vector<int>& nums , int s , vector<vector<int>> &dp) {
        if(s == 0) return true;

        if(idx >= n || s < 0) return false;

        if(dp[idx][s] != -1) return dp[idx][s];

        bool pick = solve(idx+1 , nums , s-nums[idx] , dp);
        bool not_pick = solve(idx+1 , nums , s , dp);

        return dp[idx][s] = pick || not_pick;
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }

        vector<vector<int>> dp(n+1 , vector<int>(sum , -1));

        if(sum % 2 != 0) return false;

        return solve(0 , nums , (sum) / 2 , dp);
    }
};