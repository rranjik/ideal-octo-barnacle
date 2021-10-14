class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<int> lst;
        vector<string> res;
        for(int i = 1; i<=n; i++) lst.push_back(i);
        int lp = 0;
        for(int i = 0; i<target.size(); i++){
            if(lst[lp]==target[i]) {
                res.push_back("Push");
                lp++;
            }
            else {
                while(lst[lp]!=target[i]){
                    res.push_back("Push");
                    res.push_back("Pop");
                    lp++;
                }
                lp++;
                res.push_back("Push");
            }
        }
        return res;
    }
};
