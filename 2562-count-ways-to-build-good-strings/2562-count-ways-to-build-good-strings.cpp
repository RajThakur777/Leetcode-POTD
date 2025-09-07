// //Recursion:
// class Solution {
// public:
//     const int mod = 1e9 + 7;
    
//     int solve(int low, int high, int zero, int one , int len) {
//         if(len > high) return 0;

//         bool add = false;

//         if(len >= low && len <= high) {
//             add = true;
//         }

//         //take one
//         int ones = solve(low , high , zero , one , len+one);

//         //take zero
//         int zeroes = solve(low , high , zero , one , len+zero);

//         return (add + ones + zeroes) % mod;
//     }

//     int countGoodStrings(int low, int high, int zero, int one) {
//         return solve(low , high , zero , one , 0);
//     }
// };




//Recursion+Memoization:
class Solution {
public:
    const int mod = 1e9 + 7;
    
    int solve(int low, int high, int zero, int one , int len , vector<int> &dp) {
        if(len > high) return 0;

        if(dp[len] != -1) return dp[len];

        bool add = false;

        if(len >= low && len <= high) {
            add = true;
        }

        //take one
        int ones = solve(low , high , zero , one , len+one , dp);

        //take zero
        int zeroes = solve(low , high , zero , one , len+zero , dp);

        return dp[len] = (add + ones + zeroes) % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1 , -1);

        return solve(low , high , zero , one , 0 , dp);
    }
};