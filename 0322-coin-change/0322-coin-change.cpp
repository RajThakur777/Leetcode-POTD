// //Recursion:
// class Solution {
// public:
//     int n;

//     int solve(int idx , vector<int> &coins , int amount) {
//         if(idx < 0 || amount < 0) return 1e9;

//         if(idx == 0) {
//             if(amount % coins[idx] == 0) {
//                 return (amount / coins[idx]);
//             }
//             else {
//                 return 1e9;
//             }
//         }

//         int not_pick = solve(idx-1 , coins , amount);

//         int pick = 1e9;
//         if(coins[idx] <= amount) {
//             pick = 1 + solve(idx , coins , amount-coins[idx]);
//         }

//         return min(pick , not_pick);
//     }

//     int coinChange(vector<int>& coins, int amount) { 
//         n = coins.size();

//         int ans = solve(n-1 , coins , amount);

//         if(ans == 1e9) return -1;

//         return ans;
//     }
// };





// //Recursion+Memoization:
// class Solution {
// public:
//     int n;
//     int dp[13][10001];

//     int solve(int idx , vector<int> &coins , int amount) {
//         if(idx < 0 || amount < 0) return 1e9;

//         if(idx == 0) {
//             if(amount % coins[idx] == 0) {
//                 return (amount / coins[idx]);
//             }
//             else {
//                 return 1e9;
//             }
//         }

//         if(dp[idx][amount] != -1) return dp[idx][amount];

//         int not_pick = solve(idx-1 , coins , amount);

//         int pick = 1e9;
//         if(coins[idx] <= amount) {
//             pick = 1 + solve(idx , coins , amount-coins[idx]);
//         }

//         return dp[idx][amount] = min(pick , not_pick);
//     }

//     int coinChange(vector<int>& coins, int amount) { 
//         n = coins.size();

//         memset(dp , -1 , sizeof(dp));

//         int ans = solve(n-1 , coins , amount);

//         if(ans == 1e9) return -1;

//         return ans;
//     }
// };






//Tabulation:
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) { 
        int n = coins.size();

        vector<vector<int>> dp(n+1 , vector<int>(amount+1));

        for(int i=0; i<=n; i++) {
            dp[i][0] = 0;
        }

        for(int t=0; t<=amount; t++) {
            dp[0][t] = ((amount % coins[0]) == 0 ? (amount / coins[0]) : 1e9);
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=amount; j++) {
                int not_pick = dp[i-1][j];

                int pick = 1e9;

                if(j >= coins[i-1]) {
                    pick = 1 + dp[i][j-coins[i-1]];
                }
                dp[i][j] = min(pick , not_pick);
            }
        }
        return dp[n][amount] == 1e9 ? -1 : dp[n][amount];
    }
};