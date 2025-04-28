class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int ms = INT_MIN;
        int cs = 0;

        for(int i=0; i<n; i++){
            cs += nums[i];

            ms = max(ms , cs);
            
            if(cs < 0){
                cs = 0;
            }
        }
        return ms;
    }
};