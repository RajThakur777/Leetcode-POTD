// //Recursion:
// class Solution {
// public:
//     int n;

//     int solve(int idx , int buy , int cap , vector<int> &prices) {
//         if(idx >= n || cap == 0) {
//             return 0;
//         }

//         int profit = 0;

//         if(buy == 1) {
//             profit = max(-prices[idx] + solve(idx+1 , 0 , cap , prices) , solve(idx+1 , 1 , cap , prices));
//         }
//         else {
//             profit = max(prices[idx] + solve(idx+1 , 1 , cap-1 , prices) , solve(idx+1 , 0 , cap , prices));
//         }
//         return profit;
//     }

//     int maxProfit(int k, vector<int>& prices) {
//         n = prices.size();

//         return solve(0 , 1 , k , prices);
//     }
// };




// //Recursion+Memoization:
// class Solution {
// public:
//     int n;

//     int solve(int idx , int buy , int cap , vector<int> &prices , vector<vector<vector<int>>> &dp) {
//         if(idx >= n || cap == 0) {
//             return 0;
//         }

//         if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

//         int profit = 0;

//         if(buy == 1) {
//             profit = max(-prices[idx] + solve(idx+1 , 0 , cap , prices , dp) , solve(idx+1 , 1 , cap , prices , dp));
//         }
//         else {
//             profit = max(prices[idx] + solve(idx+1 , 1 , cap-1 , prices , dp) , solve(idx+1 , 0 , cap , prices , dp));
//         }
//         return dp[idx][buy][cap] = profit;
//     }

//     int maxProfit(int k, vector<int>& prices) {
//         n = prices.size();

//         vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2 , vector<int>(k+1 , -1)));

//         return solve(0 , 1 , k , prices , dp);
//     }
// };




//Tabulation:
class Solution {
public:
    int maxProfit(int k , vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int i=0; i<=n; i++) {
            for(int buy=0; buy<=1; buy++) {
                dp[i][buy][0] = 0;
            }
        }

        for(int buy=0; buy<=1; buy++) {
            for(int cap=0; cap<=k; cap++) {
                dp[n][buy][cap] = 0;
            }
        }

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=k; cap++) {
                    int profit = 0;

                    if(buy == 1) {
                        profit = max(-prices[i] +  dp[i+1][0][cap] , dp[i+1][1][cap]);
                    }
                    else {
                        profit = max(prices[i] + dp[i+1][1][cap-1] , dp[i+1][0][cap]);
                    }
                    dp[i][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};