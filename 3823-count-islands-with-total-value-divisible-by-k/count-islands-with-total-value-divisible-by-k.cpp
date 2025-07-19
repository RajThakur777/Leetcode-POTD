class Solution {
public:
    #define ll long long 
    
    vector<vector<ll>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
    ll m;
    ll n;
    
    ll dfs(int i , int j , vector<vector<int>>& grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;

        ll sum = grid[i][j];
        grid[i][j] = 0;

        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            sum += dfs(i_ , j_ , grid);
        }
        return sum;
    }
    
    int countIslands(vector<vector<int>>& grid, int k) { 
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        int sum = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] > 0) {
                    sum = dfs(i , j , grid);

                    if(sum % k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};