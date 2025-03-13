class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {    
        int n = nums.size();

        vector<int> diff(n , 0);

        for(int i=0; i<queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];

            diff[l]++;

            if(r + 1 < n){
                diff[r+1]--;
            }
        }  

        for(int i=1; i<n; i++){
            diff[i] += diff[i-1];
        }

        for(int i=0; i<n; i++){
            if(nums[i] - diff[i] > 0) return false;
        }
        return true;
    }
};