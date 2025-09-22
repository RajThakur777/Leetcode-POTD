// //Recursion:
// class Solution {
// public:
//     int n;

//     int solve(int idx , vector<vector<int>>& piles , int k) {
//         if(k == 0) return 0;

//         if(idx >= piles.size()) return 0;

//         int sz = min(k , (int)piles[idx].size());

//         int not_pick = solve(idx+1 , piles , k);

//         int pick = 0;
//         int ans = INT_MIN;

//         for(int i=0; i<sz; i++) {
//             pick += piles[idx][i];  

//             int val = solve(idx+1 , piles , k - i - 1);

//             ans = max(ans , pick + val);
//         }
//         return max(ans , not_pick);
//     }

//     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//         n = piles.size();

//         return solve(0 , piles , k);
//     }
// };





//Recursion+Memoization:
class Solution {
public:
    int n;
    int dp[1001][2001];

    int solve(int idx , vector<vector<int>>& piles , int k) {
        if(k == 0) return 0;

        if(idx >= piles.size()) return 0;

        if(dp[idx][k] != -1) return dp[idx][k];

        int sz = min(k , (int)piles[idx].size());

        int not_pick = solve(idx+1 , piles , k);

        int pick = 0;
        int ans = INT_MIN;

        for(int i=0; i<sz; i++) {
            pick += piles[idx][i];  

            int val = solve(idx+1 , piles , k - i - 1);

            ans = max(ans , pick + val);
        }
        return dp[idx][k] = max(ans , not_pick);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , piles , k);
    }
};