class Solution {
public:
    long long sumAndMultiply(int n) {
        string str = to_string(n);

        string res;

        for(int i=0; i<str.size(); i++) {
            if(str[i] != '0') {
                res += str[i];
            }
        }

        if(res.empty()) return 0;

        long long sum = 0;
        for(int i=0; i<res.size(); i++) {
            sum += (res[i] - '0');
        }

        long long value = stoll(res);

        return (sum * value);
    }
};