// //Recursion:
// class Solution {
// public:

//     int helper(int idx , vector<int> &days , vector<int> &costs){
//         int n = days.size();

//         if(idx >= days.size()) return 0;

//         //take - 1
//         int cost1 = costs[0] + helper(idx+1 , days , costs);

//         //take - 7
//         int max_days = days[idx] + 7;
//         int j = idx;
//         while(j < n && days[j] < max_days){
//             j++;
//         }

//         int cost7 = costs[1] + helper(j , days , costs);

//         //take - 30
//         int maxi_days = days[idx] + 30;
//         int k = idx;
//         while(k < n && days[k] < maxi_days){
//             k++;
//         }

//         int cost30 = costs[2] + helper(k , days , costs);

//         return min(cost1 , min(cost7 , cost30));
//     }

//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int n = days.size();

//         return helper(0 , days , costs);
//     }
// };




//Memoization:
class Solution {
public:

    int helper(int idx , vector<int> &days , vector<int> &costs , vector<int> &dp){
        int n = days.size();

        if(idx >= days.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        //take - 1
        int cost1 = costs[0] + helper(idx+1 , days , costs , dp);

        //take - 7
        int max_days = days[idx] + 7;
        int j = idx;
        while(j < n && days[j] < max_days){
            j++;
        }

        int cost7 = costs[1] + helper(j , days , costs , dp);

        //take - 30
        int maxi_days = days[idx] + 30;
        int k = idx;
        while(k < n && days[k] < maxi_days){
            k++;
        }

        int cost30 = costs[2] + helper(k , days , costs , dp);

        return dp[idx] = min(cost1 , min(cost7 , cost30));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        vector<int> dp(n , -1);

        return helper(0 , days , costs , dp);
    }
};