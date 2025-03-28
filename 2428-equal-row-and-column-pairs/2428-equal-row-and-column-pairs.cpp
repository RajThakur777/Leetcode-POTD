class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();   

        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                int k = 0;

                while(k < n && grid[i][k] == grid[k][j]){
                    k++;
                }
                if(k == n) cnt++;
            }
        }
        return cnt;
    }
};