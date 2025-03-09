class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;

        int n = fruits.size();

        vector<int> visited(n , 0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(fruits[i] <= baskets[j] && visited[i] == 0){
                    visited[i] = 1;
                    baskets[j] = -1;
                    break;
                }
            }
        }

        for(int i=0; i<visited.size(); i++){
            if(visited[i] == 0) cnt++;
        }
        return cnt;
    }
};