class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();

        vector<vector<int>> result;

        map<int , vector<int>> mpp;

        for(int i=0; i<n; i++){
            mpp[groupSizes[i]].push_back(i);
        }

        for(auto it : mpp){
            int val = it.first;
            vector<int> res = it.second;

            vector<int> ans;

            int cnt = 0;
            for(int i=0; i<res.size(); i++){
                cnt++;

                ans.push_back(res[i]);

                if(cnt == val){
                    result.push_back(ans);
                    cnt = 0;
                    ans.clear();
                }
            }
        }
        return result;
    }
};