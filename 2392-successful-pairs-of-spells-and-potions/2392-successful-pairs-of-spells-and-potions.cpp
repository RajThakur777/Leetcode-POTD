class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();

        sort(potions.begin() , potions.end());

        vector<int> ans;

        for(int i=0; i<n; i++){
            long long val = spells[i];

            auto idx = lower_bound(potions.begin() , potions.end() , (success + val - 1) / val);

            ans.push_back(potions.end() - idx);
        }   
        return ans;
    }
};