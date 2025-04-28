class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int ms = 0;
        int cs = 0;

        for(int i=0; i<n; i++){
            cs += nums[i];

            if(cs < 0){
                cs = 0;
            }
            ms = max(ms , cs);
        }
        return ms;
    }
};