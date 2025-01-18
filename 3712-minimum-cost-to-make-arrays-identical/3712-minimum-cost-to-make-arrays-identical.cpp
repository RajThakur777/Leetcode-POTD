class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        if(arr == brr) return 0;

        int n = arr.size();

        long long diff2 = 0;
        for(int i=0; i<n; i++){
            diff2 += abs(arr[i] - brr[i]);
        }

        sort(arr.begin() , arr.end());
        sort(brr.begin() , brr.end());

        long long diff = 0;
        for(int i=0; i<n; i++){
            diff += abs(arr[i] - brr[i]);
        }
        return min(diff + k , diff2);
    }
};