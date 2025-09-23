// //Recursion:
// class Solution {
// public:
//     int n;

//     int solve(int idx , vector<int> &coins , int amount) {
//         if(amount == 0) return 1;

//         if(idx < 0 || amount < 0) return 0;

//         if(idx == 0) {
//             return (amount % coins[idx] == 0);
//         }

//         int not_pick = solve(idx-1 , coins , amount);

//         int pick = 0;

//         if(coins[idx] <= amount) {
//             pick = solve(idx , coins , amount-coins[idx]);
//         }

//         return pick + not_pick;
//     }

//     int change(int amount, vector<int>& coins) {
//         n = coins.size();

//         return solve(n-1 , coins , amount);
//     }
// };




//Recursion+Memoization:
class Solution {
public:
    int n;

    int solve(int idx , vector<int> &coins , int amount , vector<vector<int>> &dp) {
        if(amount == 0) return 1;

        if(dp[idx][amount] != -1) return dp[idx][amount];

        if(idx < 0 || amount < 0) return 0;

        if(idx == 0) {
            return (amount % coins[idx] == 0);
        }

        int not_pick = solve(idx-1 , coins , amount , dp);

        int pick = 0;

        if(coins[idx] <= amount) {
            pick = solve(idx , coins , amount-coins[idx] , dp);
        }

        return dp[idx][amount] = pick + not_pick;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();

        vector<vector<int>> dp(n+1 , vector<int>(amount+1 , -1));

        return solve(n-1 , coins , amount , dp);
    }
};