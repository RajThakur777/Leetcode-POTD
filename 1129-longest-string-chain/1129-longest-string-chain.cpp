// //Recursion:
// class Solution {
// public:

//     static bool cmp(string &s1 , string &s2) {
//         return s1.size() < s2.size();
//     }

//     bool isValid(string &prev , string &curr) {
//         int m = prev.size();
//         int n = curr.size();

//         if(m >= n || n-m != 1) return false;

//         int i = 0;
//         int j = 0;

//         while(i < m && j < n) {
//             if(prev[i] == curr[j]) {
//                 i++;
//             }
//             j++;
//         }
//         return i == m;
//     }

//     int solve(int idx , int prev , vector<string>& words) {
//         if(idx >= words.size()) return 0;

//         int take = 0;
//         if(prev == -1 || isValid(words[prev] , words[idx])) {
//             take = 1 + solve(idx+1 , idx , words);
//         }

//         int not_take = solve(idx+1 , prev , words);

//         return max(take , not_take);
//     }

//     int longestStrChain(vector<string>& words) {
//         int n = words.size();

//         sort(words.begin() , words.end() , cmp);

//         return solve(0 , -1 , words);
//     }
// };




// //Recursion + Memoization:
// class Solution {
// public:

//     static bool cmp(string &s1 , string &s2) {
//         return s1.size() < s2.size();
//     }

//     bool isValid(string &prev , string &curr) {
//         int m = prev.size();
//         int n = curr.size();

//         if(m >= n || n-m != 1) return false;

//         int i = 0;
//         int j = 0;

//         while(i < m && j < n) {
//             if(prev[i] == curr[j]) {
//                 i++;
//                 j++;
//             }
//             else {
//                 j++;
//             }
//         }
//         return i == m;
//     }

//     int solve(int idx , int prev , vector<string>& words , vector<vector<int>> &dp) {
//         if(idx >= words.size()) return 0;

//         if(prev != -1 && dp[idx][prev] != -1) return dp[idx][prev];

//         int take = 0;
//         if(prev == -1 || isValid(words[prev] , words[idx])) {
//             take = 1 + solve(idx+1 , idx , words , dp);
//         }

//         int not_take = solve(idx+1 , prev , words , dp);

//         if(prev != -1) {
//             dp[idx][prev] = max(take , not_take);
//         }

//         return max(take , not_take);
//     }

//     int longestStrChain(vector<string>& words) {
//         int n = words.size();

//         sort(words.begin() , words.end() , cmp);

//         vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));

//         return solve(0 , -1 , words , dp);
//     }
// };








//Recursion + Memoization:
class Solution {
public:

    static bool cmp(string &s1 , string &s2) {
        return s1.size() < s2.size();
    }

    bool isValid(string &prev , string &curr) {
        int m = prev.size();
        int n = curr.size();

        if(m >= n || n-m != 1) return false;

        int i = 0;
        int j = 0;

        while(i < m && j < n) {
            if(prev[i] == curr[j]) {
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return i == m;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin() , words.end() , cmp);

        vector<int> dp(n , 1);

        int ans = 1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(isValid(words[j] , words[i])) {
                    dp[i] = max(dp[i] , dp[j] + 1);
                    ans = max(ans , dp[i]);
                }
            }
        }
        return ans;
    }
};