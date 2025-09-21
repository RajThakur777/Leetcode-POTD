// //Recursion:
// class Solution {
// public:
//     int m;
//     int n;

//     int solve(int i , int j1 , int j2 , vector<vector<int>> &grid) {
//         if(i == m-1) {
//             if(j1 == j2) {
//                 return grid[i][j1];
//             }
//             else {
//                 return grid[i][j1] + grid[i][j2];
//             }
//         }

//         int cherry = grid[i][j1];

//         int ans = 0;

//         if(j1 != j2) {
//             cherry += grid[i][j2];
//         } 

//         for(int val1=-1; val1<=1; val1++) {
//             for(int val2=-1; val2<=1; val2++) {
//                 int newRow = i+1;
//                 int newCol1 = j1 + val1;
//                 int newCol2 = j2 + val2;

//                 if(newCol1 >= 0 && newCol1 < n && newCol2 >= 0 && newCol2 < n) {
//                     ans = max(ans , solve(newRow , newCol1 , newCol2 , grid));
//                 }
//             }
//         }
//         return cherry + ans;
//     }

//     int cherryPickup(vector<vector<int>>& grid) { 
//         m = grid.size();
//         n = grid[0].size();

//         return solve(0 , 0 , n-1 , grid);   
//     }
// };




//Recursion+Memoization:
class Solution {
public:
    int m;
    int n;

    int dp[71][71][71];

    int solve(int i , int j1 , int j2 , vector<vector<int>> &grid) {
        if(i == m-1) {
            if(j1 == j2) {
                return grid[i][j1];
            }
            else {
                return grid[i][j1] + grid[i][j2];
            }
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int cherry = grid[i][j1];

        int ans = 0;

        if(j1 != j2) {
            cherry += grid[i][j2];
        } 

        for(int val1=-1; val1<=1; val1++) {
            for(int val2=-1; val2<=1; val2++) {
                int newRow = i+1;
                int newCol1 = j1 + val1;
                int newCol2 = j2 + val2;

                if(newCol1 >= 0 && newCol1 < n && newCol2 >= 0 && newCol2 < n) {
                    ans = max(ans , solve(newRow , newCol1 , newCol2 , grid));
                }
            }
        }
        return dp[i][j1][j2] = cherry + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) { 
        m = grid.size();
        n = grid[0].size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , 0 , n-1 , grid);   
    }
};