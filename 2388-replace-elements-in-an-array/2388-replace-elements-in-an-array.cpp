class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n = operations.size();

        map<int , int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]] = i;
        }

        for(int i=0; i<n; i++){
            int idx = mpp[operations[i][0]]; 

            mpp.erase(operations[i][0]);

            nums[idx] = operations[i][1];

            mpp[operations[i][1]] = idx; 
        }
        return nums;
    }
};