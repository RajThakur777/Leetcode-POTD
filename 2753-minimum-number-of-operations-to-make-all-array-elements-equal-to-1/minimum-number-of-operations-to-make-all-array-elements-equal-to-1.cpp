class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int even = 0;
        int ones = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] % 2 == 0) {
                even++;
            }
            else if(nums[i] == 1){
                ones++;
            }
        }

        if(ones > 0) {
            return n - ones;
        }

        int len = INT_MAX;

        for(int i=0; i<n; i++) {
            int gcd = nums[i];
            for(int j=i; j<n; j++) {
                gcd = __gcd(gcd , nums[j]);

                if(gcd == 1) {
                    len = min(len , (j - i + 1));
                }
            }
        }
        return len == INT_MAX ? -1 : (len - 1) + n - 1;;
    }
};