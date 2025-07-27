//DFS:
class Solution {
public:
    int m;
    int n;

    bool isPossible(int i , int j , int m , int n , vector<vector<int>> &grid , int originalColor , vector<vector<bool>> &visited) {
        return ((i-1 >= 0 && grid[i-1][j] != originalColor && !visited[i-1][j]) || (j-1 >= 0 && grid[i][j-1] != originalColor && !visited[i][j-1]) || (i+1 <= m-1 && grid[i+1][j] != originalColor && !visited[i+1][j]) || (j+1 <= n-1 && grid[i][j+1] != originalColor && !visited[i][j+1]));
    }

    void dfs(int i , int j , int color , int originalColor , vector<vector<bool>> &visited , vector<vector<int>> &grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] != originalColor) return;

        visited[i][j] = true;

        if((i == 0 || i == m-1 || j == 0 || j == n-1) || (isPossible(i , j , m , n , grid , originalColor , visited))) {
            grid[i][j] = color;
        }

        dfs(i+1 , j , color , originalColor , visited , grid);
        dfs(i-1 , j , color , originalColor , visited , grid);
        dfs(i , j+1 , color , originalColor , visited , grid);
        dfs(i , j-1 , color , originalColor , visited , grid);
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m , vector<bool>(n , false));

        dfs(row , col , color , grid[row][col] , visited , grid);

        return grid;
    }
};