class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        if(sum % k == 0) {
            return 0;
        }

        int ans = 0;
        for(int i=1; i<=1000000; i++){
            if(i % k == 0 && i < sum){
                ans = i;
            }
        }

        return abs(ans-sum);
    }
};