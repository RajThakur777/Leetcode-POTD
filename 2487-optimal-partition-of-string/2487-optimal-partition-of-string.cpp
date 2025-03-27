class Solution {
public:
    int partitionString(string s) {
        int n = s.size();

        set<char> st;

        set<char> st2;
        for(int i=0; i<n; i++){
            st2.insert(s[i]);
        }

        if(st2.size() == 1) return n;

        if(st2.size() == n) return 1;

        int cnt = 0;

        for(int j=0; j<n; j++){
            if(st.find(s[j]) != st.end()){
                cnt++;
                st.clear();
                st.insert(s[j]);
            }
            st.insert(s[j]);
        }
        return (cnt + 1);
    }
};