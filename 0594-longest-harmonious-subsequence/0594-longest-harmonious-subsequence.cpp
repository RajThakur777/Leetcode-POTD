class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();

        map<int , int> mpp;

        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        int ans = 0;
        for(auto it : mpp) {
            int f = it.first;
            int freq = it.second;

            if(mpp.find(f + 1) != mpp.end()) {
                ans = max(ans , freq + mpp[f + 1]);
            }
        }
        return ans;
    }
};