class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int m = encoded.size();

        int n = m + 1;
        
        vector<int> ans(n);

        int xr = 0;
        for(int i=1; i<=n; i++){
            xr = (xr ^ i);
        }

        int val = 0;
        for(int i=1; i<m; i+=2){
            val = val ^ encoded[i];
        }

        ans[0] = (xr ^ val);

        for(int i=1; i<n; i++){
            ans[i] = (ans[i-1] ^ encoded[i-1]);
        }
        return ans;
    }
};