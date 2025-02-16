// //Brute force:
// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         vector<float> v;

//         int n = arr.size();

//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 v.push_back(((float)arr[i] / (float)arr[j]));
//             }
//         }

//         sort(v.begin() , v.end());

//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 if(v[k-1] == (((float)arr[i] / (float)arr[j]))){
//                     return {arr[i] , arr[j]};
//                 }
//             }
//         }
//         return {0 , 1};
//     }
// };







class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double , pair<int , int>>> pq;
        int n = arr.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                double val = ((double)arr[i] / (double)arr[j]);
                pq.push({val , {arr[i] , arr[j]}});

                if(pq.size() > k){
                    pq.pop();
                }
            }
        }
        auto top = pq.top();

        return {top.second.first , top.second.second};
    }
};