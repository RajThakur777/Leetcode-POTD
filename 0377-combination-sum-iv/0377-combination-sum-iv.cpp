// //Recursion:
// class Solution {
// public:

//     int recursion(vector<int> &nums , int target , int idx){
//         if(idx == nums.size()){
//             if(target == 0){
//                 return 1;
//             }
//         }
         
//         int ans = 0;

//         for(int j=0; j<nums.size(); j++){
//             if(nums[j] <= target){
//                 ans += recursion(nums , target-nums[j] , nums.size());
//             }
//         }
//         return ans;
//     }

//     int combinationSum4(vector<int>& nums, int target) {
//         return recursion(nums , target , 0);
//     }
// };







//Memoization:
class Solution {
public:
    vector<int> dp;
    int recursion(vector<int> &nums , int target , int idx){
        if(idx == nums.size()){
            if(target == 0){
                return 1;
            }
        }
        
        if(dp[target] != -1) return dp[target];

        int ans = 0;

        for(int j=0; j<nums.size(); j++){
            if(nums[j] <= target){
                ans += recursion(nums , target-nums[j] , nums.size());
            }
        }
        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target + 1 , -1);

        return recursion(nums , target , nums.size());
    }
};