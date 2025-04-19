class TopVotedCandidate {
public:
    vector<int> v1,v2;
    vector<int>leaders;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        v1 = persons;
        v2 = times;

        int maxi = 0;
        int leader = -1;

        unordered_map<int , int> mpp;

        for(int i=0; i<v1.size(); i++){
            mpp[v1[i]]++;

            if(mpp[v1[i]] >= maxi){
                leader = v1[i];
                maxi = mpp[v1[i]];
            }

            leaders.push_back(leader);
        }
    }
    
    int q(int t) {
        int idx = upper_bound(v2.begin() , v2.end() , t) - v2.begin();

        return leaders[idx-1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */