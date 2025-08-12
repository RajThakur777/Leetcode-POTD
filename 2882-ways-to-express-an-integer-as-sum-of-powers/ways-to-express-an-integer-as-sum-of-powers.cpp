// //Recursion:
// class Solution {
// public:
//     const int mod = 1e9 + 7;

//     int solve(int num , int n , int x) {
//         if(n == 0) return 1;

//         if(n < 0) return 0;

//         int val = pow(num , x);

//         if(val > n) return 0;

//         int take = solve(num + 1 , n - val , x);
//         int not_take = solve(num + 1 , n , x);

//         return (take + not_take) % mod;
//     }

//     int numberOfWays(int n, int x) {
//         return solve(1 , n , x);
//     }
// };





//Recursion + Memoization:
class Solution {
public:
    const int mod = 1e9 + 7;
    int t[301][301];
    
    int solve(int num , int n , int x) {
        if(n == 0) return 1;

        if(n < 0) return 0;

        int val = pow(num , x);

        if(val > n) return 0;

        if(t[n][num] != -1) return t[n][num];

        int take = solve(num + 1 , n - val , x);
        int not_take = solve(num + 1 , n , x);

        return t[n][num] = (take + not_take) % mod;
    }

    int numberOfWays(int n, int x) {
        memset(t , -1 , sizeof(t));

        return solve(1 , n , x);
    }
};