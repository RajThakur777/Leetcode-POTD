class Solution {
public:
    string resultingString(string s) {
        int n = s.size();

        stack<char> st;

        for(int i=0; i<n; i++){
            if(!st.empty() && abs(st.top() - s[i]) == 1){
                st.pop();
            }
            else if(!st.empty() && ((st.top() == 'z' && s[i] == 'a') || ((st.top() == 'a' && s[i] == 'z')))){
                st.pop();
            }
            else {
                st.push(s[i]);   
            }
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};