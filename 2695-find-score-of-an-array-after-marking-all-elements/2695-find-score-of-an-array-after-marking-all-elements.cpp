class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        long long ans = 0;
        for(int i=0; i<n; i++){
            pq.push({nums[i] , i});
        }

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int val = it.first;
            int ind = it.second;

            if(nums[ind] != -1){
                ans += val;
                nums[ind] = -1;

                if(ind > 0){
                    nums[ind - 1] = -1;
                }

                if(ind + 1 < n){
                    nums[ind + 1] = -1;
                }
            }
        }
        return ans;
    }
};