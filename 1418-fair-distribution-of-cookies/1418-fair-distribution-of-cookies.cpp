class Solution {
public:
    int n;
    void solve(int idx , vector<int> &children , vector<int> &cookies , int &res , int k) {
        if(idx >= n) {
            res = min(res , *max_element(children.begin() , children.end()));
            return;
        }

        int candy = cookies[idx];
        for(int i=0; i<k; i++) {
            children[i] += candy;
            solve(idx+1 , children , cookies , res , k);
            children[i] -= candy;
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();

        vector<int> children(k , 0);

        int res = INT_MAX;

        solve(0 , children , cookies , res , k);

        return res;
    }
};