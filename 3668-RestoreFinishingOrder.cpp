class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> s(friends.begin(), friends.end());
        vector<int> res;
        for(int i = 0; i<order.size(); i++){
            int f = order[i];
            if(s.find(f)==s.end()) continue;
            res.push_back(f);
        }
        return res;
    }
};
