class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int m = basket1.size();

        int mini = INT_MAX;
        for(int i=0; i<m; i++) {
            mini = min(mini , basket1[i]);
        }

        for(int i=0; i<m; i++) {
            mini = min(mini , basket2[i]);
        }

        unordered_map<int , int> mpp;
        for(int i=0; i<m; i++) {
            mpp[basket1[i]]++;
        }

        for(int i=0; i<m; i++) {
            mpp[basket2[i]]--;
        }

        vector<int> res;
        for(auto it : mpp) {
            int cost = it.first;
            int count = it.second;

            if(count == 0) continue;

            if(count % 2 != 0) return -1;

            for(int i=1; i<=abs(count/2); i++) {
                res.push_back(cost);
            }
        }

        sort(res.begin() , res.end());

        long long ans = 0;
        for(int i=0; i<res.size() / 2; i++) {
            int v = min(res[i] , 2 * mini);
            ans += v;
        }
        return ans;
    }
};