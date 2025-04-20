class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int , int>> v(n);

        for(int i=0; i<nums1.size(); i++){
            v[i] = {nums1[i] , nums2[i]};
        }

        auto lambda = [&](auto &P1, auto &P2) {
            return P1.second > P2.second;
        };
        
        sort(begin(v), end(v), lambda);

        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<=k-1; i++){
            sum += v[i].first;
            pq.push(v[i].first);
        }

        long long ans = sum * v[k-1].second;

        for(int i=k; i<n; i++){
            sum += v[i].first - pq.top();

            pq.pop();

            pq.push(v[i].first);

            ans = max(ans , sum * v[i].second);
        }
        return ans;
    }
};