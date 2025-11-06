class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        vector<int> indices;

        int cnt = 0;

        string ans;

        int idx = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                cnt++;
            }
            else {
                cnt--;
            }

            if(cnt == 0) {
                ans += s.substr(idx + 1 , i - idx - 1);
                idx = i + 1;
            }
        }
        return ans;
    }
};