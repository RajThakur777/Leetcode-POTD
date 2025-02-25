class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();

        vector<long long> ans(n);

        int maxi = nums[0];
        for(int i=0; i<n; i++){
            maxi = max(maxi , nums[i]);
            ans[i] = nums[i] + maxi;
        }

        vector<long long> prefix(n);
        prefix[0] = ans[0];

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + ans[i];
        }
        return prefix;
    }
};