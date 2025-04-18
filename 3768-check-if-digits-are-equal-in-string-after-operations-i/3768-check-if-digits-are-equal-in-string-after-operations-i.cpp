class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2){
            string res = "";

            for(int i=0; i<s.size() - 1; i++){
                int num = (s[i] - '0' + s[i+1] - '0') % 10;
                res += to_string(num);
            }
            s = res;
        }
        return s[0] == s[1];
    }
};