//Recursion+Memoization:
class Solution {
public:
    unordered_map<long long  , long long> mpp;

    long long solve(int idx , vector<int> &power , vector<long long> &dp) {
        if(idx >= power.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        long long not_pick = solve(idx+1 , power, dp);

        long long pick = 1LL * power[idx] * mpp[power[idx]];
        int it = lower_bound(power.begin()+idx , power.end() , power[idx] + 3) - power.begin();

        if(it < power.size()) {
            pick += solve(it , power , dp);
        }

        return dp[idx] = max(pick , not_pick);
    }

    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();

        sort(power.begin() , power.end());

        for(int i=0; i<n; i++) {
            mpp[power[i]]++;
        }

        vector<long long> dp(n , -1);

        return solve(0 , power , dp);
    }
};
