class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int k=0; k<n; k++){
            vector<int> ans;
            int i = k;
            int j = 0;
            while(i < n && j < n){
                ans.push_back(grid[i][j]);
                i++;
                j++;
            }

            sort(ans.rbegin() , ans.rend());
            int x = 0;
            i = k;
            j = 0;
            while(i < n && j < n){
                grid[i][j] = ans[x++];
                i++;
                j++;
            }
        }

        for(int k=1; k<n; k++){
            vector<int> ans;
            int i = 0;
            int j = k;
            while(i < n && j < n){
                ans.push_back(grid[i][j]);
                i++;
                j++;
            }

            sort(ans.begin() , ans.end());
            i = 0;
            j = k;
            int y = 0;
            while(i < n && j < n){
                grid[i][j] = ans[y++];
                i++;
                j++;
            }
        }
        return grid;
    }
};