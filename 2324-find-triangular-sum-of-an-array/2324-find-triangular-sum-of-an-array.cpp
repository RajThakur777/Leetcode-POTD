class Solution {
public:

    vector<int> solve(vector<int> &temp) {
        vector<int> ans;

        for(int i=0; i<temp.size()-1; i++) {
            ans.push_back((temp[i] + temp[i+1]) % 10);
        }
        return ans;
    }

    int triangularSum(vector<int>& nums) { 
        int n = nums.size();

        vector<int> temp = nums;

        while(temp.size() != 1) {
            vector<int> res = solve(temp);
            temp = res;
        }
        return temp[0];
    }
};