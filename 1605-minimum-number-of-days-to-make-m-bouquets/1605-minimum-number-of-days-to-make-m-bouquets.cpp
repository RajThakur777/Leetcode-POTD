class Solution {
public:

    bool isPossible(int mid , vector<int> &bloomDay , int m , int k) {
        int cnt = 0;
        int v = 0;

        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i] <= mid) {
                v++;
            }
            else {
                cnt += ((v / k));
                v = 0;
            }
        }
        cnt += ((v / k));
        return (cnt >= m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int low = *min_element(bloomDay.begin() , bloomDay.end());
        int high = *max_element(bloomDay.begin() , bloomDay.end());

        int ans = -1;

        while(low <= high) {
            int mid = low + ((high - low) / 2);

            if(isPossible(mid , bloomDay , m , k)) {
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