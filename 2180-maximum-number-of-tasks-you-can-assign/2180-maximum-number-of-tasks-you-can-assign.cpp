class Solution {
public:

    bool isPossible(int mid , vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> st(workers.begin() , workers.end());

        for(int i=mid-1; i>=0; i--){
            auto it = st.lower_bound(tasks[i]);

            if(it != st.end()){
                st.erase(it);
            }
            else {
                if(pills <= 0) return false;

                auto it = st.lower_bound(tasks[i] - strength);

                if(it != st.end()){
                    st.erase(it);
                    pills--;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {  
        int n = tasks.size();
        int m = workers.size();

        sort(tasks.begin() , tasks.end());
        sort(workers.begin() , workers.end());

        int low = 0;
        int high = min(n , m);

        int ans = 0;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(isPossible(mid , tasks , workers , pills , strength)){
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};