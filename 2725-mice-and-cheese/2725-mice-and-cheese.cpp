class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();

        int sum = 0;
        for(int i=0; i<n; i++){
            sum += reward2[i];
        }

        vector<int> diff;
        for(int i=0; i<n; i++){
            diff.push_back(reward1[i] - reward2[i]);
        }

        sort(diff.rbegin() , diff.rend());

        for(int i=0; i<k; i++){
            sum += diff[i];
        }
        return sum;
    }
};