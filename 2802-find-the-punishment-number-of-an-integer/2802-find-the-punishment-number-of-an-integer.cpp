//Brute force - Recursion + Backtracking:
// class Solution {
// public:
//     void helper(int idx, string &str, vector<string> &res, vector<vector<string>> &ans) {
//         if (idx == str.size()) {
//             ans.push_back(res); 
//             return;
//         }

//         // Generate all possible partitions
//         for (int i = idx; i < str.size(); i++) {
//             res.push_back(str.substr(idx, i - idx + 1)); 
//             helper(i + 1, str, res, ans); 
//             res.pop_back();
//         }
//     }

//     bool isValid(int i) {
//         int num = i;
//         string str = to_string(i * i);

//         vector<vector<string>> ans;
//         vector<string> res;

//         helper(0, str, res, ans);

//         for (int i = 0; i < ans.size(); i++) {
//             int sum = 0;
//             for (int j = 0; j < ans[i].size(); j++) {
//                 sum += stoi(ans[i][j]); 
//             }
//             if (sum == num) return true;  
//         }

//         return false;
//     }

//     int punishmentNumber(int n) {
//         int sum = 0;

//         for (int i = 1; i <= n; i++) {
//             if (isValid(i)) {
//                 sum += (i * i);  
//             }
//         }
//         return sum; 
//     }
// };






class Solution {
public:

    bool check(string str , int num , int idx , int currSum){
        if(idx == str.size()){
            return currSum == num;
        }

        if(currSum > num) return false;

        for(int j=idx; j<str.size(); j++){
            int val = stoi(str.substr(idx , j-idx+1));
            if(check(str , num , j+1 , currSum + val)){
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;

        for(int i=1; i<=n; i++){
            int sq = i * i;
            int currSum = 0;

            string str = to_string(sq);

            if(check(str , i , 0 , 0)){
                sum += sq;
            }
        }
        return sum;
    }
};

