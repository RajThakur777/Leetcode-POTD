class Solution {

    #define ll long long
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll n = grid[0].size();

        ll mini = LLONG_MAX;
        ll topSum = accumulate(grid[0].begin() , grid[0].end() , 0LL);

        ll bottomSum = 0;

        for(ll i=0; i<n; i++){
            topSum -= grid[0][i];

            mini = min(mini , max(topSum , bottomSum));

            bottomSum += grid[1][i];
        }
        return mini;
    }
};