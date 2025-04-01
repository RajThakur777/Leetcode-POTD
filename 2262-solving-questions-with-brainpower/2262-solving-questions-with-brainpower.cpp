// //Recursion:
// class Solution {
// public:

//     long long helper(int i , vector<vector<int>>& questions){
//         if(i >= questions.size()) return 0;

//         //pick
//         long long pick = questions[i][0] + helper(i + questions[i][1] + 1 , questions);

//         //not-pick
//         long long not_pick = helper(i + 1 , questions);

//         return max(pick , not_pick);
//     }

//     long long mostPoints(vector<vector<int>>& questions) {
//         int n = questions.size();

//         long long ans = helper(0 , questions);

//         return ans;
//     }
// };





//Memoization:
class Solution {
public:

    long long helper(int i , vector<vector<int>>& questions , vector<long long> &dp){
        if(i >= questions.size()) return 0;

        if(dp[i] != -1) return dp[i];

        //pick
        long long pick = questions[i][0] + helper(i + questions[i][1] + 1 , questions , dp);

        //not-pick
        long long not_pick = helper(i + 1 , questions , dp);

        return dp[i] = max(pick , not_pick);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long> dp(n , -1);

        long long ans = helper(0 , questions , dp);

        return ans;
    }
};