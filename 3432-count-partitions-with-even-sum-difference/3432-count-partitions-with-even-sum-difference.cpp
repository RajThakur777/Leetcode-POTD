class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        vector<int> prefix(n);
        prefix[0] = nums[0];

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i=0; i<n-1; i++) {
            int left = prefix[i];
            int right = prefix[n-1] - prefix[i];

            if((left - right) % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};