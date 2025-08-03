class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        vector<int> prefixSum(n);
        vector<int> indices(n);

        for(int i=0; i<n; i++) {
            indices[i] = fruits[i][0];
        }

        prefixSum[0] = fruits[0][1];
        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + fruits[i][1];
        }

        int ans = 0;

        for(int d=0; d<=k/2; d++) {
            int remain = k - 2 * d;

            int i = startPos - d;
            int j = startPos + remain;

            int left  = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
            int right = upper_bound(indices.begin(), indices.end(), j) - indices.begin() - 1;

            if(left <= right) {
                int total = prefixSum[right] - (left == 0 ? 0 : prefixSum[left-1]);
                ans = max(ans , total);
            }

            i  = startPos - remain;
            j  = startPos + d;
            
            left  = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
            right = upper_bound(indices.begin(), indices.end(), j) - indices.begin() - 1;

            if(left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                ans = max(ans , total);
            }
        }
        return ans;
    }
};