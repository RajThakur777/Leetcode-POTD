class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) { 
        vector<vector<int>> grid(n+1 , vector<int>(n+1 , INT_MAX));

        for(int i=1; i<n; i++) {
            grid[i][i+1] = 1;
            grid[i+1][i] = 1;
        }

        grid[x][y] = 1;
        grid[y][x] = 1;

        for(int via=1; via<=n; via++) {
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    if((grid[i][via] < INT_MAX) && (grid[via][j]) < INT_MAX) {
                        grid[i][j] = min(grid[i][j] , grid[i][via] + grid[via][j]);
                    }
                }
            }
        }

        vector<int> res(n);

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i != j) {
                    int value = grid[i][j];
                    res[value - 1]++;
                }
            }
        }
        return res;
    }
};