class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();

        int curr = 0;

        int mini = 0;
        int maxi = 0;

        for(int i=0; i<n; i++){
            curr += differences[i];

            mini = min(mini , curr);
            maxi = max(maxi , curr);

            if((upper - maxi) - (lower - mini) + 1 <= 0) return 0;
        }
        return (upper - maxi) - (lower - mini) + 1;
    }
};