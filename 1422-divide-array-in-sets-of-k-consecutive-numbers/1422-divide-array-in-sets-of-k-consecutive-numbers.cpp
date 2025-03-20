class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();

        if((n % k) != 0) return false;

        map<int , int> mpp;

        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }

        for(auto[key , value] : mpp){
            while(mpp[key]){
                for(int i=key; i<key+k; i++){
                    mpp[i]--;

                    if(mpp[i] < 0) return false;
                }
            }
        }
        return true;
    }
};