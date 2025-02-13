class Solution {
public:
    #define ll long long

    int minOperations(vector<int>& nums, int k) {
        ll n = nums.size();  

        priority_queue <ll, vector<ll>, greater<ll>> pq;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }

        ll cnt = 0;

        while(pq.top() < k){
            ll val1 = pq.top();
            pq.pop();
            ll val2 = pq.top();
            pq.pop();

            ll res = val1 * 2 + val2;

            pq.push(res);

            cnt++;
        }
        return cnt;
    }
};