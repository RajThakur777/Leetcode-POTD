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

    int countLargestGroup(int n) {
        map<int , int> mpp;   

        for(int i=1; i<=n; i++){
            int val = sumOfDigits(i);

            mpp[val]++;
        }

        int maxi = 0;
        for(auto it : mpp){
            maxi = max(maxi , it.second);
        }

        int ans = 0;
        for(auto it : mpp){
            if(it.second == maxi){
                ans++;
            }
        }
        return ans;
    }
};