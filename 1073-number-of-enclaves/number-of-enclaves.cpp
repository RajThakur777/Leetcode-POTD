class Solution {
public:

    int m;
    int n;

    void dfs1(int i , int j , vector<vector<int>> &grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return;

        grid[i][j] = 0;

        dfs1(i - 1 , j , grid);
        dfs1(i + 1 , j , grid);
        dfs1(i , j - 1 , grid);
        dfs1(i , j + 1 , grid);
    }

     void dfs2(int i , int j , vector<vector<int>> &grid , int &cnt) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return;

        cnt += grid[i][j];

        grid[i][j] = 0;

        dfs2(i - 1 , j , grid , cnt);
        dfs2(i + 1 , j , grid , cnt);
        dfs2(i , j - 1 , grid , cnt);
        dfs2(i , j + 1 , grid , cnt);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && (grid[i][j] == 1)) {
                    dfs1(i , j , grid);
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int cnt = 0;

                if(grid[i][j] == 1) {
                    dfs2(i , j , grid , cnt);

                    ans += cnt;
                }
            }
        }
        return ans;
    }
};