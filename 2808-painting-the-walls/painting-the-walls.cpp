//Recursion + Memoization:
class Solution {
public:
    int dp[501][501];

    int solve(int idx , int walls , vector<int> &cost , vector<int> &time) {
        if(idx >= cost.size() && walls > 0) return 1e9;

        if(walls <= 0) return 0;

        if(dp[idx][walls] != -1) return dp[idx][walls];

        int paint = cost[idx] + solve(idx + 1 , walls - 1 - time[idx] , cost , time);

        int not_paint = solve(idx + 1 , walls , cost , time);

        return dp[idx][walls] = min(paint , not_paint);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , n , cost , time);
    }
};