class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {  
        int n = matrix.size();

        int mini = INT_MAX;
        long long sum = 0;
        long long neg = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sum += abs(matrix[i][j]);

                if(matrix[i][j] < 0) neg++;

                mini = min(mini , abs(matrix[i][j]));
            }
        } 

        if(neg % 2 != 0){
            sum -= 2*mini;
        }
        return sum;
    }
};