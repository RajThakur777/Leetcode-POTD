class Solution {
public:

    int binarySearch(vector<int> &potions , int val , long long success) {
        int l = 0;
        int r = potions.size() - 1;

        int ans = -1;
        while(l <= r) {
            int mid = (l + r) / 2;

            if((long long)val * potions[mid] >= success) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        vector<int> ans(n);

        sort(potions.begin() , potions.end());

        for(int i=0; i<n; i++) {
            int val = spells[i];

            int idx = binarySearch(potions , val , success);

            if(idx == -1) {
                ans[i] = 0;
            }
            else {
                ans[i] = m - idx;
            }
        }
        return ans;
    }
};