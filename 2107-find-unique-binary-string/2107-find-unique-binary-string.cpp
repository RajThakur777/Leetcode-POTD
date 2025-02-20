class Solution {
public:

    void helper(int idx , int n , vector<string>&nums , string &curr , unordered_set<string> &st , string &res){
        if(idx == n){
            if(st.find(curr) == st.end()){
                res = curr;    
            }
            return;
        }

        //take 0;
        curr += '0';
        helper(idx+1 , n , nums , curr , st , res);
        if(!res.empty()) return;
        curr.pop_back();

        //take 1:
        curr += '1';
        helper(idx+1 , n , nums , curr , st , res);
        if(!res.empty()) return;
        curr.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        
        string res = "";

        unordered_set<string> st;
        for(int i=0; i<n; i++) st.insert(nums[i]);


        string curr = "";
        helper(0 , n , nums , curr , st , res);

        return res;
    }
};