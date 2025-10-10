//Recursion+Memoization:
class Solution {
public:
    int dp[100001];

    int solve(int idx , vector<int> &energy , int k) {
        if(idx >= energy.size()) {
            return -1e9;
        }

        if(dp[idx] != -1) return dp[idx];

        int ans = energy[idx];

        if(idx + k < energy.size()) {
            ans += solve(idx+k , energy , k);
        }

        return dp[idx] = ans;
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        memset(dp , -1 , sizeof(dp));

        int ans = INT_MIN;

        for(int i=0; i<n; i++) {
            ans = max(ans , solve(i , energy , k));
        }
        return ans;
    }
};