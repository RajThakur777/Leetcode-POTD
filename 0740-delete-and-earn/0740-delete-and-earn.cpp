//Recursion+Memoization:
class Solution {
public:
    unordered_map<int , int> mpp;
    int dp[20001];

    int solve(int idx , vector<int> &nums) {
        if(idx >= nums.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int not_pick = solve(idx+1 , nums);

        int pick = (mpp[nums[idx]] * nums[idx]);

        int i = upper_bound(nums.begin() + idx , nums.end() , nums[idx] + 1) - nums.begin();

        if(i < nums.size()) {
            pick += solve(i , nums);
        }

        return dp[idx] = max(pick , not_pick);
    }

    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        memset(dp , -1 , sizeof(dp));

        sort(nums.begin() , nums.end());

        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        return solve(0 , nums);
    }
};