// //Recursion:
// class Solution {
// public:
//     int solve(int idx , int end , vector<int> &nums) {
//         if(idx > end) return 0;

//         int pick = nums[idx] + solve(idx+2 , end , nums);
//         int not_pick = solve(idx+1 , end , nums);

//         return max(pick , not_pick);
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         if(n == 1) return nums[0];

//         return max(solve(0 , n-2 , nums) , solve(1 , n-1 , nums));
//     }
// };




//Recursion + Memoization:
class Solution {
public:
    int solve(int idx , int end , vector<int> &nums , vector<int> &dp) {
        if(idx > end) return 0;

        if(dp[idx] != -1) return dp[idx];

        int pick = nums[idx] + solve(idx+2 , end , nums , dp);
        int not_pick = solve(idx+1 , end , nums , dp);

        return dp[idx] = max(pick , not_pick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        if(n == 2) return max(nums[0] , nums[1]);

        vector<int> dp1(n+1 , -1);
        vector<int> dp2(n+1 , -1);

        return max(solve(0 , n-2 , nums , dp1) , solve(1 , n-1 , nums , dp2));
    }
};

