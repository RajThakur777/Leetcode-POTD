class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<int , vector<int>> mpp;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int key = i-j;

                mpp[key].push_back(grid[i][j]);
            }
        }

        for(auto &it : mpp) {
            int key = it.first;

            if(key >= 0) {
                sort(begin(it.second), end(it.second));
            }
            else {
                sort(rbegin(it.second), rend(it.second));
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int key = i-j;
                grid[i][j] = mpp[key].back();
                mpp[key].pop_back();
            }
        }
        return grid;
    }
};