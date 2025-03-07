class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) { 
        vector<vector<int>> ans;

        unordered_map<int , vector<int>> mpp;

        for(int i=0; i<groupSizes.size(); i++){
            mpp[groupSizes[i]].push_back(i);

            if(mpp[groupSizes[i]].size() == groupSizes[i]){
                ans.push_back(mpp[groupSizes[i]]);
                mpp[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};