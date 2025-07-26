class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int N = conflictingPairs.size();

        long long ans = 0;

        vector<vector<int>> conflictingPoints(n+1);

        for(int i=0; i<N; i++) {
            int a = min(conflictingPairs[i][0] , conflictingPairs[i][1]);
            int b = max(conflictingPairs[i][0] , conflictingPairs[i][1]);

            conflictingPoints[b].push_back(a);
        }

        vector<long long> extra(n+1);

        int maxi = 0;
        int secondmaxi = 0;

        for(int end=1; end<=n; end++) {
            for(auto &it : conflictingPoints[end]) {
                if(it >= maxi) {
                    secondmaxi = maxi;
                    maxi = it;
                }
                else if(it > secondmaxi) {
                    secondmaxi = it;
                }
            }
            ans += end - maxi;
            extra[maxi] += maxi - secondmaxi;
        }
        return ans + *max_element(extra.begin() , extra.end()); 
    }
};