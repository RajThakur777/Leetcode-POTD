class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n = s.size();

        set<int> st;
        for(int i=0; i<n; i++) st.insert(s[i]);

        map<char , int> mpp;
        for(int i=0; i<n; i++) mpp[s[i]]++;

        for(auto it : mpp){
            if(it.second != (n / st.size())){
                return false;
            }
        }
        return true;
    }
};