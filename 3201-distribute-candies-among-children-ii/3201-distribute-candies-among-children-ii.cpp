class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;

        for(int i=0; i<=min(n , limit); i++){
            int p = n - i;
            if(p > 2* limit) continue;

            int sc = min(p , limit);
            p -= sc;
            int th = min(p , limit);

            ans += sc - th + 1;
        }
        return ans;
    }
};