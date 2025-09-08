// //DFS:
// class Solution {
// public:
//     int m;
//     int n;

//     vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

//     const int mod = 1e9+7;

//     bool isSafe(int x , int y) {
//         return (x >= 0 && x < m && y >= 0 && y < n);
//     }

//     int dfs(int i , int j , vector<vector<int>>& grid) {
//         int ans = 1;

//         for(auto dir : directions) {
//             int i_ = i + dir[0];
//             int j_ = j + dir[1];

//             if(isSafe(i_ , j_) && grid[i_][j_] > grid[i][j]) {
//                 ans = (ans + dfs(i_ , j_ , grid)) % mod;
//             }
//         }
//         return ans;
//     }

//     int countPaths(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         int ans = 0;

//         for(int i=0; i<m; i++) {
//             for(int j=0; j<n; j++) {
//                 ans += dfs(i , j , grid);
//             }
//         }
//         return ans;
//     }
// };




//DFS+Memoization:
class Solution {
public:
    int m;
    int n;

    int dp[1001][1001];

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    const long long mod = 1e9+7;

    bool isSafe(int x , int y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int dfs(int i , int j , vector<vector<int>>& grid) {
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1;

        for(auto dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(isSafe(i_ , j_) && grid[i_][j_] > grid[i][j]) {
                ans = (ans + dfs(i_ , j_ , grid)) % mod;
            }
        }
        return dp[i][j] = ans;
    }

    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(dp , -1 , sizeof(dp));

        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans = (ans + dfs(i , j , grid)) % mod;
            }
        }
        return ans;
    }
};