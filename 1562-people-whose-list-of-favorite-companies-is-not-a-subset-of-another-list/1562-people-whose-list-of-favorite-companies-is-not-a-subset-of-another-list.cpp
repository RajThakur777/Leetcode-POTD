class Solution {
public:

    bool isSubset(vector<string> &s1 , vector<string> &s2){
        int i = 0;
        int j = 0;

        int cnt = 0;
        while(i < s1.size() && j < s2.size()){
            if(s1[i] == s2[j]){
                cnt++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return (cnt >= s1.size());
    }

    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();

        vector<int> res;

        for(int i=0; i<n; i++){
            sort(favoriteCompanies[i].begin() , favoriteCompanies[i].end());
        }

        for(int i=0; i<n; i++){
            int j = 0;

            for(; j<n; j++){
                if(j != i && isSubset(favoriteCompanies[i] , favoriteCompanies[j])){
                    break;
                }
            }

            if(j >= n){
                res.push_back(i);
            }
        }
        return res;
    }
};