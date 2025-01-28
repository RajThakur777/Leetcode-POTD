//DFS:
class Solution {
public:

    int dfs(int i , int j , vector<vector<int>>& grid , vector<vector<bool>> &visited){
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j]) return 0;

        visited[i][j] = true;

        return grid[i][j] + dfs(i+1 , j , grid , visited) + dfs(i-1 , j , grid , visited) + dfs(i , j+1 , grid , visited) + dfs(i , j-1 , grid , visited);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int res = 0;

        vector<vector<bool>> visited(m , vector<bool> (n , false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] > 0 && !visited[i][j]){
                    res = max(res , dfs(i , j , grid , visited));
                }
            }
        }
        return res;
    }
};