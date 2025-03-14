class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        
        long long ans = 0;

        while(k > 0){
            int maxi = pq.top();
            pq.pop();
            ans += maxi;
            pq.push((int)ceil(maxi / 3.0));
            k--;
        }
        return ans;
    }
};