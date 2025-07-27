class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;

        int i = 0;
        int j = n-1;

        sort(nums.begin() , nums.end());

        while(i < j) {
            ans += nums[j-1];
            j -= 2;
            i++;
        }
        return ans;
    }
};