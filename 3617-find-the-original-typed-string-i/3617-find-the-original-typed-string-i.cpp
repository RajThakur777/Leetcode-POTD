class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();

        int ans = 1;

        int cnt = 1;
        for(int i=0; i<n-1; i++) {
            if(word[i] == word[i+1]) {
                cnt++;
            }
            else {
                if(cnt > 0) {
                    ans += (cnt - 1);
                    cnt = 1;
                }
            }
        }
        if(cnt > 0) {
            ans += (cnt - 1);
        }
        return ans;
    }
};