// //Recursion:
// class Solution {
// public:

//     bool solve(int idx , vector<int> &nums) {
//         if(idx >= nums.size()) return false;

//         if(idx == nums.size() - 1) return true;

//         if(nums[idx] == 0) return false;

//         for(int i=1; i<=nums[idx]; i++) {
//             if(solve(idx+i , nums) == true) {
//                 return true;
//             }
//         }
//         return false;
//     }

//     bool canJump(vector<int>& nums) {
//         return solve(0 , nums);
//     }
// };





//Recursion+Memoization:
class Solution {
public:
    int dp[10001];

    bool solve(int idx , vector<int> &nums) {
        if(idx >= nums.size()) return false;

        if(idx == nums.size() - 1) return true;

        if(nums[idx] == 0) return false;

        if(dp[idx] != -1) return dp[idx];

        for(int i=1; i<=nums[idx]; i++) {
            if(solve(idx+i , nums) == true) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));

        return solve(0 , nums);
    }
};