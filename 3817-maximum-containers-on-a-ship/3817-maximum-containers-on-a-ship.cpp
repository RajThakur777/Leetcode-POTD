class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int val = n * n;

        int rem = (maxWeight) / w;

        return min(val , rem);
    }
};