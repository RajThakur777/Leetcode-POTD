// class ProductOfNumbers {
// public:
//     vector<int> ans;
//     ProductOfNumbers() {
        
//     }
    
//     void add(int num) {
//         ans.push_back(num);
//     }
    
//     int getProduct(int k) {
//         int res = 1;
//         int cnt = 1;
//         for(int i=ans.size()-1; i>=0; i--){
//             if(cnt <= k){
//                 res *= ans[i];
//                 cnt++;
//             }
//             else {
//                 break;
//             }
//         }
//         return res;
//     }
// };

// /**
//  * Your ProductOfNumbers object will be instantiated and called as such:
//  * ProductOfNumbers* obj = new ProductOfNumbers();
//  * obj->add(num);
//  * int param_2 = obj->getProduct(k);
//  */






class ProductOfNumbers {
public:
    vector<int> ans;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        ans.push_back(num);
    }
    
    int getProduct(int k) {
        int res = 1;
        for(int i=ans.size()-k; i<ans.size(); i++){
            res *= ans[i];
        }
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */