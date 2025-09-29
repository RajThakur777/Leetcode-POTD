// //Recursion:
// class Solution {
// public:
//     int n;

//     int solve(int idx , int buy , vector<int> &prices) {
//         if(idx == n) return 0;

//         int profit = INT_MIN;

//         if(buy == 0) {
//             profit = max(-prices[idx] + solve(idx+1 , 1 , prices) , solve(idx+1 , 0 , prices));
//         }
//         else {
//             profit = max(prices[idx] + solve(idx+1 , 0 , prices) , solve(idx+1 , 1 , prices));
//         }
//         return profit;
//     }

//     int maxProfit(vector<int>& prices) {
//         n = prices.size();

//         return solve(0 , 0 , prices);
//     }
// };



//Recursion+Memoization:
class Solution {
public:
    int n;

    int solve(int idx , int buy , vector<int> &prices , vector<vector<int>> &dp) {
        if(idx == n) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = INT_MIN;

        if(buy == 0) {
            profit = max(-prices[idx] + solve(idx+1 , 1 , prices , dp) , solve(idx+1 , 0 , prices , dp));
        }
        else {
            profit = max(prices[idx] + solve(idx+1 , 0 , prices , dp) , solve(idx+1 , 1 , prices , dp));
        }
        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();

        vector<vector<int>> dp(n , vector<int>(2 , -1));

        return solve(0 , 0 , prices , dp);
    }
};