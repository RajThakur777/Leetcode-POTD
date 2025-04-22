class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();

        vector<int> diff(1002 , 0);
        for(int i=0; i<n; i++){
            int l = trips[i][1];
            int r = trips[i][2];
            int pass = trips[i][0];

            diff[l] += pass;
            diff[r] -= pass;
        }

        for(int i=1; i<=1000; i++){
            diff[i] += diff[i-1];
        }

        bool flag = true;
        for(int i=0; i<diff.size(); i++){
            if(diff[i] > capacity){
                flag = false;
                break;
            }
        }
        return (flag);
    }
};