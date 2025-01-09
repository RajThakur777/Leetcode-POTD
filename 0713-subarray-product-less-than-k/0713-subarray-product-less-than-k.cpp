class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
         
        if(k <= 1) return 0;

        int cnt = 0;
        int i = 0;
        
        int prod = 1;
        for(int j=0; j<n; j++){
            prod *= nums[j];
            
            while(prod >= k){
                prod /= nums[i];
                i++;
            }

            cnt += (j - i + 1);
        }
        return cnt;
    }
};