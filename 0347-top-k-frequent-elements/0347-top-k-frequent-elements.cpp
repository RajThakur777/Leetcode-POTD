class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) { 
        int n = nums.size();

        vector<int> ans;

        map<int , int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }

        vector<pair<int , int>> p;
        for(auto it : mpp){
            p.push_back({it.second , it.first});
        }

        sort(p.rbegin() , p.rend());

        for(int i=0; i<k; i++){
            ans.push_back(p[i].second);
        }
        return ans;
    }
};