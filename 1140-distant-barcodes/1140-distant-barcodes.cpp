class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();

        vector<int> res(n , 0);

        unordered_map<int , int> mpp;
        for(int i=0; i<n; i++){
            mpp[barcodes[i]]++;
        }

        priority_queue<pair<int , int>> pq;

        for(auto it : mpp){
            pq.push({it.second , it.first});
        }

        int i = 0;

        while(!pq.empty()){
            pair<int , int> p = pq.top();
            pq.pop();

            int ele = p.second;
            int freq = p.first;

            while(freq > 0){
                if(i >= n) i = 1;
                res[i] = ele;
                freq--;
                i += 2;
            }
        }
        return res;
    }
};