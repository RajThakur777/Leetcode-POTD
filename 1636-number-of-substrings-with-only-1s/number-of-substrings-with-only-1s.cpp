class Solution {
public:
    const int mod = 1e9 + 7;
    int numSub(string s) {   
        int n = s.size();

        long long cnt = 0;
        long long ans = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                cnt++;
            }
            else {
                ans = (ans % mod +  ((((cnt) * (cnt + 1))) / 2) % mod) % mod;
                cnt = 0;
            }
        }
        if(cnt > 0) {
            ans = (ans % mod +  ((((cnt) * (cnt + 1))) / 2) % mod) % mod;
        }
        return ans;
    }
};