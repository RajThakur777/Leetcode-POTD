class Solution {
public:
    int minimumFlips(int n) {
        string str;

        int bits = log2(n);

        for(int i=0; i<=min(bits,30); i++) {
            if((n & (1 << i)) > 0) {
                str += '1';
            }
            else {
                str += '0';
            }
        }

        string str2 = str;
        reverse(str2.begin() , str2.end());

        int ans = 0;
        for(int i=0; i<str.size(); i++) {
            if(str[i] != str2[i]) {
                ans++;
            }
        }
        return ans;
    }
};