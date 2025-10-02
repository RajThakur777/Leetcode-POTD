// //Recursion:
// class Solution {
// public:
//     int n;

//     int solve(int idx , int buy , vector<int> prices , int fee) {
//         if(idx == n) return 0;

//         int profit = 0;

//         if(buy == 1) {
//             profit = max(-prices[idx] + solve(idx+1 , 0 , prices , fee) , solve(idx+1 , 1 , prices , fee));
//         }
//         else {
//             profit = max(prices[idx] - fee + solve(idx+1 , 1 , prices , fee) , solve(idx+1 , 0 , prices , fee));
//         }
//         return profit;
//     }

//     int maxProfit(vector<int>& prices, int fee) {
//         n = prices.size();

//         return solve(0 , 1 , prices , fee);
//     }
// };





// class Solution {
// public:
//     int n;

//     int solve(int idx , int buy , vector<int> prices , int fee , vector<vector<int>> &dp) {
//         if(idx == n) return 0;

//         if(dp[idx][buy] != -1) return dp[idx][buy];

//         int profit = 0;

//         if(buy == 1) {
//             profit = max(-prices[idx] + solve(idx+1 , 0 , prices , fee , dp) , solve(idx+1 , 1 , prices , fee , dp));
//         }
//         else {
//             profit = max(prices[idx] - fee + solve(idx+1 , 1 , prices , fee , dp) , solve(idx+1 , 0 , prices , fee , dp));
//         }
//         return dp[idx][buy] = profit;
//     }

//     int maxProfit(vector<int>& prices, int fee) {
//         n = prices.size();

//         vector<vector<int>> dp(n, vector<int>(2, -1));

//         return solve(0 , 1 , prices , fee , dp);
//     }
// };




//Tabulation:
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n+1 , vector<int>(2, 0));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                int profit = 0;

                if(buy == 1) {
                   profit = max(-prices[i] + dp[i+1][0] , dp[i+1][1]);
                }
                else {
                   profit = max(prices[i] - fee + dp[i+1][1] , dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
