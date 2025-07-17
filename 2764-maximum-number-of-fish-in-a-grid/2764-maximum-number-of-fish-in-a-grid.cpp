//DFS:
class Solution {
public:

    int m,n;
    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    int dfs(int i , int j , vector<vector<int>> &grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;

        int cnt = grid[i][j];
        grid[i][j] = 0;

        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            cnt += dfs(i_ , j_ , grid);
        }
        return cnt;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] > 0) {
                    ans = max(ans , dfs(i , j , grid));
                }
            }
        } 
        return ans;       
    }
};