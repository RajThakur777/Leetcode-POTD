class Solution {
public:
    int findComplement(int num) {
        long long ans = 0;

        for (long long i = 0; (1LL << i) <= num; i++) {
            if ((num & (1LL << i)) == 0) {
                ans += (1LL << i);
            }
        }

        return ans;
    }
};
