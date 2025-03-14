class Solution {
public:

    bool isPossible(int mid , vector<int> &piles , int k) {
        long long cnt = 0;

        for(int i=0; i<piles.size(); i++){
            cnt += (ceil(piles[i] * 1.0 / mid));
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