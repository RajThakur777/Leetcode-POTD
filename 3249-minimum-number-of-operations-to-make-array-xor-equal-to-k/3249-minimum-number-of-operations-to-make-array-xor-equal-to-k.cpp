class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        int xr = 0;
        for(int i=0; i<n; i++) {
            xr = (xr ^ nums[i]);
        }

        int val = xr ^ k;

        return __builtin_popcount(val);
    }
};