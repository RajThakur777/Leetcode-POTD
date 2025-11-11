//3D DP Problem:
class Solution {
public:

    int cntOfZeroes(string &str) {
        int cnt = 0;

        for(int i=0; i<str.size(); i++) {
            if(str[i] == '0') {
                cnt++;
            }
        }
        return cnt;
    }

    int cntOfOnes(string &str) {
        int cnt = 0;

        for(int i=0; i<str.size(); i++) {
            if(str[i] == '1') {
                cnt++;
            }
        }
        return cnt;
    }

    int solve(int idx , vector<string> &strs , int m , int n , vector<vector<vector<int>>> &dp) {
        if(idx == strs.size()) return 0;

        if(m < 0 || n < 0) return -1e9;

        if(dp[idx][m][n] != -1) return dp[idx][m][n];

        string s = strs[idx];
        int zeroes = cntOfZeroes(s);
        int ones = cntOfOnes(s);

        int pick = 0;
        if(m >= zeroes && n >= ones) {
            pick = 1 + solve(idx+1 , strs , m-zeroes , n-ones , dp);
        }

        int not_pick = solve(idx+1 , strs , m , n , dp);

        return dp[idx][m][n] = max(pick , not_pick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();

        vector<vector<vector<int>>> dp(sz+1 , vector<vector<int>>(m+1 , vector<int>(n+1 , -1)));

        return solve(0 , strs , m , n , dp);
    }
};