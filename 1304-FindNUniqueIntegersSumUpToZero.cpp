class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if(n%2){
            for(int i = 1; i<(n/2)+1; i++){
                res.push_back(i);
                res.push_back(-1*i);
            }
            res.push_back(0);
        }else {
            for(int i = 1; i<(n/2)+1; i++){
                res.push_back(i);
                res.push_back(-1*i);
            }
        }
        return res;
    }
};
