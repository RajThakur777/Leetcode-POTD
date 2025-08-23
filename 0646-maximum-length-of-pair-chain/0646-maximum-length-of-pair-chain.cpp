// //Recursion:
// class Solution {
// public:
//     int solve(int idx , int prev , vector<vector<int>>& pairs) {
//         if(idx >= pairs.size()) return 0;

//         int take = 0;
//         if(prev == -1 || pairs[prev][1] < pairs[idx][0]) {
//             take = 1 + solve(idx+1 , idx , pairs);
//         }

//         int not_take = solve(idx+1 , prev , pairs);

//         return max(take , not_take);
//     }

//     int findLongestChain(vector<vector<int>>& pairs) {
//         int n = pairs.size();

//         sort(pairs.begin() , pairs.end());

//         return solve(0 , -1 , pairs);
//     }
// };





// //Recursion + Memoization:
// class Solution {
// public:
//     int solve(int idx , int prev , vector<vector<int>>& pairs , vector<vector<int>> &dp) {
//         if(idx >= pairs.size()) return 0;

//         if(prev != -1 && dp[idx][prev] != -1) return dp[idx][prev];

//         int take = 0;
//         if(prev == -1 || pairs[prev][1] < pairs[idx][0]) {
//             take = 1 + solve(idx+1 , idx , pairs , dp);
//         }

//         int not_take = solve(idx+1 , prev , pairs , dp);

//         if(prev != -1) {
//             dp[idx][prev] = max(take , not_take);
//         }

//         return max(take , not_take);
//     }

//     int findLongestChain(vector<vector<int>>& pairs) {
//         int n = pairs.size();

//         sort(pairs.begin() , pairs.end());

//         vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));

//         return solve(0 , -1 , pairs , dp);
//     }
// };





//Tabulation:
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin() , pairs.end());

        vector<int> dp(n , 1);

        int ans = 1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i] , dp[j] + 1);
                    ans = max(ans , dp[i]);
                }
            }
        }
        return ans;
    }
};