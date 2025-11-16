class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<n; k++) {
                    if(i != j && j != k && i != k) {
                        int v = nums[i] + nums[j] - nums[k];

                        ans = max(ans , v);
                    }
                }
            }
        }
        return ans;
    }
};