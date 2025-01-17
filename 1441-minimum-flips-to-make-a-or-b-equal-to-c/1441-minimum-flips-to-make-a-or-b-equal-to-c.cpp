class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;

        for(int i=0; i<=30; i++){
            int bit_A = (a & (1 << i)) != 0 ? 1 : 0;
            int bit_B = (b & (1 << i)) != 0 ? 1 : 0;
            int bit_C = (c & (1 << i)) != 0 ? 1 : 0;

            if(bit_A == 0 && bit_B == 0 && bit_C == 1){
                cnt++;
            }
            else if(bit_C == 0 && bit_A == 1 && bit_B == 1){
                cnt += 2;
            }
            else if(bit_A == 1 && bit_B == 1 && bit_C == 0){
                cnt += 2;
            }
            else if((bit_A == 0 && bit_B == 1 && bit_C == 0) || (bit_A == 1 && bit_B == 0 && bit_C == 0)){
                cnt++;
            }
        }
        return cnt;
    }
};