class Solution {
public:

    int MOD = 1e9 + 7;

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        int n = orders.size();

        priority_queue<pair<int , int>> buy_order;

        priority_queue<pair<int , int> , vector<pair<int , int>>, greater<pair<int , int>>> sell_order;

        int backlog = 0;

        for(int i=0; i<n; i++){
            int price = orders[i][0];
            int amount = orders[i][1];
            int orderType = orders[i][2];

            if(orderType == 0){
                while(!sell_order.empty() && amount){
                    int p = sell_order.top().first;
                    if(p <= price){
                        int val = sell_order.top().second;
                        sell_order.pop();
                        int mini = min(val , amount);
                        val -= mini;
                        amount -= mini;

                        if(val) sell_order.push({p , val});
                    }
                    else {
                        break;
                    }
                }
                if(amount) {
                    buy_order.push({price , amount});
                }
            }
            else {
                while(!buy_order.empty() && amount){
                    int p = buy_order.top().first;
                    if(p >= price){
                        int val = buy_order.top().second;
                        buy_order.pop();
                        int mini = min(val , amount);
                        val -= mini;
                        amount -= mini;

                        if(val) buy_order.push({p , val});
                    }
                    else {
                        break;
                    }
                }
                if(amount) {
                    sell_order.push({price , amount});
                }   
            }
        }

        while(!buy_order.empty()){
            backlog = (backlog + buy_order.top().second) % MOD;
            buy_order.pop();
        }

        while(!sell_order.empty()){
            backlog = (backlog + sell_order.top().second) % MOD;
            sell_order.pop();
        }
        return backlog % MOD;
    }
};