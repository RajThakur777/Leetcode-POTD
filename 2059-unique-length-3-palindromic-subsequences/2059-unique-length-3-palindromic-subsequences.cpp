class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int cnt = 0;
        
        set<char> st;
        for(int i=0; i<s.size(); i++){
            st.insert(s[i]);
        }

        for(auto it : st){
            int i = -1;
            int j = 0;

            for(int k=0; k<s.size(); k++){
                if(s[k] == it){
                    if(i == -1){
                        i = k;
                    }
                    else {
                        j = k;
                    }
                }
            }

            set<char> ans;
            for(int k=i+1; k<j; k++){
                ans.insert(s[k]);
            }

            cnt += ans.size();
        }
        return cnt;
    }
};