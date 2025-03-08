class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();

        int black = 0;
        int res = INT_MIN;

        for(int i=0; i<n; i++){
            if(blocks[i] == 'B'){
                black++;
            }
            else {
                res = max(res , black);
                black = 0;
            }
        }

        if(res >= k) return 0;

        int ans = INT_MAX;

        int white = 0;

        int i = 0;
        for(int j=0; j<n; j++){
            if(blocks[j] == 'W'){
                white++;
            }

            while((j - i + 1) > k){
                if(blocks[i] == 'W'){
                    white--;
                }
                i++;
            }

            if((j - i + 1) == k){
                ans = min(ans , white);
            }
        }
        return ans;
    }
};