// class Solution {
// public:

//     int helper(int idx , vector<int> &coins , int amount){
//         if(amount == 0) return 0;

//         if(idx < 0 || amount < 0) return INT_MAX / 2;

//         return min(helper(idx , coins , amount-coins[idx]) + 1 , helper(idx-1 , coins , amount));
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();

//         int ans = helper(n-1 , coins , amount);

//         return (ans >= INT_MAX / 2) ? -1 : ans;
//     }
// };





//Memoization:
class Solution {
public:

    int helper(int idx , vector<int> &coins , int amount , vector<vector<int>> &dp){
        if(amount == 0) return 0;

        if(idx < 0 || amount < 0) return INT_MAX / 2;

        if(dp[idx][amount] != -1) return dp[idx][amount];

        return dp[idx][amount] = min(helper(idx , coins , amount-coins[idx] , dp) + 1 , helper(idx-1 , coins , amount , dp));
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n , vector<int> (amount+1 , -1));

        int ans = helper(n-1 , coins , amount , dp);

        return (ans >= INT_MAX / 2) ? -1 : ans;
    }
};