class Solution {
public:
    int maxDepth(string s) {
        int n = s.size(); 

        int ans = INT_MIN;

        int cnt = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                cnt++;
            }
            else if(s[i] == ')'){
                cnt--;
            }
            ans = max(ans , cnt);
        } 
        return ans;
    }
};