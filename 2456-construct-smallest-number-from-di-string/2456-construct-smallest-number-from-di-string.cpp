//Recursion + Backtracking:
class Solution {
public:

    bool helper(int idx , string &pattern , string &curr , vector<bool> &used){
        if(idx == pattern.size() + 1){
            return true;
        }

        //try every digit:
        for(int i=1; i<=9; i++){
            if(used[i] == true) continue;

            if(idx > 0){
                if(pattern[idx-1] == 'I'){
                    int prevDigit = curr[idx-1] - '0';
                    if(prevDigit > i) return false;;
                }
                else {
                    int prevDigit = curr[idx-1] - '0';
                    if(prevDigit < i) return false;
                }
            }

            curr[idx] = i + '0';
            used[i] = true;
            if(helper(idx+1 , pattern , curr , used) == true) return true;
            used[i] = false;
        }
        return false;
    }

    string smallestNumber(string pattern) { 
        vector<bool> used(10 , false);

        string curr(pattern.size() + 1 , '1'); 

        helper(0 , pattern , curr , used);  

        return curr;
    }
};