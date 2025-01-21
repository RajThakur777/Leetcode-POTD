// class Solution {
// public:

//     int recursion(int i , int j , int m , int n , vector<vector<int>>& obstacleGrid){
//         if(i == m-1 && j == n-1) return 1;

//         if(i >= m || j >= n) return 0;

//         if(obstacleGrid[i][j] == 1) return 0;

//         return recursion(i+1 , j , m , n , obstacleGrid) + recursion(i , j+1 , m , n , obstacleGrid);
//     }

//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) { 
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();

//         return recursion(0 , 0 , m , n , obstacleGrid);
//     }
// };






class Solution {
public:
    int recursion(int i , int j , int m , int n , vector<vector<int>>& obstacleGrid , vector<vector<int>>& dp){
        if(i == m-1 && j == n-1) {
            if(obstacleGrid[i][j] == 1) return 0;

            return 1;
        }

        if(i >= m || j >= n || obstacleGrid[i][j] == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = recursion(i+1 , j , m , n , obstacleGrid , dp) + recursion(i , j+1 , m , n , obstacleGrid , dp);
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

        return recursion(0 , 0 , m , n , obstacleGrid , dp);
    }
};