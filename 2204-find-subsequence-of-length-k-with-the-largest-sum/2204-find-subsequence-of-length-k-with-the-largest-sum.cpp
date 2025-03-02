class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<pair<int , int>> p;
        for(int i=0; i<n; i++){
            p.push_back({nums[i] , i});
        }

        unordered_set<int> st;

        sort(rbegin(p) , rend(p));

        for(auto [val , idx] : p){
            if(!k--) break;

            st.insert(idx);
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(st.count(i)){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};