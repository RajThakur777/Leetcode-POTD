class Solution {
public:
    string decodeString(string s) { 
        int n = s.size();

        string ans = "";

        stack<char> st;

        for(int i=0; i<n; i++){
            if(s[i] != ']'){
                st.push(s[i]);
            }
            else {
                string curr = "";

                while(!st.empty() && st.top() != '['){
                    curr = st.top() + curr;
                    st.pop();
                }

                st.pop();

                //extract number:
                string num = "";

                while(!st.empty() && isdigit(st.top())){
                    num = st.top() + num;
                    st.pop();
                }

                int k = stoi(num);

                while(k--){
                    for(int j=0; j<curr.size(); j++){
                        st.push(curr[j]);
                    }
                }
                curr = "";
                num = "";
            }
        }
        while(!st.empty()){
            ans =  st.top() + ans;
            st.pop();
        }
        return ans;
    }
};