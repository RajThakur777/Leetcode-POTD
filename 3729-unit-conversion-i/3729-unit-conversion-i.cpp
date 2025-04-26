class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size();

        vector<int> res(n+1);

        map<long long , long long> mpp;

        res[0] = 1;
        
        for(int i=0; i<n; i++){
            if(conversions[i][0] == 0){
                long long val = (conversions[i][2]) % mod;

                res[conversions[i][1]] = val;

                mpp[conversions[i][1]] = val; 
            }
            else {  
                long long val = mpp[conversions[i][0]];

                long long ans = (val * conversions[i][2]) % mod;

                res[conversions[i][1]] = ans;
                
                mpp[conversions[i][1]] = ans;
            }
        }
        return res;
    }
};