class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();

        unordered_set<int> res;
        unordered_set<int> curr;
        unordered_set<int> prev;

        for(int i=0; i<n; i++) {
            for(auto it : prev) {
                curr.insert(arr[i] | it);
                res.insert(arr[i] | it);
            }
            curr.insert(arr[i]);
            res.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return res.size();
    }
};