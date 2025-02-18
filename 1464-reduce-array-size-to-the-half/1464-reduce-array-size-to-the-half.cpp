// class Solution {
// public:
//     int minSetSize(vector<int>& arr) {
//         int n = arr.size();

//         map<int , int> mpp;
//         for(int i=0; i<n; i++){
//             mpp[arr[i]]++;
//         }

//         priority_queue<int> pq;

//         for(auto [val , cnt] : mpp){
//             pq.push(cnt);
//         }

//         int ans = 0;
//         int sz = (n / 2);

//         while(sz > 0){
//             ans++;
//             sz -= pq.top();
//             pq.pop();
//         }
//         return ans;
//     }
// };





class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++){
            mpp[arr[i]]++;
        }

        priority_queue<int> pq;

        for(auto it : mpp){
            pq.push(it.second);
        }

        int ans = 0;
        int sz = (n / 2);

        while(sz > 0){
            ans++;
            sz -= pq.top();
            pq.pop();
        }
        return ans;
    }
};