// class Solution {
// public:
//     int tupleSameProduct(vector<int>& nums) {   
//         int n = nums.size();

//         map<int , int> mpp;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 mpp[(nums[i] * nums[j])]++;
//             }
//         }

//         int cnt = 0;
//         for(auto it : mpp){
//             int res = ((it.second) * (it.second - 1) ) / 2;

//             cnt += (res) * 8;
//         }
//         return cnt;
//     }
// };





class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {   
        int n = nums.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                mpp[(nums[i] * nums[j])]++;
            }
        }

        int cnt = 0;
        for(auto it : mpp){
            if(it.second >= 2){
                int res = ((it.second) * (it.second - 1) ) / 2;

               cnt += (res) * 8;
            }
        }
        return cnt;
    }
};