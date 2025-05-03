class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        map<int , int> mpp1;
        for(int i=0; i<n; i++){
            mpp1[tops[i]]++;
        }

        int maxi1 = INT_MIN;
        int val1 = 0;
        for(auto it : mpp1){
            maxi1 = max(maxi1 , it.second);
        }

        for(auto it : mpp1){
            if(it.second == maxi1){
                val1 = it.first;
            }
        }

        map<int , int> mpp2;
        for(int i=0; i<n; i++){
            mpp2[bottoms[i]]++;
        }

        int maxi2 = INT_MIN;
        int val2 = 0;
        for(auto it : mpp2){
            maxi2 = max(maxi2 , it.second);
        }

        for(auto it : mpp2){
            if(it.second == maxi2){
                val2 = it.first;
            }
        }

        bool flag1 = true;
        bool flag2 = true;

        int cnt1 = 0;
        for(int i=0; i<n; i++){
            if(tops[i] != val1){
                if(bottoms[i] == val1){
                    cnt1++;
                }
                else {
                    flag1 = false;
                    break;
                }
            }
        }

        int cnt2 = 0;
        for(int i=0; i<n; i++){
            if(bottoms[i] != val2){
                if(tops[i] == val2){
                    cnt2++;
                }
                else {
                    flag2 = false;
                    break;
                }
            }
        }
        if(!flag1 && !flag2) return -1;

        if(cnt1 == 0) return cnt2;

        if(cnt2 == 0) return cnt1;

        return min(cnt1 , cnt2);
    }
};