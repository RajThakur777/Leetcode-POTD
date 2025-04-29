class Solution {
public:
    #define ll long long

    long long countSubarrays(vector<int>& nums, int k) { 
        int n = nums.size();

        ll maxi = *max_element(nums.begin() , nums.end());

        map<ll , ll> mpp;
        ll ans = 0;

        ll i = 0;
        for(ll j=0; j<n; j++){
            mpp[nums[j]]++;

            while(mpp[maxi] >= k){
                ans += (n - j);

                if(nums[i] == maxi){
                    mpp[maxi]--;
                }
                i++;
            }
        }
        return ans;
    }
};