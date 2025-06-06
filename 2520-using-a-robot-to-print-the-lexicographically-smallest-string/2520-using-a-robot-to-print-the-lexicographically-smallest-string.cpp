class Solution {
public:

    char low(vector<int> & freq){  
        
        for(int i=0;i<26;i++){
            if(freq[i]!=0)return 'a'+i;
        } 
        return 'a';   
    }

    string robotWithString(string s) {
        int n = s.size();

        stack<char> st;

        string ans = "";

        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }

        for(int i=0; i<n; i++){
            st.push(s[i]);
            freq[s[i] - 'a']--;

            while(!st.empty() && st.top() <= low(freq)) {
                ans += st.top();
                st.pop();
            }
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};