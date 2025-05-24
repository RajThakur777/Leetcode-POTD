class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();

        vector<int> ans;

        for(int i=0; i<n; i++){
            string str = words[i];

            set<char> st;
            for(int j=0; j<str.size(); j++){
                st.insert(str[j]);
            }

            bool flag = false;
            for(auto it : st){
                if(st.find(x) != st.end()){
                    flag = true;
                    break;
                }
            }

            if(flag){
                ans.push_back(i);
            }
        }
        return ans;
    }
};