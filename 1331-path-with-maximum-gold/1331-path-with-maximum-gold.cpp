//Recursion + Backtracking:
class Solution {
public:
    int m;
    int n;

    int solve(int i , int j , vector<vector<int>>& grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;

        int value = 0;

        int temp = grid[i][j];
        grid[i][j] = 0;

        value = max(value , solve(i-1 , j , grid));
        value = max(value , solve(i+1 , j , grid));
        value = max(value , solve(i , j-1 , grid));
        value = max(value , solve(i , j+1 , grid));

        grid[i][j] = temp;

        return value + temp;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = INT_MIN;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    ans = max(ans , solve(i , j , grid));
                }
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};