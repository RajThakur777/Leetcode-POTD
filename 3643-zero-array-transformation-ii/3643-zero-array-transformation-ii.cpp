class Solution {
public:
    bool isPossible(int mid , vector<int>& nums , vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> temp(nums.begin(), nums.end());
        
        vector<int> diff(n , 0);

        for(int i = 0; i <= mid; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diff[l] += val;
            if(r + 1 < n) {
                diff[r + 1] -= val;
            }
        }

        for(int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        for(int i = 0; i < n; i++) {
            if(temp[i] > diff[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                cnt++;
            }
        }

        if(cnt == n) return 0;

        int ans = -1;

        int low = 0;
        int high = queries.size() - 1;  

        while(low <= high) {
            int mid = (low + high) / 2;

            if(isPossible(mid , nums , queries)) {
                ans = mid + 1; 
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
