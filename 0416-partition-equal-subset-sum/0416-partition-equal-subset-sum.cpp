// //Recursion:
// class Solution {
// public:

//     bool helper(int idx , int target , vector<int> &nums){
//         if(target == 0) return true;

//         if(idx >= nums.size() && target != 0) return false;

//         bool pick = helper(idx+1 , target-nums[idx] , nums);

//         bool not_pick = helper(idx+1 , target , nums);

//         return (pick) || (not_pick);
//     }

//     bool canPartition(vector<int>& nums) {
//         int total = 0;
//         for(int i=0; i<nums.size(); i++){
//             total += nums[i];
//         }

//         if((total) % 2 != 0) return false;

//         int target = (total) / 2;

//         bool ans = helper(0 , target , nums);

//         if(ans == true) return true;

//         return false;
//     }
// };






//Memoization:
class Solution {
public:
    bool solve(int ind, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(target == 0) return true;

        if(ind == nums.size()) return false;

        if(dp[ind][target] != -1) return dp[ind][target];

        bool take = target >= nums[ind] ? solve(ind+1 , nums , target-nums[ind] , dp) : 0;

        bool ntake = solve(ind+1 , nums , target , dp);

        return dp[ind][target] = take || ntake;
    }
    bool canPartition(vector<int>& nums) {
        int sum =  accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2 != 0) return false;

        int target = sum / 2;

        vector<vector<int>> dp(nums.size() + 1 , vector<int>(target + 1 , -1));

        return solve(0, nums, target, dp);
    }
};