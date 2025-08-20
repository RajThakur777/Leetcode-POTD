class Solution {
public:
    void solve(int idx , int n , int k , vector<string> &res , string &temp) {
        if(idx == n) {
            res.push_back(temp);
            return;
        }

        for(char ch='a'; ch<='c'; ch++) {
            if(temp.empty() || ch != temp.back()) {
                temp.push_back(ch);
                solve(idx+1 , n , k , res , temp);
                temp.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> res;

        string temp;

        solve(0 , n , k , res , temp);

        if(res.size() < k) return "";

        return res[k-1];
    }
};