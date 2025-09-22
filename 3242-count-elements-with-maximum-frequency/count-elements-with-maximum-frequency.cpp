class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int> mpp;

        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        int maxi = INT_MIN;
        for(auto it : mpp) {
            maxi = max(maxi , it.second);
        }

        int cnt = 0;
        for(auto it : mpp) {
            if(it.second == maxi) {
                cnt++;
            }
        }
        return (cnt * maxi);
    }
};