// //Recursion:
// class Solution {
// public:
//     #define ll long long 

//     ll solve(int idx , vector<int> &coins , int amount) {
//         if(idx >= coins.size()) {
//             return (amount == 0);
//         }

//         if(amount == 0) return 1;

//         ll pick = 0;
//         if(coins[idx] <= amount) {
//             pick = solve(idx , coins , (ll)amount-coins[idx]);
//         }

//         ll not_pick = solve(idx+1 , coins , amount);

//         return pick + not_pick;
//     }

//     int change(int amount, vector<int>& coins) { 
//         return solve(0 , coins , amount);  
//     }
// };




//Recursion+Memoization:
class Solution {
public:
    #define ll long long 

    ll solve(int idx , vector<int> &coins , int amount , vector<vector<int>> &dp) {
        if(idx >= coins.size()) {
            return (amount == 0);
        }

        if(amount == 0) return 1;

        if(dp[idx][amount] != -1) return dp[idx][amount];

        ll pick = 0;
        if(coins[idx] <= amount) {
            pick = solve(idx , coins , (ll)amount-coins[idx] , dp);
        }

        ll not_pick = solve(idx+1 , coins , amount , dp);

        return dp[idx][amount] = pick + not_pick;
    }

    int change(int amount, vector<int>& coins) { 
        int n = coins.size();

        vector<vector<int>> dp(n+1 , vector<int>(amount+1 , -1));

        return solve(0 , coins , amount , dp);  
    }
};