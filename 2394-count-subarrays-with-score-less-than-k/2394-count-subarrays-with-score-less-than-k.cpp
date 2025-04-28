class Solution {
public:
    #define ll long long

    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        ll cnt = 0;

        ll i = 0;

        ll sum = 0;

        for(int j=0; j<n; j++){
            sum += nums[j];

            while((sum) * (j - i + 1) >= k){
                sum -= nums[i];
                i++;
            }

            cnt += (j - i + 1);
        }
        return cnt;
    }
};