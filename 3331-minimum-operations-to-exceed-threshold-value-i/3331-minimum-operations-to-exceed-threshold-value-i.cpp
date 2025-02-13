// class Solution {
// public:
//     int minOperations(vector<int>& nums, int k) {
//         int n = nums.size();

//         int cnt = 0;

//         for(int i=0; i<n; i++){
//             if(nums[i] < k){
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };






class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue <int, vector<int>, greater<int>> pq;

        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }

        int cnt = 0;

        while(pq.top() < k){
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};








