class Solution {
public:
    #define ll long long 
    const int mod = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<ll> powers;

        for(int i=0; (1 << i) <= n; i++) {
            if((n & (1 << i))) {
                powers.push_back((1 << i));
            }
        }

        vector<int> ans;
        for(int i=0; i<queries.size(); i++) {
            ll left = queries[i][0];
            ll right = queries[i][1];

            ll val = 1;

            for(int j=left; j<=right; j++) {
                val = (val * powers[j]) % mod;
            }
            ans.push_back(val);
        }
        return ans;
    }
};