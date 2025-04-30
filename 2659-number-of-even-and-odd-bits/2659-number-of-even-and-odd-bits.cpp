class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd = 0;

        for(int i=0; i<=30; i++){
            if((n & (1 << i)) > 0 && (i % 2 == 0)){
                even++;
            }
            else if((n & (1 << i)) > 0 && (i % 2 == 1)){
                odd++;
            }
        }  
        vector<int> res;

        res.push_back(even);
        res.push_back(odd);

        return res;
    }
};