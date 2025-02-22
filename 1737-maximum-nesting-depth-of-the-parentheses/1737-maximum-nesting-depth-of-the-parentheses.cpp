class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();

        stack<char> st;

        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                st.pop();
            }
            ans = max(ans , (int)st.size());
        }
        return ans;
    }
};