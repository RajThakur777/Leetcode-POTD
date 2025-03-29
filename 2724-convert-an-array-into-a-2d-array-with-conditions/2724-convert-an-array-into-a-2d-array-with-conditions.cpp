class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<vector<int>> ans;
        vector<int> v;
        for(auto &i: nums){
            mp[i]++;
        }
        unordered_map<int,int> tmp;
        while(!mp.empty()){
            tmp = mp;
            v.clear();
            for(auto &i: tmp){
                mp[i.first]--;
                v.push_back(i.first);
                if(mp[i.first]==0){
                    mp.erase(i.first);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};