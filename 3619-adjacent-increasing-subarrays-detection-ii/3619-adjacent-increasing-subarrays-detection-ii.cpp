class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;

        int cnt = 1;
        int prev = 0;

        for(int i=1; i<n; i++) {
            if(nums[i] > nums[i-1]) {
                cnt++;
            }
            else {
                prev = cnt;
                cnt = 1;
            }

            ans = max(ans , min(cnt , prev));
            ans = max(ans , (cnt / 2));
        }
        return ans;
    }
};