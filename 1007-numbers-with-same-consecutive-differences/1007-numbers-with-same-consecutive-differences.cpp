class Solution {
public:

    void helper(int num , int lastDigit , int n , int k , int idx , vector<int> &res){
        if(idx == n){
            res.push_back(num);
            return;
        }

        //try all digits
        for(int i=0; i<10; i++){
            if(abs(i - lastDigit) == k){
                helper(num * 10 + i , i , n , k , idx + 1 , res);
            }
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) { 
        vector<int> res;

        for(int i=1; i<=9; i++){
            helper(i , i , n , k , 1 , res);
        }
        return res;
    }
};