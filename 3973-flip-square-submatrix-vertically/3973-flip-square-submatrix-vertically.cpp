class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m  = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < k / 2; ++i) {
            int t = x + i;
            int b = x + k - 1 - i;

            for (int j = 0; j < k; ++j) {
                swap(grid[t][y + j], grid[b][y + j]);
            }
        }
       return grid;
    }
};