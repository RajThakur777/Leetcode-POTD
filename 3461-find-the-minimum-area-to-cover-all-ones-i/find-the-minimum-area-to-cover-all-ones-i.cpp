class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int miniRow = m;
        int maxiRow = -1;
        int miniCol = n;
        int maxiCol = -1;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    miniRow = min(miniRow , i);
                    maxiRow = max(maxiRow , i);

                    miniCol = min(miniCol , j);
                    maxiCol = max(maxiCol , j);
                }
            }
        }
        return (maxiRow - miniRow + 1) * (maxiCol - miniCol + 1);
    }
};