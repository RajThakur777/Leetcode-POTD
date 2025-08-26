class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int diagonal = 0;

        for(int i=0; i<dimensions.size(); i++) {
            int length = dimensions[i][0];
            int width = dimensions[i][1];

            int dig = (length * length + width * width);
            int a = (length * width);

            if(dig > diagonal) {
                diagonal = dig;
                ans = a;
            }
            else if(dig == diagonal) {
                ans = max(ans , a);
            }
        }
        return ans;
    }
};