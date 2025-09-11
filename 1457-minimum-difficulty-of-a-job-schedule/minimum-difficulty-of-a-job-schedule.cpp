// //Recursion:
// class Solution {
// public:
//     int n;
//     int solve(int idx , vector<int>& jobDifficulty , int days) {
//         //base case:
//         if(days == 1) return *max_element(jobDifficulty.begin() + idx , jobDifficulty.end());

//         int ans = INT_MAX;
//         int sum = INT_MIN;

//         for(int i=idx; i<=n-days; i++) {
//             sum = max(sum , jobDifficulty[i]);
//             ans = min(ans , sum + solve(i+1 , jobDifficulty , days-1));
//         }
//         return ans;
//     }

//     int minDifficulty(vector<int>& jobDifficulty, int d) {
//         n = jobDifficulty.size();

//         if(n < d) return -1;

//         return solve(0 , jobDifficulty , d);
//     }
// };




//Recursion+Memoization:
class Solution {
public:
    int n;
    int dp[301][11];

    int solve(int idx , vector<int>& jobDifficulty , int days) {
        //base case:
        if(days == 1) return *max_element(jobDifficulty.begin() + idx , jobDifficulty.end());

        if(dp[idx][days] != -1) return dp[idx][days];

        int ans = INT_MAX;
        int sum = INT_MIN;

        for(int i=idx; i<=n-days; i++) {
            sum = max(sum , jobDifficulty[i]);
            ans = min(ans , sum + solve(i+1 , jobDifficulty , days-1));
        }
        return dp[idx][days] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();

        if(n < d) return -1;

        memset(dp , -1 , sizeof(dp));
        
        return solve(0 , jobDifficulty , d);
    }
};