//Greedy + stack approach:
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();

        int ans = 0;

        stack<char> st;

        for(int i=0; i<n; i++) {
            if(!st.empty() && x >= y && st.top() == 'a' && s[i] == 'b') {
                st.pop();
                ans += x;
            }
            else if(!st.empty() && y > x && st.top() == 'b' && s[i] == 'a') {
                st.pop();
                ans += y;
            }
            else {
                st.push(s[i]);
            }
        }

        s = "";

        while(!st.empty()) {
            s += st.top();
            st.pop();
        }

        reverse(s.begin() , s.end());

         for(int i=0; i<s.size(); i++) {
            if(!st.empty() && st.top() == 'a' && s[i] == 'b') {
                st.pop();
                ans += x;
            }
            else if(!st.empty() && st.top() == 'b' && s[i] == 'a') {
                st.pop();
                ans += y;
            }
            else {
                st.push(s[i]);
            }
        }
        return ans;
    }
};