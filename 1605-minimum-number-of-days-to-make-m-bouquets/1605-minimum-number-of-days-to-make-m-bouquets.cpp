class Solution {
public:

    bool isPossible(int mid , vector<int> &bloomDay , int m , int k){
        int cnt = 0;
        int res = 0;

        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                cnt++;
            }
            else {
                cnt = 0;
            }

            if(cnt == k){
                res++;
                cnt = 0;
            }
        }
        return res >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int low = 1;
        int high = *max_element(bloomDay.begin() , bloomDay.end());

        int ans = -1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(mid , bloomDay , m , k)){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};