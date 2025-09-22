// //Recursion:
// class Solution {
// public:
//     int n;

//     int solve(int idx , vector<int>& satisfaction , int time) {
//         if(idx >= n) return 0;

//         int pick = (time * satisfaction[idx]) + solve(idx+1 , satisfaction , time+1);

//         int not_pick = solve(idx+1 , satisfaction , time);

//         return max(pick , not_pick);
//     }

//     int maxSatisfaction(vector<int>& satisfaction) {
//         n = satisfaction.size();

//         sort(satisfaction.begin() , satisfaction.end());

//         return solve(0 , satisfaction , 1);
//     }
// };





// //Recursion+Memoization:
// class Solution {
// public:
//     int n;
//     int dp[501][501];

//     int solve(int idx , vector<int>& satisfaction , int time) {
//         if(idx >= n) return 0;

//         if(dp[idx][time]) {
//             return dp[idx][time];
//         }

//         int pick = (time * satisfaction[idx]) + solve(idx+1 , satisfaction , time+1);

//         int not_pick = solve(idx+1 , satisfaction , time);

//         return dp[idx][time] = max(pick , not_pick);
//     }

//     int maxSatisfaction(vector<int>& satisfaction) {
//         n = satisfaction.size();

//         sort(satisfaction.begin() , satisfaction.end());

//         memset(dp , 0 , sizeof(dp));

//         return solve(0 , satisfaction , 1);
//     }
// };





//Tabulation:
class Solution {
public:
        int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int idx = n-1; idx >=0; idx--){
            for(int prev = idx; prev >=0; prev--){
                int pick = satisfaction[idx] * (prev+1) + dp[idx+1][prev+1];

                int notPick = dp[idx+1][prev];
                
                dp[idx][prev] = max(pick, notPick);
            }
        }
        return dp[0][0];
    }
};