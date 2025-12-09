class Solution {
public:
    const int mod = 1e9 + 7;

    #define ll long long 
    
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , ll> right , left;

        for(int i=0; i<n; i++) {
            right[nums[i]]++;
        } 

        long long ans = 0;

        for(int i=0; i<n; i++) {
            int x = nums[i];

            right[x]--;

            if(left.find(2 * x) != left.end() && right.find(2 * x) != right.end()) {
                ans = (ans % mod + (left[2 * x] % mod * right[2 * x] % mod) % mod) % mod;
            }

            left[x]++;
        }
        return (int)ans;
    }
};