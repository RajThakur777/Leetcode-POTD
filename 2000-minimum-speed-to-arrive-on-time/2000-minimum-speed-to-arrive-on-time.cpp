class Solution {
public:

    bool isPossible(int mid , vector<int>& dist , double hour){
        double ans = 0.0;

        for(int i=0; i<dist.size(); i++){
            double t = (double)(dist[i]) / (double)(mid);

            if(i == dist.size() - 1){
                ans += (t);
            }
            else {
                ans += ceil(t);
            }
        }
        return ans <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();

        int ans = -1;

        int low = 1;
        int high = 1e7;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(isPossible(mid , dist , hour)){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};