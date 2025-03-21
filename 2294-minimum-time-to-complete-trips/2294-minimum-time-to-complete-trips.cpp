class Solution {
public:

    bool isPossible(long long mid , vector<int> &time , int totalTrips){
        long long cnt = 0;

        for(int i=0; i<time.size(); i++){
            cnt += (mid / time[i]);
        } 
        return cnt >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {   
        int n = time.size();

        long long low = 1;
        long long high = 1e14;

        long long ans = -1;

        while(low <= high){
            long long mid = (low + high) / 2;

            if(isPossible(mid , time , totalTrips)){
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