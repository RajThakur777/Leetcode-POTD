class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int n = piles.size();

        for(int i=0; i<n; i++){
            pq.push(piles[i]);
        }

        while(k > 0){
            int val = pq.top();
            pq.pop();

            pq.push(val - floor(val / 2));
            k--;
        }   

        int ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};