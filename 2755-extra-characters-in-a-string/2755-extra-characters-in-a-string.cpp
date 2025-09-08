// //Recursion:
// class Solution {
// public:
//     int n;

//     int solve(int i , string s , unordered_set<string> &st) {
//         if(i >= n) return 0;

//         int mini = 1 + solve(i+1 , s , st);

//         for(int j=i; j<n; j++) {
//             string res = s.substr(i , j-i+1);

//             if(st.find(res) != st.end()) {
//                 mini = min(mini , solve(j+1 , s , st));
//             }
//         }
//         return mini;
//     }

//     int minExtraChar(string s, vector<string>& dictionary) {
//         n = s.size();

//         unordered_set<string> st;
//         for(auto it : dictionary) {
//             st.insert(it);
//         }

//         return solve(0 , s , st);
//     }
// };




// //Recursion+Memoization:
// class Solution {
// public:
//     int n;
//     int dp[51];

//     int solve(int i , string s , unordered_set<string> &st) {
//         if(i >= n) return 0;

//         if(dp[i] != -1) return dp[i];

//         int mini = 1 + solve(i+1 , s , st);

//         for(int j=i; j<n; j++) {
//             string res = s.substr(i , j-i+1);

//             if(st.find(res) != st.end()) {
//                 mini = min(mini , solve(j+1 , s , st));
//             }
//         }
//         return dp[i] = mini;
//     }

//     int minExtraChar(string s, vector<string>& dictionary) {
//         n = s.size();

//         memset(dp , -1 , sizeof(dp));

//         unordered_set<string> st;
//         for(auto it : dictionary) {
//             st.insert(it);
//         }

//         return solve(0 , s , st);
//     }
// };





//Tabulation:
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1 + dp[i + 1];

            for (int j = i; j < n; j++) {
                string str = s.substr(i, j - i + 1);

                if (st.count(str)) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};