//Tabulation:
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1 , vector<int>(n+1));

        for(int i=0; i<m+1; i++) {
            for(int j=0; j<n+1; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = (i+j);
                }
                else if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        int i = m;
        int j = n;

        string ans;
        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }
            else {
                if(dp[i-1][j] < dp[i][j-1]) {
                    ans.push_back(s1[i-1]);
                    i--;
                }
                else {
                    ans.push_back(s2[j-1]);
                    j--;
                }
            }
        }
        while(i > 0) {
            ans.push_back(s1[i-1]);
            i--;
        }

        while(j > 0) {
            ans.push_back(s2[j-1]);
            j--;
        }

        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};