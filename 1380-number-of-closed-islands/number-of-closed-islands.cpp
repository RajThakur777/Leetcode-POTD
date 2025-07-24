class Solution {
public:
    int m;
    int n; 

    void dfs(int i , int j , vector<vector<int>> &grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 0) return;

        grid[i][j] = -1;

        dfs(i - 1 , j , grid);
        dfs(i + 1 , j , grid);
        dfs(i , j + 1 , grid);
        dfs(i , j - 1 , grid);
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && (grid[i][j] == 0)) {
                    dfs(i , j , grid);
                }
            }
        }

        int cnt = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    dfs(i , j , grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};