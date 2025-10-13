class Solution {
public:

    bool isAnagram(string s1 , string s2) {
        sort(s1.begin() , s1.end());
        sort(s2.begin() , s2.end());

        return (s1 == s2);
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        vector<string> ans;

        string prev = "";

        for(int i=0; i<n; i++) {
            if(ans.empty() || !isAnagram(prev , words[i])) {
                ans.push_back(words[i]);
                prev = words[i];
            }
        }
        return ans;
    }
};