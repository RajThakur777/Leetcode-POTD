// class StockSpanner {
// public:

//     stack<pair<int , int>> st; //stores {price , span}

//     StockSpanner() {
        
//     }
    
//     int next(int price) {
//         int span = 1;
//         while(!st.empty() && price >= st.top().first){
//             span += st.top().second;
//             st.pop();
//         }
//         st.push({price , span});

//         return st.top().second;
//     }
// };

// /**
//  * Your StockSpanner object will be instantiated and called as such:
//  * StockSpanner* obj = new StockSpanner();
//  * int param_1 = obj->next(price);
//  */





class StockSpanner {
public:

    stack<int> st;  //stores idx
    vector<int> ans; 

    StockSpanner() {
        
    }
    
    int next(int price) {
        int i = ans.size();
        ans.push_back(price);

        while(!st.empty() && price >= ans[st.top()]){
            st.pop();
        }
        int span = st.empty() ? i+1 : i-st.top();

        st.push(i);

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */