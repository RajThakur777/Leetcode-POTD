class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> ans;

        vector<int> prefix(n);
        prefix[0] = arr[0];

        for(int i=1; i<n; i++){
            prefix[i] = (prefix[i-1] ^ arr[i]);
        }

        for(int i=0; i<queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];

            if(l == 0){
                ans.push_back(prefix[r]);
            }
            else {
                ans.push_back(prefix[r] ^ prefix[l-1]);
            }
        }
        return ans;
    }
};