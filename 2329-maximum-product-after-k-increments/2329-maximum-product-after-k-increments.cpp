class Solution {
public:
    int MOD = 1e9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue < int, vector < int > , greater < int >> pq; 

        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }

        while(k--){
            int val = pq.top();
            pq.pop();

            pq.push(val+1);
        }

        long long int res = 1;
        while(!pq.empty()){
            res = (res * pq.top()) % MOD;
            pq.pop();
        }

        return res % MOD;
    }
};