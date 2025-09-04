// //Recursion:
// class Solution {
// public:
//     int n;

//     int child1(vector<vector<int>>& fruits) {
//         int ans = 0;

//         for(int i=0; i<fruits.size(); i++) {
//             ans += fruits[i][i];
//         }
//         return ans;
//     }

//     int child2(vector<vector<int>>& fruits , int i , int j) {
//         if(i >= n || j < 0 || j >= n) return 0;

//         if(i == j || i > j) return 0;

//         int ans1 = fruits[i][j] + child2(fruits , i+1 , j-1);
//         int ans2 = fruits[i][j] + child2(fruits , i+1 , j);
//         int ans3 = fruits[i][j] + child2(fruits , i+1 , j+1);

//         return max({ans1 , ans2 , ans3});
//     }

//     int child3(vector<vector<int>>& fruits , int i , int j) {
//         if(i < 0 || i >= n || j >= n) return 0;

//         if(i == j || i < j) return 0;

//         int ans1 = fruits[i][j] + child3(fruits , i-1 , j+1);
//         int ans2 = fruits[i][j] + child3(fruits , i , j+1);
//         int ans3 = fruits[i][j] + child3(fruits , i+1 , j+1);

//         return max({ans1 , ans2 , ans3});
//     }

//     int maxCollectedFruits(vector<vector<int>>& fruits) {  
//         n = fruits.size();    

//         int first = child1(fruits);
//         int second = child2(fruits , 0 , n-1);
//         int third = child3(fruits , n-1 , 0);

//         return first + second + third;
//     }
// };





//Recursion+Memoization:
class Solution {
public:
    int n;
    int dp[1001][1001];

    int child1(vector<vector<int>>& fruits) {
        int ans = 0;

        for(int i=0; i<fruits.size(); i++) {
            ans += fruits[i][i];
            dp[i][i] = 0;
        }
        return ans;
    }

    int child2(vector<vector<int>>& fruits , int i , int j) {
        if(i >= n || j < 0 || j >= n) return 0;

        if(i == j || i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans1 = fruits[i][j] + child2(fruits , i+1 , j-1);
        int ans2 = fruits[i][j] + child2(fruits , i+1 , j);
        int ans3 = fruits[i][j] + child2(fruits , i+1 , j+1);

        return dp[i][j] = max({ans1 , ans2 , ans3});
    }

    int child3(vector<vector<int>>& fruits , int i , int j) {
        if(i < 0 || i >= n || j >= n) return 0;

        if(i == j || i < j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans1 = fruits[i][j] + child3(fruits , i-1 , j+1);
        int ans2 = fruits[i][j] + child3(fruits , i , j+1);
        int ans3 = fruits[i][j] + child3(fruits , i+1 , j+1);

        return dp[i][j] = max({ans1 , ans2 , ans3});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {  
        n = fruits.size(); 

        memset(dp , -1 , sizeof(dp));   

        int first = child1(fruits);
        int second = child2(fruits , 0 , n-1);
        int third = child3(fruits , n-1 , 0);

        return first + second + third;
    }
};