class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();

        map<long long , long long> mpp;

        long long cnt = 0;

        for(int i=0; i<n; i++){
            int rem = hours[i] % 24;
            int val = (24 - rem) % 24;

            if(mpp.find(val) != mpp.end()){
                cnt += mpp[val];
            }
            mpp[rem]++;
        }
        return cnt;
    }
};