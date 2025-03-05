class Solution {
public:
    long long coloredCells(long long n) {
        long long val = (n * n) + (n -1) * (n - 1);

        return val;
    }
};