// //Recursion:
// class Solution {
// public:

//     void helper(int idx , int n , vector<string> &ans , string curr , int k){
//         if(idx == n){
//             ans.push_back(curr);
//             return;
//         }

//         for(char ch='a'; ch<='c'; ch++){
//             if(curr.size() > 0 && curr.back() == ch) continue;

//             helper(idx+1 , n , ans , curr+ch , k);
//         }
//     }

//     string getHappyString(int n, int k) {
//         vector<string> ans;

//         helper(0 , n , ans , "" , k);

//         sort(ans.begin() , ans.end());

//         if(ans.size() < k){
//             return "";
//         }
//         return ans[k-1];
//     }
// };






//Recursion + Backtracking:
class Solution {
public:

    void helper(string curr , vector<string> &ans , int n){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }

        //try out every possibilities:
        for(char ch='a'; ch<='c'; ch++){
            if(!curr.empty() && curr.back() == ch) continue;

            //DO
            curr.push_back(ch);

            //EXPLORE
            helper(curr , ans , n);

            //UNDO
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;

        helper("" , ans , n);

        if(ans.size() < k){
            return "";
        }
        return ans[k-1];
    }
};