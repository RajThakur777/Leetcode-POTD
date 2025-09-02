// //Recursion:
// class Solution {
// public:
//     int m;
//     int n;

//     #define ll long long 

//     const int mod = 1e9+7;

//     pair<ll , ll> solve(int i , int j , vector<vector<int>>& grid) {
//         if(i == m-1 && j == n-1) return {grid[i][j] , grid[i][j]};

//         ll mini = LLONG_MAX;
//         ll maxi = LLONG_MIN;

//         //Down
//         if(i+1 < m) {
//             auto [downmaxi , downmini] = solve(i+1 , j , grid);
//             maxi = max({maxi , grid[i][j] * downmaxi , grid[i][j] * downmini});
//             mini = min({mini , grid[i][j] * downmaxi , grid[i][j] * downmini});
//         }

//         //Right
//         if(j+1 < n) {
//             auto [rightmaxi , rightmini] = solve(i , j+1 , grid);
//             maxi = max({maxi , grid[i][j] * rightmaxi , grid[i][j] * rightmini});
//             mini = min({mini , grid[i][j] * rightmaxi , grid[i][j] * rightmini});
//         }
//         return {maxi , mini};
//     }

//     int maxProductPath(vector<vector<int>>& grid) {  
//         m = grid.size();
//         n = grid[0].size();

//         auto [maxProd , minProd] = solve(0 , 0 , grid);

//         return (maxProd < 0 ? -1 : maxProd % mod);
//     }
// };





//Recursion+Memoization:
class Solution {
public:
    int m;
    int n;

    #define ll long long 

    const int mod = 1e9+7;

    vector<vector<pair<ll , ll>>> dp;

    pair<ll , ll> solve(int i , int j , vector<vector<int>>& grid) {
        if(i == m-1 && j == n-1) return {grid[i][j] , grid[i][j]};

        if(dp[i][j] != make_pair(LLONG_MIN , LLONG_MAX)) {
            return dp[i][j];
        }

        ll mini = LLONG_MAX;
        ll maxi = LLONG_MIN;

        //Down
        if(i+1 < m) {
            auto [downmaxi , downmini] = solve(i+1 , j , grid);
            maxi = max({maxi , grid[i][j] * downmaxi , grid[i][j] * downmini});
            mini = min({mini , grid[i][j] * downmaxi , grid[i][j] * downmini});
        }

        //Right
        if(j+1 < n) {
            auto [rightmaxi , rightmini] = solve(i , j+1 , grid);
            maxi = max({maxi , grid[i][j] * rightmaxi , grid[i][j] * rightmini});
            mini = min({mini , grid[i][j] * rightmaxi , grid[i][j] * rightmini});
        }
        return dp[i][j] = {maxi , mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {  
        m = grid.size();
        n = grid[0].size();

        dp = vector<vector<pair<ll , ll>>>(m , vector<pair<ll , ll>>(n , {LLONG_MIN , LLONG_MAX}));

        auto [maxProd , minProd] = solve(0 , 0 , grid);

        return (maxProd < 0 ? -1 : maxProd % mod);
    }
};