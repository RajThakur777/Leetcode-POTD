class Solution {
public:

    int sumOfDigits(int n){
        int sum = 0;
        while(n > 0){
            sum += (n % 10);
            n = n / 10;
        }
        return sum;
    }

    int countBalls(int lowLimit, int highLimit) {
        int n = highLimit - lowLimit + 1;

        unordered_map<int , int> mpp;

        for(int i=lowLimit; i<=highLimit; i++){
            int sum = sumOfDigits(i);

            mpp[sum]++;
        }

        int maxi = 0;
        for(auto it : mpp){
            maxi = max(maxi , it.second);
        }
        return maxi;
    }
};