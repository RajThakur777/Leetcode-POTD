//Brute force:
// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         int len = s.size();

//         char seen[128] = {};

//         for (int i = 0; i < len; i++) {
//             char c = s[i];
//             if (!seen[c]) {
//                 for (char s: seen) if (s == t[i]) return false;
//                 seen[c] = t[i];
//             }
//             else if (seen[c] != t[i]) return false;
//         }
//         return true;
//     }
// };







//Optimised Approach:
// class Solution {
//     public:
//     bool isIsomorphic(string s, string t) {
//         char map_s[128] = { 0 };
//         char map_t[128] = { 0 };

//         int len = s.size();
        
//         for (int i = 0; i < len; ++i)
//         {
//             if (map_s[s[i]]!=map_t[t[i]]) return false;
//             map_s[s[i]] = i+1;
//             map_t[t[i]] = i+1;
//         }
//         return true;    
//     }
// };




class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        map<char , int> mpp1;
        map<char , int> mpp2;

        for(int i=0; i<s.size(); i++){
            if(mpp1[s[i]] != mpp2[t[i]]) return false;
            mpp1[s[i]] = i+1;
            mpp2[t[i]] = i+1;
        }
        return true;
    }
};