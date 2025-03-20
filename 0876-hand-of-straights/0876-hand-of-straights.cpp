class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0) return false;

        map<int , int> mpp;
        for(int i=0; i<n; i++){
            mpp[hand[i]]++;
        }

        for(auto [key , value] : mpp){
            while(mpp[key]){
                for(int i=key; i<key+groupSize; i++){
                    mpp[i]--;

                    if(mpp[i] < 0) return false;
                }
            }
        }
        return true;
    }
};