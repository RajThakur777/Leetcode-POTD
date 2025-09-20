class Router {
public:

    set<vector<int>> st; 
    deque<vector<int>> dq;
    unordered_map<int,deque<int>> mpp; 
    int sz;

    Router(int memoryLimit) {
        sz=memoryLimit;
    }
    
    bool addPacket(int s, int d, int t) {
        if(st.count({s,d,t})) return false;

        if(dq.size()==sz){
            auto it=dq.front();

            dq.pop_front();
            st.erase(it);
            mpp[it[1]].pop_front();
        }

        dq.push_back({s,d,t});
        st.insert({s,d,t});
        mpp[d].push_back(t);

        return true;
    }
    
    vector<int> forwardPacket() {
        if(dq.empty()) return {};

        auto it=dq.front();

        dq.pop_front();
        st.erase(it);
        mpp[it[1]].pop_front();
        
        return it;
    }
    
    int getCount(int d, int start, int end) {
        int ind1=lower_bound(mpp[d].begin(),mpp[d].end(),start)-mpp[d].begin();

        int ind2=upper_bound(mpp[d].begin(),mpp[d].end(),end)-mpp[d].begin();

        return ind2-ind1;
    }
};


/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */