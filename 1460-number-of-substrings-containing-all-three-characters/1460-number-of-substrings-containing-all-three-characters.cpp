// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();

//         int ans = 0;

//         int i = 0;
//         map<char , int> mpp;

//         for(int j=0; j<n; j++){
//             mpp[s[j]]++;

//             while(mpp.size() == 3){
//                 ans += (n - j);

//                 if(s[i] == 'a' || s[i] == 'b' || s[i] == 'c') {
//                     mpp[s[i]]--;
                    
//                     if(mpp[s[i]] == 0){
//                         mpp.erase(s[i]);
//                     }
//                 }
//                 i++;
//             }
//         }
//         return ans;
//     }
// };




class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        int result = 0;
        
        vector<int> mp(3, 0); //0 - a, 1 - b, 2 - c

        int i = 0;
        int j = 0;
        while(j < n) {
            char ch = s[j];
            mp[ch-'a']++;

            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
                result += (n - j);

                mp[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return result;   
    }
};