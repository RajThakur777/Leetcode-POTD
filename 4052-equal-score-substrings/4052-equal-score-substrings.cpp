class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();

        for(int i=0; i<n-1; i++) {
            int s1 = 0;
            for(int j=0; j<=i; j++) {
                s1 += (s[j] - 'a' + 1);
            }

            int s2 = 0;
            for(int k=i+1; k<n; k++) {
                s2 += (s[k] - 'a' + 1);
            }

            if(s1 == s2) return true;
        }
        return false;
    }
};