class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;

        long long N = n; 
        if (N < 0) {
            N = -N; 
            x = 1 / x;
        }

        double half = myPow(x, N / 2);

        if (N % 2 == 0) return half * half;

        return half * half * x;
    }
};