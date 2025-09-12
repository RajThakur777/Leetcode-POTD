// //Recursion:
// class Solution {
// public:
//     const int mod = 1e9 + 7;

//     int solve(int idx , int n , int minProfit , vector<int> &group , vector<int> &profit , int cnt , int ans) {
//         if(idx >= group.size()) {
//             return (cnt <= n && ans >= minProfit);
//         }

//         //take
//         int take = solve(idx+1 , n , minProfit , group , profit , cnt+group[idx] , ans+profit[idx]) % mod;

//         //not_take
//         int not_take = solve(idx+1 , n , minProfit , group , profit , cnt , ans) % mod;

//         return (take + not_take) % mod;
//     }
    
//     int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {  
//         int sz = group.size();

//         int ans = solve(0 , n , minProfit , group , profit , 0 , 0);

//         return (ans % mod);
//     }
// };




//Recursion+Memoization:
class Solution {
public:
    const int mod = 1e9 + 7;

    int dp[101][101][101];

    int solve(int idx , int n , int minProfit , vector<int> &group , vector<int> &profit , int cnt , int ans) {
        if(idx == group.size()) {
            return ans >= minProfit;
        }

        if(dp[idx][cnt][ans] != -1) return dp[idx][cnt][ans];

        //take
        int take = 0;
        if(cnt + group[idx] <= n) {
            take = solve(idx + 1 , n , minProfit , group , profit , cnt + group[idx] , min(ans + profit[idx] , minProfit)) % mod;
        }

        //not_take
        int not_take = solve(idx + 1 , n , minProfit , group , profit , cnt , ans) % mod;

        return dp[idx][cnt][ans] = (take + not_take) % mod;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {  
        int sz = group.size();

        memset(dp , -1 , sizeof(dp));

        int ans = solve(0 , n , minProfit , group , profit , 0 , 0);

        return (ans % mod);
    }
};