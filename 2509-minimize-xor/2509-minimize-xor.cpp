class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = __builtin_popcount(num2);
        int bits = (int)log2(num1) + 1;

        int x = 0;

        for(int i=bits; i>=0; i--){
            if(((num1 & (1 << i)) > 0) && setBits > 0){
                x |= (1 << i);
                setBits--;
            }
            else {
                continue;
            }
            if(setBits == 0) break;
        }

        for(int i=0; i<=30; i++){
            if((x & (1 << i)) == 0 && setBits > 0){
                x |= (1 << i);
                setBits--;
            }
            if(setBits == 0) break;
        }

        return x;
    }
};