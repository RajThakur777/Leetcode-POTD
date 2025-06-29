class Solution {
public:
    #define ll long long
    const ll mod = 1e9 + 7;

    ll binPow(ll a , ll b , ll mod) {
        if(b == 0) return 1;

        ll res = binPow(a , b / 2 , mod) % mod;

        if(b % 2 == 0) {
            return (res * res) % mod;
        }
        return (res * res * a) % mod;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        int i = 0;
        int j = n-1;

        int ans = 0;

        while(i <= j) {
            if(nums[i] + nums[j] <= target) {
                ans = (ans + binPow(2 , (j - i) , mod)) % mod;
                i++;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};