class Solution {
public:

    int solve(int d1 , int d2 , int t) {
        return abs(d2 - d1) + 2 * t;
    }

    int maxDistance(string s, int k) {
        int n = s.size();

        int N = 0;
        int S = 0;
        int E = 0;
        int W = 0;

        int ans = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == 'N') {
                N++;
            }
            else if(s[i] == 'S') {
                S++;
            }
            else if(s[i] == 'E') {
                E++;
            }
            else if(s[i] == 'W'){
                W++;
            }

            int t1 = min({N , S , k});
            int t2 = min({E , W , k - t1});

            ans = max(ans , solve(N , S , t1) + solve(E , W , t2));

        }
        return ans;
    }
};