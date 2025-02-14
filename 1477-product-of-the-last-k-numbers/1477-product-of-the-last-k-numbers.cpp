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
//         for(int i=ans.size()-k; i<ans.size(); i++){
//             res *= ans[i];
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
    vector<int> nums;
    int n;
    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }
    
    void add(int num) {
        if(num == 0) {
            nums = {};
            n = 0;
        }
        else {
            if(nums.empty()){
                nums.push_back(num);
            }
            else {
                nums.push_back(nums[n-1] * num);
            }
            n++;
        }
    }
    
    int getProduct(int k) {
        if(k > n){
            return 0;
        }
        if(k == n){
            return nums[n-1];
        }

        return (nums[n-1]) / nums[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */