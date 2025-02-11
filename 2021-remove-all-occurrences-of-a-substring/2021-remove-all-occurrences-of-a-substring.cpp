//Using c++ stl:
// class Solution {
// public:
//     string removeOccurrences(string s, string part) {  
//         int pos = s.find(part);

//         while(pos != string::npos){
//             s.erase(pos , part.length());
//             pos = s.find(part);
//         }
//         return s;
//     }
// };




//Using stack:
class Solution {
public:

    bool check(stack<char> &st , string part , int n){
        stack<char> temp = st;

        for(int i=n-1; i>=0; i--){
            if(temp.top() != part[i]){
                return false;
            }
            temp.pop();
        }
        return true;
    }

    string removeOccurrences(string s, string part) { 
        stack<char> st;

        int m = s.size();
        int n = part.size();

        for(int i=0; i<m; i++){
            st.push(s[i]);

            if(st.size() >= n && check(st , part , n) == true){
                for(int j=0; j<n; j++){
                    st.pop();
                }
            }
        }

        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());

        return ans;
    }
};