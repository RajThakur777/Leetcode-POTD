class Solution {
public:
    bool isPrime(long long n) {
        if(n < 2) return false;

        for(int i=2; i*i<=n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
    
    long long splitArray(vector<int>& nums) {
        int n = nums.size();

        vector<long long> a;
        vector<long long> b;

        for(int i=0; i<n; i++) {
            if(isPrime(i)) {
                a.push_back(nums[i]);
            }
            else {
                b.push_back(nums[i]);
            }
        }

        long long s1 = 0;
        long long s2 = 0;

        for(int i=0; i<a.size(); i++) {
            s1 += a[i];
        }

        for(int i=0; i<b.size(); i++) {
            s2 += b[i];
        }

        return abs(s1 - s2);
    }
};