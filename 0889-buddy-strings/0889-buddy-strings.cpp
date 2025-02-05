class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;

        if(s == goal){
            unordered_set<char> st;
            for(int i=0; i<s.size(); i++){
                if(st.count(s[i])) return true;

                st.insert(s[i]);
            }
            return false;
        }
        
        int f1 = -1;
        int se = -1;
        for(int i=0; i<s.size(); i++){
            if(s[i] != goal[i]){
                if(f1 == -1){
                    f1 = i;
                }
                else if(se == -1){
                    se = i;
                }
                else {
                    return false;
                }
            }
        }
        return se != -1 && s[f1] == goal[se] && s[se] == goal[f1];
    }
};