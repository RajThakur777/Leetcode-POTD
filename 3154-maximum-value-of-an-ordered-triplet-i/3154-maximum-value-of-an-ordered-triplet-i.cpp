class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;

        for(long long i=0; i<n-2; i++){
            for(long long j=i+1; j<n-1; j++){
                for(long long k=j+1; k<n; k++){
                    ans = max(ans , ((nums[i] - nums[j]) * 1LL * nums[k]));

                    if(ans < 0) ans = 0;
                }
            }
        }
        return ans;
    }
};