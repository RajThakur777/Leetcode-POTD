class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();

        int ans = 0;
        int cnt_1 = 0;

        int i = 0;

        while(i < n) {
            if(s[i] == '0') {
                ans += cnt_1;

                while(i < n && s[i] == '0') {
                    i++;
                }
            }
            else {
                cnt_1++;
                i++;
            }
        }
        return ans;
    }
};