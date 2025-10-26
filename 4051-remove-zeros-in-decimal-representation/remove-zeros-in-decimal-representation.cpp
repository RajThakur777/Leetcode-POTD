class Solution {
public:
    long long removeZeros(long long n) {
        string str = to_string(n);

        string res;

        for(int i=0; i<str.size(); i++) {
            if(str[i] != '0') {
                res += str[i];
            }
        }
        return stoll(res);
    }
};