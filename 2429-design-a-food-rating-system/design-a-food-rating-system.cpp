struct cmp {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        if (a.first != b.first) {
            return a.first > b.first; 
        }
        return a.second < b.second; 
    }
};

class FoodRatings {
public:
    unordered_map<string, int> mpp1;
    unordered_map<string, string> mpp2;
    unordered_map<string, set<pair<int, string>, cmp>> mpp3;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            mpp1[foods[i]] = ratings[i];
            mpp2[foods[i]] = cuisines[i];
            mpp3[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = mpp2[food];
        int oldRating = mpp1[food];
        
        mpp3[cuisine].erase({oldRating, food});
        mpp3[cuisine].insert({newRating, food});
        
        mpp1[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return mpp3[cuisine].begin()->second;
    }
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */