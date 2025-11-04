class Solution {
public:

    int calculateSum(unordered_map<int , int> mpp , int x) {
        priority_queue<pair<int , int>> pq;
        for(auto it : mpp) {
            pq.push({it.second , it.first});
        }

        if(pq.size() < x) {
            int sum = 0;
            while(!pq.empty()) {
                sum += ((pq.top().second * pq.top().first));
                pq.pop();
            }

            return sum;
        }

        int sum = 0;
        while(x--) {
            sum += ((pq.top().first * pq.top().second));
            pq.pop();
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        vector<int> ans;

        unordered_map<int , int> mpp;

        int i = 0;
        for(int j=0; j<n; j++) {
            mpp[nums[j]]++;

            while((j - i + 1) > k) {
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }
                i++;
            }

            if((j - i + 1) == k) {
                int value = calculateSum(mpp , x);
                ans.push_back(value);
            }
        }
        return ans;
    }
};