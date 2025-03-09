class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        for(int i=0; i<k-1; i++){
            colors.push_back(colors[i]);
        }

        int N = n + (k - 1);

        int cnt = 0;

        int i = 0;

        for(int j=1; j<N; j++){
            if(colors[j] == colors[j-1]){
                i = j;
                continue;
            }

            if((j - i + 1) == k){
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};