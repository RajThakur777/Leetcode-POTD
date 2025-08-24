// //Recursion:
// class Solution {
// public:

//     int solve(int idx , int search_cost , int maxi , int k , int n , int m) {
//         if(idx >= n) {
//             return (search_cost == k);
//         }

//         int res = 0;
//         for(int i=1; i<=m; i++) {
//             if(i > maxi) {
//                 res += solve(idx+1 , search_cost+1 , i , k , n , m);
//             }
//             else {
//                 res += solve(idx+1 , search_cost , maxi , k , n , m);
//             }
//         }
//         return res;
//     }

//     int numOfArrays(int n, int m, int k) {
//         return solve(0 , 0 , -1 , k , n , m);
//     }
// };





//Recursion + Memoization:
class Solution {
public:
    int dp[51][51][101];
    const int mod = 1e9 + 7;

    int solve(int idx , int search_cost , int maxi , int k , int n , int m) {
        if(idx >= n) {
            return (search_cost == k);
        }

        if(dp[idx][search_cost][maxi] != -1) return dp[idx][search_cost][maxi];

        int res = 0;
        for(int i=1; i<=m; i++) {
            if(i > maxi) {
                res = (res + solve(idx+1 , search_cost+1 , i , k , n , m)) % mod;
            }
            else {
                res = (res + solve(idx+1 , search_cost , maxi , k , n , m)) % mod;
            }
        }
        return dp[idx][search_cost][maxi] = res % mod;
    }

    int numOfArrays(int n, int m, int k) {
        memset(dp , -1 , sizeof(dp));

        return solve(0 , 0 , 0 , k , n , m);
    }
};