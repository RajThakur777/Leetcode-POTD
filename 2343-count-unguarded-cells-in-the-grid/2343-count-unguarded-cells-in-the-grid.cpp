class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto& g : guards) grid[g[0]][g[1]] = 2;
        for (auto& w : walls) grid[w[0]][w[1]] = 3;

        for (auto& g : guards) {
            int r = g[0], c = g[1];

            for (int k = c - 1; k >= 0; k--) {
                if (grid[r][k] == 2 || grid[r][k] == 3) break;
                grid[r][k] = 4;
            }
            for (int k = c + 1; k < n; k++) {
                if (grid[r][k] == 2 || grid[r][k] == 3) break;
                grid[r][k] = 4;
            }
            for (int k = r - 1; k >= 0; k--) {
                if (grid[k][c] == 2 || grid[k][c] == 3) break;
                grid[k][c] = 4;
            }
            for (int k = r + 1; k < m; k++) {
                if (grid[k][c] == 2 || grid[k][c] == 3) break;
                grid[k][c] = 4;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0) ans++;

        return ans;
    }
};
