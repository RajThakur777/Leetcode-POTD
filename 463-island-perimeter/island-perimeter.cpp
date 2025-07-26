class Solution {
public:
    int m;
    int n;

    int dfs(int i , int j , vector<vector<int>>& grid , vector<vector<bool>> &visited) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 1;

        if(visited[i][j]) return 0;

        visited[i][j] = true;

        int cnt = 0;
        
        cnt += dfs(i-1 , j , grid , visited);
        cnt += dfs(i+1 , j , grid , visited);
        cnt += dfs(i , j-1 , grid , visited);
        cnt += dfs(i , j+1 , grid , visited);

        return cnt;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m , vector<bool> (n , false));

        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    ans += dfs(i , j , grid , visited);
                }
            }
        }
        return ans;
    }
};