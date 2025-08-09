class Solution {
public:

    void solve(int num , int n , vector<int> &ans) {
        if(num > n) return;

        ans.push_back(num);

        for(int next=0; next<=9; next++) {
            int curr = (num * 10) + next;

            if(curr > n) return;

            solve(curr , n , ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for(int i=1; i<=9; i++) {
            solve(i , n , ans);
        }
        return ans;
    }
};