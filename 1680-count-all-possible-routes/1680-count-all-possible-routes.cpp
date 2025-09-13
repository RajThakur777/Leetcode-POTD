// //Recursion:
// class Solution {
// public:

//     const int mod = 1e9 + 7;
//     int n;

//     int solve(int idx , int finish , int fuel , vector<int> &locations) {
//         if(fuel < 0) return 0;

//         int ans = 0;
//         if(idx == finish) {
//             ans = 1;
//         }

//         for(int i=0; i<n; i++) {
//             if(i != idx) {
//                 int rem = abs(locations[idx] - locations[i]);
//                 ans = (ans + solve(i , finish , fuel-rem , locations)) % mod;
//             }
//         }
//         return ans;
//     }

//     int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
//         n = locations.size();

//         return solve(start , finish , fuel , locations);   
//     }
// };




//Recursion+Memoization:
class Solution {
public:

    const int mod = 1e9 + 7;
    int n;
    int dp[101][201];

    int solve(int idx , int finish , int fuel , vector<int> &locations) {
        if(fuel < 0) return 0;

        int ans = 0;
        if(idx == finish) {
            ans = 1;
        }

        if(dp[idx][fuel] != -1) {
            return dp[idx][fuel];
        }

        for(int i=0; i<n; i++) {
            if(i != idx) {
                int rem = abs(locations[idx] - locations[i]);
                ans = (ans + solve(i , finish , fuel-rem , locations)) % mod;
            }
        }
        return dp[idx][fuel] = ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();

        memset(dp , -1 , sizeof(dp));

        return solve(start , finish , fuel , locations);   
    }
};