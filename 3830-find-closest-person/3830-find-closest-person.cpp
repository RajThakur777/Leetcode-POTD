class Solution {
public:
    int findClosest(int x, int y, int z) {
        int v1 = abs(x-z);
        int v2 = abs(y-z);

        if(v1 < v2) {
            return 1;
        }
        else if(v1 > v2) {
            return 2;
        }
        else {
            return 0;
        }
    }
};