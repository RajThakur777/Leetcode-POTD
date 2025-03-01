class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();

        sort(piles.begin() , piles.end());

        int ops = (n) / 3;

        int cnt = 0;
        int j = n-2;

        int ans = 0;

        while(cnt != ops && j >= 0){
            ans += piles[j];
            j -= 2;
            cnt++;
        }        
        return ans;
    }
};