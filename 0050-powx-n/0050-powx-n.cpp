class Solution {
public:

    double power(double x , int n){
        if(n == 0) return 1;

        double temp = power(x , n/2);
        if(n % 2 != 0){
            return temp * temp * x;
        }
        return temp * temp;
    }

    double myPow(double x, int n) {
        return (n < 0 ? power(1/x , n) : power(x , n));
    }
};