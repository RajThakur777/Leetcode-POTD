// //Recursion:
// class Solution {
// public:

//     int helper(int i , int j , vector<vector<int>>& obstacleGrid){
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();

//         if(i >= m || j >= n || obstacleGrid[i][j] == 1) return 0;

//         if(i == m-1 && j == n-1) return 1;

//         return helper(i+1 , j , obstacleGrid) + helper(i , j+1 , obstacleGrid);
//     }

//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {  
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();

//         return helper(0 , 0 , obstacleGrid); 
//     }
// };




//Memoization:
//Recursion:
class Solution {
public:

    int helper(int i , int j , vector<vector<int>>& obstacleGrid , vector<vector<int>> &dp){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(i >= m || j >= n || obstacleGrid[i][j] == 1) return 0;

        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = helper(i+1 , j , obstacleGrid , dp) + helper(i , j+1 , obstacleGrid , dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {  
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m , vector<int> (n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = -1;
            }
        }

        return helper(0 , 0 , obstacleGrid , dp); 
    }
};