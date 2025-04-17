class Solution {
public:
    int MOD = 1e9 + 7;
    int countHomogenous(string s) {
        int n = s.size();

        int ans = 0;
        int cnt = 1;

        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                cnt++;
            }
            else {
                ans += (((cnt) * 1LL * (cnt + 1)) / 2) % MOD;
                cnt = 1;
            }
        }
        ans += (((cnt) * 1LL * (cnt + 1)) / 2) % MOD; 

        return ans;
    }
};