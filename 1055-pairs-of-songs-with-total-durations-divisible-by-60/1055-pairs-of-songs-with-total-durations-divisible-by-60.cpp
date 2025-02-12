// //Brute force:
// class Solution {
// public:
//     int numPairsDivisibleBy60(vector<int>& time) {
//         int n = time.size();

//         int cnt = 0;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 if((time[i] + time[j]) % 60 == 0){
//                     cnt++;
//                 }
//             }
//         }   
//         return cnt;
//     }
// };






class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();

        int cnt = 0;

        unordered_map<int , int> mpp;

        for(int i=0; i<n; i++){
            int val = (time[i] % 60);
            int rem = (60 - val) % 60;

            if(mpp.find(rem) != mpp.end()){
                cnt += mpp[rem];
            }
            mpp[val]++;
        }   
        return cnt;
    }
};