class Solution {
public:

    int cntOfSetBits(int x) {
        return __builtin_popcount(x);
    }

    int smallestNumber(int n) {
        int ans = 0;

        int res = floor(log2(n)) + 1;

        for(int i=n; i<=10000; i++) {
            if(cntOfSetBits(i) == res) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};