// //Recursion:
// class Solution {
// public:
//     int n;

//     int solve(int idx , int buy , vector<int> &prices) {
//         if(idx >= n) return 0;

//         int profit = 0;

//         if(buy == 1) {
//             profit = max(-prices[idx] + solve(idx+1 , 0 , prices) , solve(idx+1 , 1 , prices));
//         } 
//         else {
//             profit = max(prices[idx] + solve(idx+2 , 1 , prices) , solve(idx+1 , 0 , prices));
//         }
//         return profit;
//     }

//     int maxProfit(vector<int>& prices) {   
//         n = prices.size();

//         return solve(0 , 1 , prices);
//     }
// };




//Recursion+Memoization:
class Solution {
public:
    int n;

    int solve(int idx , int buy , vector<int> &prices , vector<vector<int>> &dp) {
        if(idx >= n) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;

        if(buy == 1) {
            profit = max(-prices[idx] + solve(idx+1 , 0 , prices , dp) , solve(idx+1 , 1 , prices , dp));
        } 
        else {
            profit = max(prices[idx] + solve(idx+2 , 1 , prices , dp) , solve(idx+1 , 0 , prices , dp));
        }
        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {   
        n = prices.size();

        vector<vector<int>> dp(n+1 , vector<int>(2 , -1));

        return solve(0 , 1 , prices , dp);
    }
};