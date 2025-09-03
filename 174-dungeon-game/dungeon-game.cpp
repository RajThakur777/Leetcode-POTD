// //Recursion:
// class Solution {
// public:
//     int m;
//     int n;

//     int solve(int i , int j , vector<vector<int>>& dungeon) {
//         if(i >= m || j >= n) return INT_MAX;

//         if(i == m-1 && j == n-1) return (dungeon[i][j] <= 0 ? abs(dungeon[i][j]) + 1 : 1);

//         int right = solve(i , j+1 , dungeon);
//         int down = solve(i+1 , j , dungeon);

//         return min(right , down) - dungeon[i][j] <= 0 ? 1 : min(right , down) - dungeon[i][j];
//     }

//     int calculateMinimumHP(vector<vector<int>>& dungeon) {
//         m = dungeon.size();
//         n = dungeon[0].size();

//         return solve(0 , 0 , dungeon);
//     }
// };




//Recursion+Memoization:
class Solution {
public:
    int m;
    int n;

    int dp[201][201];

    int solve(int i , int j , vector<vector<int>>& dungeon) {
        if(i >= m || j >= n) return INT_MAX;

        if(i == m-1 && j == n-1) return (dungeon[i][j] <= 0 ? abs(dungeon[i][j]) + 1 : 1);
        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i , j+1 , dungeon);
        int down = solve(i+1 , j , dungeon);

        return dp[i][j] = min(right , down) - dungeon[i][j] <= 0 ? 1 : min(right , down) - dungeon[i][j];
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , 0 , dungeon);
    }
};