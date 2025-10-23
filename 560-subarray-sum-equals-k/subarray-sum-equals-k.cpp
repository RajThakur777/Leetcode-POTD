class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        map<int , int> mpp;
        
        int ans = 0;
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];

            if(sum == k) {
                ans++;
            }

            if(mpp.find(sum - k) != mpp.end()) {
                ans += mpp[sum - k];
            }
            mpp[sum]++;
        }
        return ans;
    }
};