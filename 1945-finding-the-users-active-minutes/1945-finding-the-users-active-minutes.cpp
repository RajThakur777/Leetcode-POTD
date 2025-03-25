class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        int n = logs.size();

        map<int , set<int>> mpp;

        for(int i=0; i<n; i++){
            mpp[logs[i][0]].insert(logs[i][1]);
        }

        vector<int> res(k);

        for(auto it : mpp){
            if(it.second.size() <= k){
                res[it.second.size() - 1]++;
            }
        }
        return res;
    }
};