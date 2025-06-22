class Solution {
public:
    vector<string> divideString(string s, int k, char fill) { 
        int n = s.size();

        vector<string> ans;

        if(n % k == 0) {
            for(int i=0; i<n; i+=k) {
                string str = s.substr(i , k);

                ans.push_back(str);
            }

            return ans;
        }  

        int i;
        for(i=0; i<n; i+=k) {
            string str = s.substr(i , k);

            ans.push_back(str);
        }

        string res = ans[ans.size() - 1];
        int rem = k - res.size();
        ans.pop_back();

        for(int i=0; i<rem; i++) {
            res += fill;
        }
        ans.push_back(res);

        return ans;
    }
};