class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , vector<int>> mpp;

        for(int i=0; i<n; i++) {
            mpp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(auto it : mpp) {
            vector<int> arr = it.second;

            if(arr.size() >= 3) {
                for(int i=0; i<arr.size()-2; i++) {
                    int dist = abs(arr[i] - arr[i+1]) + abs(arr[i+1] - arr[i+2]) + abs(arr[i+2] - arr[i]);

                    ans = min(ans , dist);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};