class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> copy(n);
        for(int i=0; i<n; i++) {
            copy[i] = abs(nums[i]);
        }

        if(n % 2 == 0) {
            sort(copy.rbegin() , copy.rend());

            int v = (n / 2);

            long long ans = 0;

            for(int i=0; i<v; i++) {
                ans += ((copy[i] * copy[i]));
            }

            for(int i=v; i<n; i++) {
                ans -= ((copy[i] * copy[i]));
            }
            return ans;
        }
        else {
            int v = (n / 2) + 1;

            sort(copy.rbegin() , copy.rend());

            long long ans = 0;

            for(int i=0; i<v; i++) {
                ans += ((copy[i] * copy[i]));
            }

            for(int i=v; i<n; i++) {
                ans -= ((copy[i] * copy[i]));
            }
            return ans;
        }
    }
};