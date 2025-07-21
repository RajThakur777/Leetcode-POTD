class Solution {
public:
    string makeFancyString(string s) { 
        int n = s.size();

        string ans;

        int prev = s[0];
        int cnt = 1;

        ans += s[0];

        for(int i=1; i<n; i++) {
            if(s[i] == prev) {
                cnt++;
            }
            else {
                prev = s[i];
                cnt = 1;
            }

            if(cnt < 3) {
                ans += s[i];
            }
        }
        return ans;
    }
};