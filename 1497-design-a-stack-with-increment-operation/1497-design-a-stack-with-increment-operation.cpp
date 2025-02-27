class CustomStack {
public:
    vector<int> st;
    int top;

    CustomStack(int maxSize) {
        st.resize(maxSize);
        top = -1;
    }
    
    void push(int x) {
        if(top < (int)(st.size()) - 1){
            st[++top] = x;
        }
    }
    
    int pop() {
        if(top >= 0){
            return st[top--];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int y = min(k , top+1);

        for(int i=0; i<y; i++){
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */