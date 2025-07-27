class Solution {
public:
    int m;
    int n;

    bool dfs(int i , int j , vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) return true;

        grid2[i][j] = 0;

        bool res = (grid1[i][j] == 1);

        res = res & dfs(i-1 , j , grid1 , grid2);
        res = res & dfs(i+1 , j , grid1 , grid2);
        res = res & dfs(i , j-1 , grid1 , grid2);
        res = res & dfs(i , j+1 , grid1 , grid2);

        return res;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();

        int cnt = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid2[i][j] == 1 && dfs(i , j , grid1 , grid2)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};