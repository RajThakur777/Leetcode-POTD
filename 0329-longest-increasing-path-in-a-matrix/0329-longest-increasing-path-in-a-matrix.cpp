//DFS+Memoization:
class Solution {
public:
    int m;
    int n;

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    int dp[201][201];

    bool isValid(int x , int y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int dfs(int i , int j , vector<vector<int>>& matrix) {
        if(dp[i][j] != -1) return dp[i][j];

        int cnt = 1;

        for(auto dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(isValid(i_ , j_) && matrix[i_][j_] > matrix[i][j]) {
                cnt = max(cnt , 1 + dfs(i_ , j_ , matrix));
            }
        }
        return dp[i][j] = cnt;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        memset(dp , -1 , sizeof(dp));

        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans = max(ans , dfs(i , j , matrix));
            }
        }
        return ans;
    }
};