class Solution {
public:

    bool isPossible(int mid , vector<int> &piles , int k) {
        long long cnt = 0;

        for(int i=0; i<piles.size(); i++){
            cnt += (piles[i] / mid);

            if(piles[i] % mid != 0){
                cnt++;
            }
        }
        return cnt <= k;
    }

    int minEatingSpeed(vector<int>& piles, int h) {   
        int n = piles.size();

        int low = 1;
        int high = *max_element(piles.begin() , piles.end());

        int ans = 0;

        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(mid , piles , h)){
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