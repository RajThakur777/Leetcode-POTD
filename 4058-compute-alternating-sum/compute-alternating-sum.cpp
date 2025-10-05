class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        for(int i=0; i<n; i++) {
            if(i % 2 == 0) {
                ans += nums[i];
            }
            else {
                ans -= nums[i];
            }
        }
        return ans;
    }
};