// //Recursion:
// class Solution {
// public:

//     int solve(int idx , vector<int> &cost) {
//         if(idx >= cost.size()) return 0;

//         int one = cost[idx] + solve(idx+1 , cost);
//         int two = cost[idx] + solve(idx+2 , cost);

//         return min(one , two);
//     }

//     int minCostClimbingStairs(vector<int>& cost) {
//         return min(solve(0 , cost) , solve(1 , cost));
//     }
// };




//Recursion + Memoization:
class Solution {
public:

    int solve(int idx , vector<int> &cost , vector<int> &dp) {
        if(idx >= cost.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int one = cost[idx] + solve(idx+1 , cost , dp);
        int two = cost[idx] + solve(idx+2 , cost , dp);

        return dp[idx] = min(one , two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n+1 , -1);

        return min(solve(0 , cost , dp) , solve(1 , cost , dp));
    }
};