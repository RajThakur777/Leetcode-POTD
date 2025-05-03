// class Solution {
// public:
//     int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
//         int n = tops.size();

//         map<int , int> mpp1;
//         for(int i=0; i<n; i++){
//             mpp1[tops[i]]++;
//         }

//         int maxi1 = INT_MIN;
//         int val1 = 0;
//         for(auto it : mpp1){
//             maxi1 = max(maxi1 , it.second);
//         }

//         for(auto it : mpp1){
//             if(it.second == maxi1){
//                 val1 = it.first;
//             }
//         }

//         map<int , int> mpp2;
//         for(int i=0; i<n; i++){
//             mpp2[bottoms[i]]++;
//         }

//         int maxi2 = INT_MIN;
//         int val2 = 0;
//         for(auto it : mpp2){
//             maxi2 = max(maxi2 , it.second);
//         }

//         for(auto it : mpp2){
//             if(it.second == maxi2){
//                 val2 = it.first;
//             }
//         }

//         bool flag1 = true;
//         bool flag2 = true;

//         int cnt1 = 0;
//         for(int i=0; i<n; i++){
//             if(tops[i] != val1){
//                 if(bottoms[i] == val1){
//                     cnt1++;
//                 }
//                 else {
//                     flag1 = false;
//                     break;
//                 }
//             }
//         }

//         int cnt2 = 0;
//         for(int i=0; i<n; i++){
//             if(bottoms[i] != val2){
//                 if(tops[i] == val2){
//                     cnt2++;
//                 }
//                 else {
//                     flag2 = false;
//                     break;
//                 }
//             }
//         }
//         if(!flag1 && !flag2) return -1;

//         if(cnt1 == 0) return cnt2;

//         if(cnt2 == 0) return cnt1;

//         return min(cnt1 , cnt2);
//     }
// };





class Solution {
public:

    int find(vector<int>& tops , vector<int>& bottoms , int val){
        int top = 0;
        int bottom = 0;

        for(int i=0; i<tops.size(); i++){
            if(tops[i] != val && bottoms[i] != val) {
                return -1;
            }
            else if(tops[i] != val){
                top++;
            }
            else if(bottoms[i] != val){
                bottom++;
            }
        }
        return min(top , bottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        int res = INT_MAX;

        for(int i=1; i<=6; i++){
            int ans = find(tops , bottoms , i);

            if(ans != -1){
                res = min(res , ans);
            }
        }
        if(res == INT_MAX) return -1;

        return res;
    }
};