// class Solution {
// public:
//     long long minEnd(int n, int x) {
//         long long res = x;

//         while(--n){
//             res = (res + 1) | x;
//         }
//         return res;
//     }
// };




class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x;

        for(int i=1; i<n; i++){
            num = (num + 1) | x;
        }
        return num;
    }
};