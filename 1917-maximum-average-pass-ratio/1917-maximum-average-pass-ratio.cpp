class Solution {
public:
    typedef pair<double , int> P;

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq;

        for(int i=0; i<n; i++) {
            double curr = (double)classes[i][0] / classes[i][1];
            double new_value = (double)(classes[i][0] + 1) / (classes[i][1] + 1);

            double delta = new_value - curr;
            pq.push({delta , i});
        }

        while(extraStudents--) {
            auto it = pq.top();
            pq.pop();

            int idx = it.second;

            classes[idx][0]++;
            classes[idx][1]++;

            double curr = (double)classes[idx][0] / classes[idx][1];
            double new_value = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1);

            double delta = new_value - curr;

            pq.push({delta , idx});
        }

        double ans = 0.0;
        for(int i=0; i<n; i++) {
            ans += (double)classes[i][0] / classes[i][1];
        }
        return ans / n;
    }
};
