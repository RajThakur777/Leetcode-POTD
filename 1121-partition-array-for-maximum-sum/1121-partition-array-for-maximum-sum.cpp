// //Recursion:
// class Solution {
// public:
//     int n;

//     int solve(int i , vector<int> &arr , int k) {
//         if(i >= n) return 0;

//         int curr_maxi = -1;
//         int ans = INT_MIN;

//         for(int j=i; j<n && (j-i+1) <= k; j++) {
//             curr_maxi = max(curr_maxi , arr[j]);

//             ans = max(ans , (((j-i+1) * curr_maxi) + solve(j+1 , arr , k)));
//         }
//         return ans;
//     }

//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         n = arr.size();

//         return solve(0 , arr , k);
//     }
// };




//Recursion+Memoization:
class Solution {
public:
    int n;
    int dp[501];

    int solve(int i , vector<int> &arr , int k) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int curr_maxi = -1;
        int ans = INT_MIN;

        for(int j=i; j<n && (j-i+1) <= k; j++) {
            curr_maxi = max(curr_maxi , arr[j]);

            ans = max(ans , (((j-i+1) * curr_maxi) + solve(j+1 , arr , k)));
        }
        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , arr , k);
    }
};