class Solution {
public:

    bool isPrime(int x) {
        if(x <= 1) return false;

        for(int i=2; i<x; i++) {
            if(x % i == 0) return false;
        }
        return true;
    }
    
    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        bool flag = false;
        for(auto it : mpp) {
            if(isPrime(it.second)) {
                flag = true;
                break;
            }
        }
        if(flag) return true;

        return false;
    }
};