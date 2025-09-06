// //Recursion:
// class Solution {
// public:
//     int m;
//     int n;

//     int solve(int i , int j , vector<int>& nums1, vector<int>& nums2) {
//         if(i >= m || j >= n) return 0;

//         if(nums1[i] == nums2[j]) {
//             return 1 + solve(i+1 , j+1 , nums1 , nums2);
//         }
//         int p1 = solve(i+1 , j , nums1 , nums2);
//         int p2 = solve(i , j+1 , nums1 , nums2);
//         return max(p1 , p2);
//     }

//     int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {  
//         m = nums1.size();
//         n = nums2.size();

//         return solve(0 , 0 , nums1 , nums2); 
//     }
// };




//Recursion+Memoization:
class Solution {
public:
    int m;
    int n;

    int solve(int i , int j , vector<int>& nums1, vector<int>& nums2 , vector<vector<int>> &dp) {
        if(i >= m || j >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(nums1[i] == nums2[j]) {
            return dp[i][j] = 1 + solve(i+1 , j+1 , nums1 , nums2 , dp);
        }
        int p1 = solve(i+1 , j , nums1 , nums2 , dp);
        int p2 = solve(i , j+1 , nums1 , nums2 , dp);

        return dp[i][j] = max(p1 , p2);
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {  
        m = nums1.size();
        n = nums2.size();

        vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));

        return solve(0 , 0 , nums1 , nums2 , dp); 
    }
};