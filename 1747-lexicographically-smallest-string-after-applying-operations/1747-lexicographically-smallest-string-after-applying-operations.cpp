class Solution {
public:
    string res;

    void solve(string s , int a , int b , unordered_set<string> &st) {
        if(st.find(s) != st.end()) {
            return;
        }
        st.insert(s);

        res = min(res , s);

        string ans = s;

        //op1:
        for(int i=0; i<ans.size(); i++) {
            if(i % 2 != 0) {
                ans[i] = (((ans[i] - '0') + a) % 10) + '0';
            }
        }
        solve(ans , a , b , st);

        //op2:
        string str = s.substr(b) + s.substr(0 , b);

        solve(str , a , b , st);
    }

    string findLexSmallestString(string s, int a, int b) {  
        int n = s.size(); 

        res = string(s.size(), '9');

        unordered_set<string> st;

        solve(s , a , b , st);

        return res;
    }
};