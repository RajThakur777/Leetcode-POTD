class Solution {
public:
    int MOD = 1e9 + 7;

    int rev(int num){
        int reverse = 0;

        while(num > 0){
            reverse = reverse* 10 + (num % 10);
            num = num / 10;
        }
        return reverse;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i] - rev(nums[i])]++;
        }

        int cnt = 0;
        for(auto it : mpp){
            cnt = cnt + ((((long)(it.second) * (long)(it.second - 1)) / 2) % MOD);
        }
        return cnt % MOD;
    }
};