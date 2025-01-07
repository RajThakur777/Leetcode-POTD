//Brute force:
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();

        vector<string> ans;
        set<string> st;

        for(int i=0; i<n; i++){
            string temp1 = words[i];
            for(int j=i+1; j<n; j++){
                string temp2 = words[j];

                if(temp1.size() > temp2.size()){
                    for(int k=0; k<=temp1.size()-temp2.size(); k++){
                        int m;
                        for(m=0; m<temp2.size(); m++){
                            if(temp1[k+m] != temp2[m]){
                                break;
                            }
                        }

                        if(m == temp2.size() && st.find(temp2) == st.end()){
                            ans.push_back(temp2);
                            st.insert(temp2);
                        }
                    }
                }
                else {
                    for(int k=0; k<=temp2.size()-temp1.size(); k++){
                        int m;
                        for(m=0; m<temp1.size(); m++){
                            if(temp2[k+m] != temp1[m]){
                                break;
                            }
                        }

                        if(m == temp1.size() && st.find(temp1) == st.end()){
                            ans.push_back(temp1);
                            st.insert(temp1);
                        }
                    }
                }
            }
        }
        return ans;
    }
};