class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int cs = 0;
        int ms = INT_MIN;

        for(int i=0; i<n; i++){
            cs += nums[i];

            ms = max(ms , cs);

            if(cs < 0) cs = 0;
        }
        return ms;
    }
};