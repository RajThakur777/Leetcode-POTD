class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();

        long long ans = 1;

        long long a = 0;
        long long b = 0;

        map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[abs(nums[i])] = nums[i];
        }

        vector<int> copy = nums;
        for(int i=0; i<n; i++) {
            copy[i] = abs(copy[i]);
        }

        sort(copy.rbegin() , copy.rend());

        a = mpp[copy[0]];
        b = mpp[copy[1]];

        if(a < 0 && b < 0) {
            ans *= a;
            ans *= b;
            ans *= 1e5;

            return ans;
        }
        else if(a > 0 && b > 0) {
            ans *= a;
            ans *= b;
            ans *= 1e5;

            return ans;
        }
        else if(a < 0) {
            ans *= a;
            ans *= b;
            ans *= (-1e5);

            return ans;
        }
        else {
            ans *= a;
            ans *= b;
            ans *= (-1e5);

            return ans;
        }
    }
};