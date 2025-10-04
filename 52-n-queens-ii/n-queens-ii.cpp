class Solution {
public:
    bool is_Safe(int i , int j , vector<vector<char>> &grid) {
        int n = grid.size();

        int row = i;
        int col = j;

        for(int l=row-1; l>=0; l--) {
            if(grid[l][col] == 'Q') {
                return false;
            }
        }

        for(int l=row-1,r=col-1; l>=0 && r>=0; l--,r--) {
            if(grid[l][r] == 'Q') {
                return false;
            }
        }

        for(int l=row-1,r=col+1; l>=0 && r<n; l--,r++) {
            if(grid[l][r] == 'Q') {
                return false;
            }
        }
        return true;
    }

    int solve(int row , vector<vector<char>> &grid) {
        int n = grid.size();

        if(row == n) return 1;

        int ans = 0;

        for(int col=0; col<n; col++) {
            if(is_Safe(row , col , grid)) {
                grid[row][col] = 'Q';
                ans += solve(row+1 , grid);
                grid[row][col] = '.';
            }
        }
        return ans;
    }

    int totalNQueens(int n) {
        vector<vector<char>> grid(n , vector<char>(n));

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                grid[i][j] = '.';
            }
        }

        return solve(0 , grid);
    }
};