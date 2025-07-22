class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;

        map<int , int> mpp;

        int sum = 0;

        int i = 0;
        for(int j=0; j<n; j++) {
            mpp[nums[j]]++;
            sum += nums[j];

            while(mpp[nums[j]] >= 2) {
                mpp[nums[i]]--;
                sum -= nums[i];

                if(mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }
                i++;
            }
            ans = max(ans , sum);
        }
        return ans;
    }
};