class Solution {
public:

    char solv(vector<int> &vis , unordered_map<char , vector<char>> &mpp , char ch) {
        vis[ch - 'a'] = 1;

        char mini = ch;

        for(char &v : mpp[ch]){
            if(!vis[v - 'a']) {
                mini = min(mini , solv(vis , mpp , v));
            }
        }
        return mini;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();

        string ans;

        unordered_map<char , vector<char>> mpp;
        for(int i=0; i<n; i++){
            mpp[s1[i]].push_back(s2[i]);
            mpp[s2[i]].push_back(s1[i]);
        }

        for(int i=0; i<baseStr.size(); i++){
            char ch = baseStr[i];

            vector<int> vis(26 , 0);

            char mini = solv(vis , mpp , ch);

            ans += mini;
        }
        return ans;
    }
};