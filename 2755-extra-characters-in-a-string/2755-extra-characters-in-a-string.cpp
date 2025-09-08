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




//Recursion+Memoization:
class Solution {
public:
    int n;
    int dp[51];

    int solve(int i , string s , unordered_set<string> &st) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int mini = 1 + solve(i+1 , s , st);

        for(int j=i; j<n; j++) {
            string res = s.substr(i , j-i+1);

            if(st.find(res) != st.end()) {
                mini = min(mini , solve(j+1 , s , st));
            }
        }
        return dp[i] = mini;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();

        memset(dp , -1 , sizeof(dp));

        unordered_set<string> st;
        for(auto it : dictionary) {
            st.insert(it);
        }

        return solve(0 , s , st);
    }
};