class Solution {
public:

    int isPeak(string str) {
        int ans = 0;
        for(int i=1; i<str.size()-1; i++) {
            if((str[i] - '0') > (str[i-1] - '0') && (str[i] - '0') > (str[i+1] - '0')) {
                ans++;
            }
            else if((str[i] - '0') < (str[i-1] - '0') && (str[i] - '0') < (str[i+1] - '0')) {
                ans++;
            }
        }
        return ans;
    }
    
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        int v1 = num1;
        int v2 = num2;
        while(v1 != v2) {
            string str = to_string(v1);

            ans += isPeak(str);
            
            v1++;
        }

        ans += isPeak(to_string(num2));
        return ans;
    }
};