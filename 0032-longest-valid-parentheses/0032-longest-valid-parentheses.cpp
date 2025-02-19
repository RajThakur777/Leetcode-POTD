class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        stack<int> idx;
        stack<int> st;

        idx.push(-1);

        int i = 0;
        int ans = 0;
        
        while(i < n){
            if(s[i] == '('){
                st.push('(');
                idx.push(i);
            }
            else {
                if(!st.empty()){ 
                    st.pop();
                    idx.pop();
                    ans = max(ans , i-idx.top());  
                }
                else {
                    idx.push(i);
                }
            }
            i++;
        }
        return ans;
    }
};