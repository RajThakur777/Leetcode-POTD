// //Brute force:
// class Solution {
// public:
//     int maxScore(string s) {   
//         int n = s.size();

//         int maxScore = INT_MIN;

//         for(int i=0; i<n-1; i++){
//             int zero = 0;
//             int one = 0;

//             for(int left=0; left<=i; left++){
//                 if(s[left] == '0'){
//                     zero++;
//                 }
//             }

//             for(int right=i+1; right<=n; right++){
//                 if(s[right] == '1'){
//                     one++;
//                 }
//             }
//             maxScore = max(maxScore , zero + one);
//         }
//         return maxScore;
//     }
// };









//Optimised:
class Solution {
public:
    int maxScore(string s) {   
        int n = s.size();

        int ones = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1') ones++;
        }

        int zeroes = 0;
        int ans = INT_MIN;

        for(int i=0; i<n-1; i++){
            if(s[i] == '1'){
                ones--;
            }
            else {
                zeroes++;
            }

            ans = max(ans , zeroes + ones);
        }
        return ans;
    }
};