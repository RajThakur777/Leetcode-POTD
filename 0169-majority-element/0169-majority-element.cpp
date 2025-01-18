class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }  

        int ans = 0;
        for(auto it : mpp){
            if(it.second > n / 2){
                ans = it.first;
            }
        }
        return ans;
    }
};