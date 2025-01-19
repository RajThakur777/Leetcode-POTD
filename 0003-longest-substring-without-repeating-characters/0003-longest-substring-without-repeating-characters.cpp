// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) { 
//         int n = s.size();

//         int maxi = 0;
//         int i = 0;

//         map<char , int> mpp;
//         for(int j=0; j<n; j++){
//             mpp[s[j]]++;

//             while(mpp[s[j]] > 1){
//                 mpp[s[i]]--;
//                 i++;
//             }

//             maxi = max(maxi , j - i + 1);
//         }
//         return maxi;
//     }
// };





class Solution {
public:
    int lengthOfLongestSubstring(string s) { 
        int n = s.size();

        int maxi = 0;
        int i = 0;

        map<char , int> mpp;
        for(int j=0; j<n; j++){
            mpp[s[j]]++;

            while(mpp.size() < j - i + 1){
                if(mpp.size() < j - i + 1){
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0) mpp.erase(s[i]);
                    i++;
                }
            }

            if(mpp.size() == j - i + 1){
                maxi = max(maxi , j - i + 1);
            }
        }
        return maxi;
    }
};