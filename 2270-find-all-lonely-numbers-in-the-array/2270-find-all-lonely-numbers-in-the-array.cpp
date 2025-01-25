class Solution {
public:
    vector<int> findLonely(vector<int>& v) {
        int n = v.size();

        vector<int> ans;
        map<int , int> mpp;
        for(int i=0; i<n; i++){
            mpp[v[i]]++;
        }

        for(int i=0; i<n; i++){
            if(mpp[v[i]] == 1 && mpp.find(v[i] - 1) == mpp.end() && mpp.find(v[i] + 1) == mpp.end()){
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};