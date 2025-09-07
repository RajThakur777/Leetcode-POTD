// //Recursion:
// class Solution {
// public:
//     long long n;

//     long long solve(int idx , vector<vector<int>>& questions) {
//         if(idx >= n) return 0;

//         long long pick = questions[idx][0] + solve(idx+questions[idx][1]+1 , questions);

//         long long not_pick = solve(idx+1 , questions);

//         return max(pick , not_pick);
//     }

//     long long mostPoints(vector<vector<int>>& questions) {
//         n = questions.size();

//         return solve(0 , questions);
//     }
// };




// //Recursion+Memoization:
// class Solution {
// public:
//     long long n;

//     long long solve(int idx , vector<vector<int>>& questions , vector<long long> &dp) {
//         if(idx >= n) return 0;

//         if(dp[idx] != -1) return dp[idx];

//         long long pick = questions[idx][0] + solve(idx+questions[idx][1]+1 , questions , dp);

//         long long not_pick = solve(idx+1 , questions , dp);

//         return dp[idx] = max(pick , not_pick);
//     }

//     long long mostPoints(vector<vector<int>>& questions) {
//         n = questions.size();

//         vector<long long> dp(n , -1);

//         return solve(0 , questions , dp);
//     }
// };





//Tabulation:
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long n = questions.size();

        vector<long long> dp(200001 , 0);

        for(int i=n-1; i>=0; i--) {
            dp[i] = max(questions[i][0] + dp[i + questions[i][1] + 1] , dp[i+1]);
        }
        return dp[0];
    }
};