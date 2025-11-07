class Solution {
public:

    bool isExists(const string& a, const string& b) {
        if (b.size() > a.size()) return false;
        return a.substr(0, b.size()) == b;
    }

    static bool cmp(const string& a, const string& b) {
        return a.size() < b.size();
    }

    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";

        sort(strs.begin(), strs.end(), cmp);
        string comp = strs[0];
        string ans = "";

        for (int i = 0; i < comp.size(); i++) {
            string res = comp.substr(0, i + 1);
            bool allMatch = true;

            for (int j = 0; j < n; j++) {
                if (!isExists(strs[j], res)) {
                    allMatch = false;
                    break;
                }
            }

            if (allMatch)
                ans = res; 
            else
                break; 
        }

        return ans;
    }
};
