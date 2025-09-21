class MovieRentingSystem {
public:
    unordered_map<int, unordered_map<int, int>> prices; // shop -> movie, price
    unordered_map<int, set<pair<int, int>>> available; // movie ->price, shop
    set<tuple<int, int, int>> rented; // price, shop, movie

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto& e : entries){
            int shop = e[0], movie = e[1], price = e[2];
            prices[shop][movie] = price;
            available[movie].insert({price, shop});
        }
        
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        auto &a = available[movie];
        int count = 0;
        for(auto & [p, s] : a){
            res.push_back(s);
            count++;
            if(count == 5) break;
        }
        return res;
        
    }
    
    void rent(int shop, int movie) {
        int price = prices[shop][movie];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = prices[shop][movie];
        available[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        for( auto & [p, shop, movie] : rented){
            res.push_back({shop, movie});
            count++;
            if(count == 5) break;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */