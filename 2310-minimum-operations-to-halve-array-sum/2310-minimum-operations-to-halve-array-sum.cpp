class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();

        priority_queue<double> pq;
        double sum = 0.0;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
            sum += nums[i];
        }

        double res = sum;

        int cnt = 0;
        while(res > sum / 2){
            double ans = (pq.top()) / 2;
            pq.pop();
            res -= ans;
            pq.push(ans);
            cnt++;
        }
        return cnt;
    }
};