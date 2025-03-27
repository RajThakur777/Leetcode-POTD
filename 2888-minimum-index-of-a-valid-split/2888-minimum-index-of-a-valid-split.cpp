class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }

        int ans = 0;
        int freq = 0;
        for(auto it : mpp){
            if(it.second > (n / 2)){
                ans = it.first;
                freq = it.second;
            }
        }

        int val = 0;
        int idx = -1;

        for(int i=0; i<n; i++){
            if(nums[i] == ans){
                val++;
            }

            if(((i+1) / 2) < val && ((n - 1 - i) / 2) < (freq - val)){
                idx = i;
                break;
            }
        }
        if(idx == -1) return -1;

        return idx;
    }
};