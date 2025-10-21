//Recursion+Memoization:
class Solution {
public:
    int dp[50001];

    int solve(int idx , vector<int> &stoneValue) {
        if(idx == stoneValue.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        dp[idx] = stoneValue[idx] - solve(idx + 1 , stoneValue);

        if(idx + 1 < stoneValue.size()) {
            dp[idx] = max(dp[idx] , stoneValue[idx] + stoneValue[idx + 1] - solve(idx + 2 , stoneValue));
        }

        if(idx + 2 < stoneValue.size()) {
            dp[idx] = max(dp[idx] , stoneValue[idx] + stoneValue[idx + 1] + stoneValue[idx + 2] - solve(idx + 3 , stoneValue));
        }
        return dp[idx];
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        memset(dp , -1 , sizeof(dp));

        int diff = solve(0 , stoneValue);

        if(diff < 0) {
            return "Bob";
        }
        else if(diff == 0) {
            return "Tie";
        }
        else {
            return "Alice";
        }
    }
};