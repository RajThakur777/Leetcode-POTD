class Solution {
public:
    int n;

    int dp[101][101][2];

    int solve(int idx , vector<int> &piles , int M , int turn) {
        if(idx >= n) return 0;

        if(dp[idx][M][turn] != -1) return dp[idx][M][turn];

        int ans = (turn == 0) ? -1 : INT_MAX;

        int stones = 0;

        for(int x=1; x<=min(2*M , n-idx); x++) {
            stones += piles[idx+x-1];

            if(turn == 0) {
                ans = max(ans , stones + solve(idx+x , piles , max(M , x) , 1));
            }
            else {
                ans = min(ans , solve(idx+x , piles , max(M , x) , 0));
            }
        }
        return dp[idx][M][turn] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , piles , 1 , 0);
    }
};