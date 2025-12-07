class Solution {
public:
    int countOdds(int low, int high) {
        if(low % 2 == 0 && high % 2 == 0) {
            return (high - low) / 2;
        }
        else if(low % 2 != 0 && high % 2 == 0) {
            low++;
            return (((high - low)) / 2) + 1;           
        }
        else if(low % 2 == 0 && high % 2 != 0) {
            high--;
            return (((high - low)) / 2) + 1;            
        }
        else {
            low++;
            high--;
            return ((high - low) / 2) + 2;
        }
    }
};