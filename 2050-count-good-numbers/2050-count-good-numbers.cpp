class Solution {
public:
    
    const long long MOD = 1e9 + 7;

    int recursion(long long x , long long y){
        if(y == 0) return 1;

        long long temp = recursion(x , y/2);
        temp *= temp;
        temp %= MOD;

        if((y & 1)){
            return (temp * x) % MOD;
        }
        return temp;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = (n / 2);

        long long ans1 = recursion(5 , even);
        long long ans2 = recursion(4 , odd);

        return (ans1 * ans2) % MOD;
    }
};