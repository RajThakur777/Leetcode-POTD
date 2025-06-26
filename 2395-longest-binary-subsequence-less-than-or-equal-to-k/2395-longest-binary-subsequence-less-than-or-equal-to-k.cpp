class Solution {
    #define ll long long 
public:

    ll num(ll l) {
        if (l >= 63) return LLONG_MAX;  
        return 1LL << l;
    }

    int longestSubsequence(string s, int k) {
        int n = s.size();
        int ans = 0;
        int cnt = 0;

        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '1' && num(cnt) <= k) {
                ans++;
                k -= num(cnt);
                cnt++;
            } else if(s[i] == '0') {
                ans++;
                cnt++;
            }
        }
        return ans;
    } 
};
