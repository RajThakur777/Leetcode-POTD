// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         int n = spells.size();

//         sort(potions.begin() , potions.end());

//         vector<int> ans;

//         for(int i=0; i<n; i++){
//             long long val = spells[i];

//             auto idx = lower_bound(potions.begin() , potions.end() , (success + val - 1) / val);

//             ans.push_back(potions.end() - idx);
//         }   
//         return ans;
//     }
// };





class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();

        sort(potions.begin() , potions.end());

        vector<int> ans;

        for(int i=0; i<n; i++){
            int low = 0;
            int high = potions.size() - 1;

            long long val = spells[i];

            int idx = -1;
            while(low <= high){
                int mid = (low + high) / 2;

                if((potions[mid]) * (val) >= success){
                    idx = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            if(idx == -1) {
                ans.push_back(0);
            }
            else {
                ans.push_back(potions.size() - idx);
            }
        }   
        return ans;
    }
};