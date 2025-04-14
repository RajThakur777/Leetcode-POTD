// class Solution {
// public:
//     bool canMakeSubsequence(string str1, string str2) {
//         int m = str1.size();
//         int n = str2.size();

//         int i = 0;
//         int j = 0;

//         while(i < m && j < n){
//             if(str1[i] == str2[j]){
//                 i++;
//                 j++;
//             }
//             else if(str2[j] == (str1[i] - 'a' + 1) % 26 + 'a'){
//                 i++;
//                 j++;
//             }
//             else {
//                 i++;
//             }
//         }

//         if(j == n){
//             return true;
//         }
//         return false;
//     }
// };







class Solution {
 public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0;

        for(int i=0; i<str1.size(); i++){
            if(((str2[j] - str1[i]) + 26)% 26 <= 1){
                j++;
            }
            if(j == str2.size()) return true;
        }
        return false;
    }
};