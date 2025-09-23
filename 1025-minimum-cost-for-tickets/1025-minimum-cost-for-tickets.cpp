// //Recursion:
// class Solution {
// public:
//     int n;

//     int solve(int day , set<int> &st , vector<int> &costs , vector<int> &days) {
//         if(day > days[n-1]) return 0;

//         if(st.find(day) == st.end()) {
//             return solve(day+1 , st , costs , days);
//         }

//         int one = costs[0] + solve(day+1 , st , costs , days);
//         int seven = costs[1] + solve(day+7 , st , costs , days);
//         int thirty = costs[2] + solve(day+30 , st , costs , days);

//         return min({one , seven , thirty});
//     }

//     int mincostTickets(vector<int>& days, vector<int>& costs) { 
//         n = days.size();

//         set<int> st;
//         for(int i=0; i<n; i++) {
//             st.insert(days[i]);
//         }

//         return solve(1 , st , costs , days);     
//     }
// };




// //Recursion+Memoization:
// class Solution {
// public:
//     int n;
//     int dp[366];

//     int solve(int day , set<int> &st , vector<int> &costs , vector<int> &days) {
//         if(day > days[n-1]) return 0;

//         if(dp[day] != -1) return dp[day];

//         if(st.find(day) == st.end()) {
//             return solve(day+1 , st , costs , days);
//         }

//         int one = costs[0] + solve(day+1 , st , costs , days);
//         int seven = costs[1] + solve(day+7 , st , costs , days);
//         int thirty = costs[2] + solve(day+30 , st , costs , days);

//         return dp[day] = min({one , seven , thirty});
//     }

//     int mincostTickets(vector<int>& days, vector<int>& costs) { 
//         n = days.size();

//         memset(dp , -1 , sizeof(dp));

//         set<int> st;
//         for(int i=0; i<n; i++) {
//             st.insert(days[i]);
//         }

//         return solve(1 , st , costs , days);     
//     }
// };




//Tabulation:
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, 0);
        
        int i = 0;
        for (int day = 1; day <= lastDay; day++) {
            if (day < days[i]) {
                dp[day] = dp[day - 1];
            } else {
                i++;
                dp[day] = min({dp[day - 1] + costs[0],
                               dp[max(0, day - 7)] + costs[1],
                               dp[max(0, day - 30)] + costs[2]});
            }
        }
     
        return dp[lastDay];
    }
};