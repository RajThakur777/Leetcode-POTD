class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;

        priority_queue<pair<int , int>> pq;
        for(int i=0; i<n; i++) {
            pq.push({nums[i] , i});
        }

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> q;
        while(!pq.empty() && k--) {
            auto it  = pq.top();
            pq.pop();

            q.push({it.second , it.first});
        }

        while(!q.empty()) {
            auto it = q.top();
            q.pop();

            ans.push_back(it.second);
        }
        return ans;
    }
};