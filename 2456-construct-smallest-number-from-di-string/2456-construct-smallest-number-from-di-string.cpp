// //Recursion + Backtracking:
// class Solution {
// public:

//     bool helper(int idx , string &pattern , string &curr , vector<bool> &used){
//         if(idx == pattern.size() + 1){
//             return true;
//         }

//         //try every digit:
//         for(int i=1; i<=9; i++){
//             if(used[i] == true) continue;

//             if(idx > 0){
//                 if(pattern[idx-1] == 'I'){
//                     int prevDigit = curr[idx-1] - '0';
//                     if(prevDigit > i) return false;;
//                 }
//                 else {
//                     int prevDigit = curr[idx-1] - '0';
//                     if(prevDigit < i) return false;
//                 }
//             }
           
//             curr[idx] = i + '0'; //DO
//             used[i] = true;
//             if(helper(idx+1 , pattern , curr , used) == true) return true; //EXPLORE
//             used[i] = false; //UNDO
//         }
//         return false;
//     }

//     string smallestNumber(string pattern) { 
//         vector<bool> used(10 , false);

//         string curr(pattern.size() + 1 , '1'); 

//         helper(0 , pattern , curr , used);  

//         return curr;
//     }
// };






//brute force:
class Solution {
public:

    bool matches(string &num , string &pattern){
        for(int i=0; i<pattern.size(); i++){
            if((pattern[i] == 'I' && num[i] > num[i+1]) || (pattern[i] == 'D' && num[i] < num[i+1])){
                return false;
            }
        }
        return true;
    }

    string smallestNumber(string pattern) { 
        int n = pattern.size();

        string num = "";

        for(int i=1; i<=n+1; i++){
            num.push_back(i+'0');
        }

        while(!matches(num , pattern)){
            next_permutation(begin(num) , end(num));
        }
        return num;
    }
};