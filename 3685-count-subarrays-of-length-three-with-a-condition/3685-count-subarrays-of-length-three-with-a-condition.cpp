class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;

        for(int i=1; i<n-1; i++){
            int a = nums[i-1];
            int b = nums[i];
            int c = nums[i+1];

            if((b) == 2 * (a + c)){
                cnt++;
            }
        }   
        return cnt;
    }
};