class Solution {
public:
    int m;
    int n;

    int solve(int i , int j , vector<vector<int>> &grid , int k , vector<vector<vector<int>>> &dp) {
        if(i >= m || j >= n) return INT_MIN;

        if(k < 0) return INT_MIN;

        if(i == m - 1 && j == n - 1) {
            if(grid[i][j] == 0) {
                return grid[i][j];
            }
            else {
                if(k - 1 >= 0) {
                    return grid[i][j];
                }
                else {
                    return INT_MIN;
                }
            }
        }

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int right = INT_MIN;
        int down = INT_MIN;

        if(grid[i][j] == 0) {
            right = solve(i , j+1 , grid , k , dp);
            down = solve(i+1 , j , grid , k , dp);
        }
        else if(grid[i][j] == 1){
            right = 1 + solve(i , j+1 , grid , k-1 , dp);
            down = 1 + solve(i+1 , j , grid , k-1 , dp);
        }
        else {
            right = 2 + solve(i , j+1 , grid , k-1 , dp);
            down = 2 + solve(i+1 , j , grid , k-1 , dp);
        }

        return dp[i][j][k] = max(right , down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(m+1 , vector<vector<int>>(n+1 , vector<int>(k+1 , -1)));

        int ans = solve(0 , 0 , grid , k , dp);

        return (ans < 0) ? -1 : ans;
    }
};