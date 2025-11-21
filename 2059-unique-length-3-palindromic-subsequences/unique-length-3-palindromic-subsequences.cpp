class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(s[i]);
        }

        int ans = 0;

        for(auto it : st) {
            int ele = it;
            int l = -1;
            int r = -1;

            for(int j=0; j<n; j++) {
                if(s[j] == ele) {
                    l = j;
                    break;
                }
            }

            for(int j=n-1; j>=0; j--) {
                if(s[j] == ele) {
                    r = j;
                    break;
                }
            }

            if(l != -1 && r != -1 && r - l > 1 && l != r) {
                set<int> st2;
                for(int k=l+1; k<=r-1; k++) {
                    st2.insert(s[k]);
                }

                ans += st2.size();
            }
        }
        return ans;
    }
};