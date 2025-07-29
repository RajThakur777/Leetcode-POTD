class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        vector<int> setBit(32 , -1);

        for(int i=n-1; i>=0; i--) {
            int endIdx = i;
            for(int j=0; j<32; j++) {
                if(!(nums[i] & (1 << j))) {
                    if(setBit[j] != -1) {
                        endIdx = max(endIdx , setBit[j]);
                    }
                }
                else {
                    setBit[j] = i;
                }
            }
            ans[i] = endIdx - i + 1;
        }
        return ans;
    }
};