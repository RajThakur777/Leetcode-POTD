class Solution {
    int dx[4] = {0 , 0 , 1 , -1};
    int dy[4] = {1 , -1 , 0 , 0};
public:

    int recursion(int r , int c , int cnt , vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == -1){
            return 0;
        } 

        if(grid[r][c] == 2){
            return (cnt == -1);
        }

        int temp = grid[r][c];
        grid[r][c] = -1;
        int ans = 0;

        for(int i=0; i<4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];

            ans += recursion(nr , nc , cnt - 1 , grid);
        }
        grid[r][c] = temp;

        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        int r = 0;
        int c = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    r = i;
                    c = j;
                }

                if(grid[i][j] == 0){
                    cnt++;
                }
            }
        }
        return recursion(r , c , cnt , grid);
    }
};