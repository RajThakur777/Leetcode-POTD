class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();

        while(s.size() != 2) {
            string ans;
            for(int i=0; i<s.size()-1; i++) {
                int d1 = s[i] - '0';
                int d2 = s[i+1] - '0';

                ans += ((d1 + d2) % 10);
            }

            s = ans;
        }

        if(s[0] == s[1]) return true;

        return false;
    }
};