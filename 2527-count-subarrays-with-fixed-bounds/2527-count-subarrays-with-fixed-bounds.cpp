class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();

        long long ans = 0;

        int mini = -1;
        int maxi = -1;
        int culprit = -1;

        for(int i=0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                culprit = i;
            }

            if(nums[i] == minK){
                mini = i;
            }

            if(nums[i] == maxK){
                maxi = i;
            }

            long long smaller = min(mini , maxi);

            long long temp = smaller - culprit;

            ans += (temp <= 0) ? 0 : temp;
        }
        return ans;
    }
};