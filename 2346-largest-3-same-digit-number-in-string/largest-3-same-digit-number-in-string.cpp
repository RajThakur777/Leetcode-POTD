class Solution {
public:
    string largestGoodInteger(string s) { 
        string res = "";
        int n = s.size();

        for(int i=0; i<n-2; i++) {
            if(s[i] == s[i+1] && s[i+1] == s[i+2] && s[i+2] == s[i]) {
                string ans = s.substr(i , 3);

                if(ans > res) {
                    res = ans;
                }
            }
        }  
        return res;
    }
};