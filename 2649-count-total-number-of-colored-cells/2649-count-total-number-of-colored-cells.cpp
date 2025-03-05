// class Solution {
// public:
//     long long coloredCells(long long n) {
//         long long val = (n * n) + (n -1) * (n - 1);

//         return val;
//     }
// };





class Solution {
public:
    long long coloredCells(int n) {
        long long numBlueCells = 1;
        int addend = 4;
        while (--n) {
            numBlueCells += addend;
            addend += 4;
        }
        return numBlueCells;
    }
};