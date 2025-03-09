class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        int zeroes = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                zeroes++;
            }
        }

        if(zeroes == 0) return n-1;
        
        int i = 0;
        int zero = 0;
        for(int j=0; j<n; j++){
            if(nums[j] == 0){
                zero++;
            }

            if(zero == 1){
                ans = max(ans , j - i + 1);
            }

            while(zero > 1){
                if(nums[i] == 0){
                    zero--;
                }
                i++;
            }
        }
        return ans - 1;
    }
};