// //Recursion:
// class Solution {
// public:

//     bool solve(int i , int j , vector<int> &piles , int alice , int bob , int flag) {
//         if(i > j) {
//             return (alice > bob);
//         }

//         bool alice_first = false;
//         bool alice_last = false;

//         bool bob_first = false;
//         bool bob_last = false;

//         if(flag == 0) {
//             alice_first = solve(i+1 , j , piles , alice+piles[i] , bob , 1);
//             alice_last = solve(i , j-1 , piles , alice+piles[j] , bob , 1);
//         }
//         else {
//             bob_first = solve(i+1 , j , piles , alice , bob+piles[i] , 0);
//             bob_last = solve(i , j-1 , piles , alice , bob+piles[j] , 0);
//         }

//         return alice_first || alice_last || bob_first || bob_last;
//     }

//     bool stoneGame(vector<int>& piles) {
//         int n = piles.size();

//         int alice = 0;
//         int bob = 0;

//         return solve(0 , n-1 , piles , alice , bob , 0);
//     }
// };





//Recursion+Memoization:
class Solution {
public:
    int dp[501][501][2];

    bool solve(int i , int j , vector<int> &piles , int alice , int bob , int flag) {
        if(i > j) {
            return (alice > bob);
        }

        if(dp[i][j][flag] != -1) return dp[i][j][flag];

        bool alice_first = false;
        bool alice_last = false;

        bool bob_first = false;
        bool bob_last = false;

        if(flag == 0) {
            alice_first = solve(i+1 , j , piles , alice+piles[i] , bob , 1);
            alice_last = solve(i , j-1 , piles , alice+piles[j] , bob , 1);
        }
        else {
            bob_first = solve(i+1 , j , piles , alice , bob+piles[i] , 0);
            bob_last = solve(i , j-1 , piles , alice , bob+piles[j] , 0);
        }

        return dp[i][j][flag] = alice_first || alice_last || bob_first || bob_last;
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        memset(dp , -1 , sizeof(dp));

        int alice = 0;
        int bob = 0;

        return solve(0 , n-1 , piles , alice , bob , 0);
    }
};