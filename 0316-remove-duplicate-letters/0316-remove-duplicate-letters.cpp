class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();  

        vector<bool> vis(26 , false);
        vector<int> last(26);

        for(int i=0; i<n; i++){
            last[(s[i] - 'a')] = i;
        } 

        string res = "";

        for(int i=0; i<n; i++){
            if(vis[s[i] - 'a']) continue;

            while(res.size() > 0 && res.back() > s[i] && last[res.back() - 'a'] > i){
                vis[res.back() - 'a'] = false;
                res.pop_back();
            }

            res += s[i];
            vis[s[i] - 'a'] = true;
        }
        return res;
    }
};