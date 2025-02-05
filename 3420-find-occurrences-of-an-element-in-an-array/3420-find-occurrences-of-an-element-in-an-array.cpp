class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();

        map<int , int> mpp;
        int cnt = 1;
        for(int i=0; i<n; i++){
            if(nums[i] == x){
                mpp[cnt] = i;
                cnt++;
            }
        }

        vector<int> ans;
        for(int i=0; i<queries.size(); i++){
            if(mpp.find(queries[i]) != mpp.end()){
                ans.push_back(mpp[queries[i]]);
            }
            else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};