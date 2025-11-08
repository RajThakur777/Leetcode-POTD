class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();

        sort(s.begin() , s.end());
        sort(t.begin() , t.end());

        return (s == t);
    }
};