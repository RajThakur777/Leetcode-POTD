class Solution {
public:

    bool isPossible(long long  mid , vector<int>&ranks , int cars){
        long long cnt = 0;

        for(int i=0; i<ranks.size(); i++){
            cnt += sqrt((mid) / (ranks[i]));
        }

        return cnt >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();

        long long ans = 0;

        long long low = 1;
        int val = *max_element(ranks.begin() , ranks.end());

        long long high = 1LL * val * cars * cars;

        while(low <= high){
            long long mid = (low + high) / 2;

            if(isPossible(mid , ranks , cars)){
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